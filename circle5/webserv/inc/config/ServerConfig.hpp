#ifndef SERVERCONFIG_HPP
#define SERVERCONFIG_HPP

#include <string>
#include <vector>
#include <map>
#include "ListenEndpoint.hpp"
#include "RouteConfig.hpp"

struct User {
    std::string username;
    std::string password;
    std::string theme;
};

class ServerConfig {
private:
    std::vector<ListenEndpoint> listens;
    std::string server_name;
    std::string root;
    size_t max_body_size;
    std::map<int, std::string> error_pages;
    std::vector<RouteConfig> routes;
    std::map<std::string, User> users;

public:
    ServerConfig();
    ~ServerConfig();
    ServerConfig(const ServerConfig &other);
    ServerConfig &operator=(const ServerConfig &other);

    const std::vector<ListenEndpoint> &getListens() const;
    const std::string &getServerName() const;
    const std::string &getRoot() const;
    size_t getMaxBodySize() const;
    const std::map<int, std::string> &getErrorPages() const;
    const std::vector<RouteConfig> &getRoutes() const;

    void setListens(const std::vector<ListenEndpoint> &listens_);
    void setServerName(const std::string &name_);
    void setRoot(const std::string &root_);
    void setMaxBodySize(size_t size_);
    void setErrorPages(const std::map<int, std::string> &errors_);
    void setRoutes(const std::vector<RouteConfig> &routes_);

    void addListen(const ListenEndpoint &listen_);
    void addRoute(const RouteConfig &route_);
    void addErrorPage(int code, const std::string &path);

    bool userExist(const std::string &username);
    bool registerUser(const std::string &username, const std::string &password, const std::string &theme);
    bool authenticate(const std::string &username, const std::string &password);
    std::string getTheme(const std::string &username);
    void setTheme(const std::string &username, const std::string &theme);

    const std::map<std::string, User> &getUsers() const;
};

#endif
