#ifndef WEBSERVCONFIG_HPP
#define WEBSERVCONFIG_HPP

#include <vector>
#include "ServerConfig.hpp"

class WebservConfig {
private:
    std::vector<ServerConfig> servers;

public:
    WebservConfig();
    ~WebservConfig();
    WebservConfig(const WebservConfig &other);
    WebservConfig &operator=(const WebservConfig &other);

    const std::vector<ServerConfig> &getServers() const;

    void addServer(const ServerConfig &server);
    void setServers(const std::vector<ServerConfig> &servers_);
};

#endif
