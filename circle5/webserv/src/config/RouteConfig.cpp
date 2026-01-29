#include "RouteConfig.hpp"

RouteConfig::RouteConfig() 
    : path(""), methods(), root(""), autoindex(false), index_file(""), 
      upload_enabled(false), upload_store(""), redirect(""), cgis() {}

RouteConfig::~RouteConfig() {}

RouteConfig::RouteConfig(const RouteConfig& other) 
    : path(other.path), methods(other.methods), root(other.root),
      autoindex(other.autoindex), index_file(other.index_file),
      upload_enabled(other.upload_enabled), upload_store(other.upload_store),
      redirect(other.redirect), cgis(other.cgis) {}

RouteConfig& RouteConfig::operator=(const RouteConfig& other){
    if (this != &other){
        path = other.path;
        methods = other.methods;
        root = other.root;
        autoindex = other.autoindex;
        index_file = other.index_file;
        upload_enabled = other.upload_enabled;
        upload_store = other.upload_store;
        redirect = other.redirect;
        cgis = other.cgis;
    }
    return *this;
}

const std::string& RouteConfig::getPath() const{
    return path;
}

const std::vector<std::string>& RouteConfig::getMethods() const{
    return methods;
}

const std::string& RouteConfig::getRoot() const{
    return root;
}

bool RouteConfig::getAutoindex() const{
    return autoindex;
}

const std::string& RouteConfig::getIndexFile() const{
    return index_file;
}

bool RouteConfig::getUploadEnabled() const{
    return upload_enabled;
}

const std::string& RouteConfig::getUploadStore() const{
    return upload_store;
}

const std::string& RouteConfig::getRedirect() const{
    return redirect;
}

const std::vector<CGIConfig>& RouteConfig::getCGIs() const{
    return cgis;
}

 std::vector<CGIConfig>& RouteConfig::getCGIs() {
    return cgis;
}

void RouteConfig::setPath(const std::string &path_){
    path = path_;
}

void RouteConfig::setMethods(const std::vector<std::string> &methods_){
    methods = methods_;
}

void RouteConfig::setRoot(const std::string &root_){
    root = root_;
}

void RouteConfig::setAutoindex(bool autoindex_){
    autoindex = autoindex_;
}

void RouteConfig::setIndexFile(const std::string &index_file_){
    index_file = index_file_;
}

void RouteConfig::setUploadEnabled(bool enabled_){
    upload_enabled = enabled_;
}

void RouteConfig::setUploadStore(const std::string &store_){
    upload_store = store_;
}

void RouteConfig::setRedirect(const std::string &redirect_){
    redirect = redirect_;
}

void RouteConfig::setCGIs(const std::vector<CGIConfig> &cgis_){
    cgis = cgis_;
}

void RouteConfig::addMethod(const std::string &method_) {
    methods.push_back(method_);
}

void RouteConfig::addCGI(const CGIConfig &cgi_) {
    cgis.push_back(cgi_);
}