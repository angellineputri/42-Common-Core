#include "../../inc/Server.hpp"

ssize_t Server::write_some(int fd, const char* data, size_t len)
{
    if (clients.find(fd) == clients.end())
        return -1;

    clients[fd].write_buf.append(data, len);
    return (static_cast<ssize_t>(len));
}

void Server::update_poll_event(int fd, short new_events)
{
    for (size_t i = 0; i < pfds.size(); ++i) {
        if (pfds[i].fd == fd) {
            pfds[i].events = new_events;
            break;
        }
    }
}

void Server::disable_write_event(int fd, ClientState &state)
{
    update_poll_event(fd, POLLIN);
    state.want_write = false;
}

void Server::handle_client_write(int fd)
{
    std::map<int, ClientState>::iterator it = clients.find(fd);
    if (it == clients.end())
        return;

    ClientState &state = it->second;
    if (state.write_buf.empty()) {
        disable_write_event(fd, state);
        return ;
    }

    ssize_t n = send(fd, state.write_buf.data(), state.write_buf.size(), 0);
    if (n > 0) {
        handle_write_success(fd, state, n);
    }
    else {
        handle_write_failure(fd);
    }
}

void Server::handle_write_success(int fd, ClientState &state, ssize_t n)
{
    log("Sent " + ft_to_string(n) + " bytes to client on fd " + ft_to_string(fd), GREEN);
    state.write_buf.erase(0, static_cast<size_t>(n));
    if (state.write_buf.empty())
    {
        if (state.keep_alive) {
            update_poll_event(fd, POLLIN);
        }
        else {
            disconnect_client(fd, "write complete");
        }
    }
}

void Server::handle_write_failure(int fd)
{
    if (errno != EWOULDBLOCK && errno != EAGAIN)
    {
        log("Send error to client on fd " + ft_to_string(fd) + ": " + std::string(strerror(errno)), RED);
    }
    disconnect_client(fd, "send error");
}
