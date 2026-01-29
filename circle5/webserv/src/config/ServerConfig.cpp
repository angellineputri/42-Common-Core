#include "ServerConfig.hpp"

ServerConfig::ServerConfig() 
    : listens(), server_name(""), root(""), max_body_size(0), 
      error_pages(), routes() {}

ServerConfig::~ServerConfig() {}

ServerConfig::ServerConfig(const ServerConfig& other) 
    : listens(other.listens), server_name(other.server_name),
      root(other.root), max_body_size(other.max_body_size),
      error_pages(other.error_pages), routes(other.routes) {}

ServerConfig& ServerConfig::operator=(const ServerConfig& other){
    if (this != &other){
        listens = other.listens;
        server_name = other.server_name;
        root = other.root;
        max_body_size = other.max_body_size;
        error_pages = other.error_pages;
        routes = other.routes;
    }
    return *this;
}

const std::vector<ListenEndpoint>& ServerConfig::getListens() const{
    return listens;
}

const std::string& ServerConfig::getServerName() const{
    return server_name;
}

const std::string& ServerConfig::getRoot() const{
    return root;
}

size_t ServerConfig::getMaxBodySize() const{
    return max_body_size;
}

const std::map<int, std::string>& ServerConfig::getErrorPages() const{
    return error_pages;
}

const std::vector<RouteConfig>& ServerConfig::getRoutes() const{
    return routes;
}

void ServerConfig::setListens(const std::vector<ListenEndpoint> &listens_){
    listens = listens_;
}

void ServerConfig::setServerName(const std::string &name_){
    server_name = name_;
}

void ServerConfig::setRoot(const std::string &root_){
    root = root_;
}

void ServerConfig::setMaxBodySize(size_t size_){
    max_body_size = size_;
}

void ServerConfig::setErrorPages(const std::map<int, std::string> &errors_){
    error_pages = errors_;
}

void ServerConfig::setRoutes(const std::vector<RouteConfig> &routes_){
    routes = routes_;
}

void ServerConfig::addListen(const ListenEndpoint &listen_){
    listens.push_back(listen_);
}

void ServerConfig::addRoute(const RouteConfig &route_){
    routes.push_back(route_);
}

void ServerConfig::addErrorPage(int code, const std::string &path){
    error_pages[code] = path;
}


bool ServerConfig::registerUser(const std::string &username, const std::string &password, const std::string &theme) {
    if (users.find(username) != users.end())
        return false;
    users[username].username = username;
    users[username].password = password;
    users[username].theme = theme;
    return true;
}

bool ServerConfig::authenticate(const std::string &username, const std::string &password) {
    std::map<std::string, User>::iterator it = users.find(username);
    if (it == users.end()) return false;
    return (it->second.password == password);
}

std::string ServerConfig::getTheme(const std::string &username)
{
    std::map<std::string, User>::iterator it = users.find(username);
    if (it == users.end()) return "";
    return (it->second.theme);
}

bool    ServerConfig::userExist(const std::string &username)
{
    std::map<std::string, User>::iterator it = users.find(username);
    if (it == users.end())
        return false;
    return (true);
}

void ServerConfig::setTheme (const std::string &username, const std::string &theme)
{
    std::map<std::string, User>::iterator it = users.find(username);
    if (it == users.end())
        return ;
    it->second.theme = theme;
}

const std::map<std::string, User>& ServerConfig::getUsers() const
{ 
    return users;
};
