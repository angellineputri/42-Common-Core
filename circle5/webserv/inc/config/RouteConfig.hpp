#ifndef ROUTECONFIG_HPP
#define ROUTECONFIG_HPP

#include <iostream>
#include <vector>
#include "CGIConfig.hpp"

class RouteConfig {
private:
    std::string path;
    std::vector<std::string> methods;
    std::string root;
    bool autoindex;
    std::string index_file;
    bool upload_enabled;
    std::string upload_store;
    std::string redirect;
    std::vector<CGIConfig> cgis;

public:
    RouteConfig();
    ~RouteConfig();
    RouteConfig(const RouteConfig &other);
    RouteConfig &operator=(const RouteConfig &other);

    const std::string &getPath() const;
    const std::vector<std::string> &getMethods() const;
    const std::string &getRoot() const;
    bool getAutoindex() const;
    const std::string &getIndexFile() const;
    bool getUploadEnabled() const;
    const std::string &getUploadStore() const;
    const std::string &getRedirect() const;
    const std::vector<CGIConfig> &getCGIs() const;
    std::vector<CGIConfig> &getCGIs();

    void setPath(const std::string &path_);
    void setMethods(const std::vector<std::string> &methods_);
    void setRoot(const std::string &root_);
    void setAutoindex(bool autoindex_);
    void setIndexFile(const std::string &index_file_);
    void setUploadEnabled(bool enabled_);
    void setUploadStore(const std::string &store_);
    void setRedirect(const std::string &redirect_);
    void setCGIs(const std::vector<CGIConfig> &cgis_);

    void addMethod(const std::string &method_);
    void addCGI(const CGIConfig &cgi_);
};

#endif
