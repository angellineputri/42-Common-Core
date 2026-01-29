#include "../../inc/Server.hpp"

void Server::add_listener(std::string ip, int port, std::string server_name)
{
    log("Initializing server " + server_name + " on port " + ft_to_string(port) + "..", YELLOW);

    int fd = create_listening_socket();
    configure_socket(fd);
    bind_and_listen(fd, ip, port);

    listen_fds.push_back(fd);
    listener_to_server[fd] = server_name;
    add_pollfd(fd, POLLIN);

    log("Server " + server_name + " is now listening on port " + ft_to_string(port), GREEN);
    std::cout << std::endl;
}

int Server::create_listening_socket()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
        throw std::runtime_error("Error: failed to create TCP socket");
    log("Socket created successfully on fd " + ft_to_string(fd), GREEN);
    return fd;
}

void Server::configure_socket(int fd)
{
    int yes = 1;
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1)
        throw std::runtime_error("Error: setsockopt");

    if (make_nonblocking(fd)== ERR_RET)
        throw std::runtime_error("Error: fcntl");
}

void Server::bind_and_listen(int fd, std::string ip, int port)
{
    struct sockaddr_in addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    addr.sin_port = htons(port);

    if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1)
        throw std::runtime_error("Error: bind");

    if (listen(fd, SOMAXCONN) == -1)
        throw std::runtime_error("Error: listen");
}
