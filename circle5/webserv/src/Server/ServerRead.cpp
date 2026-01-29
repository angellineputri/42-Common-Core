#include "../../inc/Server.hpp"

ssize_t Server::read_some(int fd, char* data, size_t len)
{
    if (clients.find(fd) == clients.end())
        return (-1);

    ClientState &client = clients[fd];
    if (client.read_buf.empty())
        return (0);

    size_t n = std::min(len, client.read_buf.size());
    std::memcpy(data, client.read_buf.data(), n);
    client.read_buf.erase(0, n);

    return (static_cast<ssize_t>(n));
}

void Server::handle_client_read(int fd)
{
    char buf[4096];
    ssize_t n = recv(fd, buf, sizeof(buf), 0);

    if (n > 0) {
        handle_received_data(fd ,buf, static_cast<size_t>(n));
    }
    else if (n == 0) {
        disconnect_client(fd, "EOF");
    }
    else {
        handle_recv_error(fd);
    }
}

void Server::handle_received_data(int fd, char* buf, size_t len)
{
    ClientState &client = clients[fd];
    HttpRequestParser::Result res = client.parser.feed(buf, len, client.request, client.parse_err, client.maxBodySize);

    if (res == HttpRequestParser::INCOMPLETE) {
        log("Parser: INCOMPLETE for fd " + ft_to_string(fd), YELLOW);
    } else if (res == HttpRequestParser::ERROR) {
        handle_parse_error(fd, client);
    }
    else if (res == HttpRequestParser::COMPLETE) {
        handle_complete_request(fd, client);
    }
}

void Server::handle_parse_error(int fd, ClientState &client)
{
    log("Parser ERROR on fd " + ft_to_string(fd) + ": " + client.parse_err, RED);

    int status_code = 400;
    std::string status_text = "Bad Request";
    if (client.parse_err.find("Body exceeds") != std::string::npos) {
        status_code = 413;
        status_text = client.parse_err;
    }

    HttpResponse resp(status_code, status_text);
    resp.setStatus(status_code, status_text);
    resp.addHeader("Content-Type", "text/html");
    resp.setBody(load_error_page(status_code, client.parse_err, client));

    std::string out = ResponseWriter::serialize(resp, false);

    client.write_buf.append(out);
    client.want_write = true;
    for (size_t i = 0; i < pfds.size(); ++i) {
        if (pfds[i].fd == fd) {
            pfds[i].events = POLLIN | POLLOUT;
            break;
        }
    }
}

void Server::handle_complete_request(int fd, ClientState &client)
{
    log("Parser COMPLETE on fd " + ft_to_string(fd), GREEN);
    client.keep_alive = request_keep_alive(client.request);

    if (is_cgi_request(client.request, client)) {
        handle_cgi_request(fd, client.request, client);
    } else {
        handle_http_request(fd, client.request, client);
    }

    client.parser.reset();
    client.request = HttpRequest();
    client.parse_err.clear();
}

void Server::disconnect_client(int fd, std::string reason)
{
    log("Client fd " + ft_to_string(fd) + " disconnected (" + reason + ")", RED);
    remove_pollfd(fd);
    clients.erase(fd);
    close(fd);
}

void Server::handle_recv_error(int fd)
{
    if (errno != EWOULDBLOCK && errno != EAGAIN) {
        log("Error client on fd " + ft_to_string(fd) + ": " + std::string(strerror(errno)), RED);
    }
    disconnect_client(fd, "recv error");
}

