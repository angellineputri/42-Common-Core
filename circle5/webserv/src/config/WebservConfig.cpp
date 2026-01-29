#include "WebservConfig.hpp"

WebservConfig::WebservConfig() 
    : servers() {}

WebservConfig::~WebservConfig() {}

WebservConfig::WebservConfig(const WebservConfig& other) 
    : servers(other.servers) {}

WebservConfig& WebservConfig::operator=(const WebservConfig& other){
    if (this != &other){
        servers = other.servers;
    }
    return *this;
}

const std::vector<ServerConfig>& WebservConfig::getServers() const{
    return servers;
}

void WebservConfig::addServer(const ServerConfig& server){
    servers.push_back(server);
}

void WebservConfig::setServers(const std::vector<ServerConfig>& servers_){
    servers = servers_;
}
