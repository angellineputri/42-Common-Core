#include "../../inc/Server.hpp"

volatile sig_atomic_t Server::s_signal_received = 0;

Server::Server()
: running(true)
{
    signal(SIGPIPE, SIG_IGN);
    signal(SIGINT, Server::handle_signal);
}

Server::~Server()
{
    for (size_t i = 0; i < listen_fds.size(); ++i)
        close(listen_fds[i]);
    for (std::map<int, ClientState>::iterator it = clients.begin(); it != clients.end(); ++it)
        close(it->first);
    log("Server cleanup completed successfully", GREEN);
}

void    Server::init(const WebservConfig& cfg)
{
    _cfg = cfg;
    const std::vector<ServerConfig>& servers = cfg.getServers();
    for (size_t i = 0; i < servers.size(); ++i)
    {
        const std::vector<ListenEndpoint>& listens = servers[i].getListens();
        for (size_t j = 0; j < listens.size(); ++j)
        {
            int port = listens[j].getPort();
            std::string ip = listens[j].getIP();
            add_listener(ip, port, servers[i].getServerName());
        }
    }
}

void Server::run()
{
    log("Servers are running...", GREEN);
    std::cout << std::endl;

    const int poll_timeout = 1000;

    while (running)
    {
        if (s_signal_received)
        {
            std::cout << RED << "Shutting down server.." << RESET << std::endl;
            running = 0;
            break;
        }

        int ready = poll(&pfds[0], pfds.size(), poll_timeout);
        if (ready <= 0) 
            continue;

        std::time_t now = std::time(0);

        for (int i = pfds.size() - 1; i >= 0; --i)
        {
            struct pollfd &pe = pfds[i];
            if (pe.revents == 0) 
                continue;
            if (is_listener(pe.fd))
                handle_listener_event(pe);
            else if (is_cgi_fd(pe.fd))
                handle_cgi_event(pe);
            else
                handle_client_event(pe);
        }

        for (int j = pending_cgis.size() - 1; j >= 0; --j)
        {
            PendingCGI &cgi = pending_cgis[j];
            if (now - cgi.start_time > CGI_TIMEOUT)
            {
                ClientState &client = clients[cgi.client_fd];
                kill(cgi.pid, SIGKILL);
                waitpid(cgi.pid, NULL, 0);

                HttpResponse resp;
                resp.setStatus(500, "Internal Server Error");
                resp.setBody(load_error_page(500, "CGI script timeout", client));
                send_response(cgi.client_fd, resp);

                if (cgi.out_fd >= 0) 
                    close(cgi.out_fd);
                if (cgi.in_fd >= 0) 
                    close(cgi.in_fd);

                for (int k = pfds.size() - 1; k >= 0; --k)
                    if (pfds[k].fd == cgi.out_fd || pfds[k].fd == cgi.in_fd)
                        pfds.erase(pfds.begin() + k);

                pending_cgis.erase(pending_cgis.begin() + j);
            }
        }
    }
}

void Server::handle_cgi_event(struct pollfd &pe)
{
    for (int i = pending_cgis.size() - 1; i >= 0; --i)
    {
        PendingCGI &cgi = pending_cgis[i];

        if (pe.fd == cgi.in_fd && cgi.in_fd >= 0)
        {
            if (pe.revents & POLLOUT)
            {
                if (cgi.post_offset < cgi.post_data.size())
                {
                    int n = write(pe.fd, cgi.post_data.c_str() + cgi.post_offset,
                                  cgi.post_data.size() - cgi.post_offset);
                    if (n > 0)
                        cgi.post_offset += n;
                }

                if (cgi.post_offset >= cgi.post_data.size())
                {
                    close(cgi.in_fd);
                    cgi.in_fd = -1;

                    for (int k = pfds.size() - 1; k >= 0; --k)
                        if (pfds[k].fd == pe.fd)
                            pfds.erase(pfds.begin() + k);
                }
            }
            else if (pe.revents & (POLLERR | POLLHUP))
            {
                close(cgi.in_fd);
                cgi.in_fd = -1;
            }
            continue;
        }

        if (pe.fd != cgi.out_fd)
            continue;

        if (pe.revents & POLLIN)
        {
            char buf[1024];
            int n = read(pe.fd, buf, sizeof(buf));
            if (n > 0)
                cgi.buffer.append(buf, n);
        }

        if (pe.revents & (POLLHUP | POLLERR))
        {
            int status;
            pid_t ret = waitpid(cgi.pid, &status, WNOHANG);
            if (ret > 0)
            {
                HttpResponse resp;

                if (WIFEXITED(status)) {
                    int exit_code = WEXITSTATUS(status);
                    if (exit_code == 0) {
                        std::string body = parse_cgi_output(cgi.buffer);
                        resp.setStatus(200, "OK");

                        size_t first_char = body.find_first_not_of(" \t\r\n");
                        if (first_char != std::string::npos && body[first_char] == '<')
                            resp.addHeader("Content-Type", "text/html");
                        else
                            resp.addHeader("Content-Type", "application/json");

                        resp.setBody(body);
                    } else {
                        resp.setStatus(500, "Internal Server Error");
                        resp.setBody(load_error_page(500, "CGI failed", clients[cgi.client_fd]));
                    }
                } else if (WIFSIGNALED(status)) {
                    resp.setStatus(502, "Bad Gateway");
                    resp.setBody(load_error_page(502, "CGI terminated by signal", clients[cgi.client_fd]));
                } else {
                    resp.setStatus(500, "Internal Server Error");
                    resp.setBody(load_error_page(500, "Unknown CGI error", clients[cgi.client_fd]));
                }

                send_response(cgi.client_fd, resp);

                close(cgi.out_fd);
                for (int k = pfds.size() - 1; k >= 0; --k)
                    if (pfds[k].fd == cgi.out_fd)
                        pfds.erase(pfds.begin() + k);

                pending_cgis.erase(pending_cgis.begin() + i);
            }
        }
        break;
    }
}

bool Server::is_cgi_fd(int fd)
{
    for (size_t i = 0; i < pending_cgis.size(); ++i)
        if (pending_cgis[i].in_fd == fd || pending_cgis[i].out_fd == fd)
            return true;
    return false;
}

void Server::handle_listener_event(struct pollfd &pe)
{
    if (pe.revents & POLLIN)
        handle_new_connection(pe.fd);
}

void Server::handle_client_event(struct pollfd &pe)
{
    if (pe.revents & POLLIN)
        handle_client_read(pe.fd);

    if (pe.revents & POLLOUT)
        handle_client_write(pe.fd);

    if (pe.revents & (POLLERR | POLLHUP | POLLNVAL))
        handle_client_disconnect(pe);
}

void Server::handle_client_disconnect(struct pollfd &pe)
{
    std::vector<std::string> reasons;
    if (pe.revents & POLLHUP) 
        reasons.push_back("hang up");
    if (pe.revents & POLLERR) 
        reasons.push_back("error");
    if (pe.revents & POLLNVAL) 
        reasons.push_back("invalid request");

    std::string reason;
    for (size_t i = 0; i < reasons.size(); ++i)
    {
        reason += reasons[i];
        if (i != reasons.size() - 1)
            reason += ", ";
    }

    log("Client fd " + ft_to_string(pe.fd) + " disconnected due to " + reason, RED);
    remove_pollfd(pe.fd);
    clients.erase(pe.fd);
    close(pe.fd);
}

