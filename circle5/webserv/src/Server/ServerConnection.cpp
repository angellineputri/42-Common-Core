#include "../../inc/Server.hpp"

void Server::handle_new_connection(int listen_fd)
{
    while (true) {
        struct sockaddr_in cli;
        int cfd = accept_new_client(listen_fd, cli);
        if (cfd == -1)
            break;
        
        if (make_nonblocking(cfd)== ERR_RET) {
            log("Failed to set non-blocking flag for client fd " + ft_to_string(cfd), RED);
            close(cfd);
            continue ;
        }

        setup_client_state(cfd, listen_fd, cli);
    }
}

int Server::accept_new_client(int listen_fd, struct sockaddr_in &cli)
{
    socklen_t len = sizeof(cli);
    
    int cfd = accept(listen_fd, (struct sockaddr*)&cli, &len);
    if (cfd == -1)
        return -1;

    return cfd;
}

void Server::setup_client_state(int cfd, int listen_fd, struct sockaddr_in &cli)
{
    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(cli.sin_addr), client_ip, INET_ADDRSTRLEN);
    
    ClientState client;
    client.fd = cfd;
    client.want_write = false;
    client.ip = client_ip;
    client.port = ntohs(cli.sin_port);
    client.server_name = listener_to_server[listen_fd];

    assign_server_config(client);
    clients[cfd] = client;
    add_pollfd(cfd, POLLIN);
    
    log("Client " + client.ip + ":" + ft_to_string(client.port) + " connected on socket " + ft_to_string(cfd), MAGENTA);
}

void Server::assign_server_config(ClientState &client)
{
    const std::vector<ServerConfig>& servers = _cfg.getServers();
    for (std::vector<ServerConfig>::const_iterator it = servers.begin(); it != servers.end(); ++it) {
        if (it->getServerName() == client.server_name) {
            client.maxBodySize = it->getMaxBodySize();
            client.server = const_cast<ServerConfig*>(&(*it));;
            break;
        }
    }
}
