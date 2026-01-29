#include "ListenEndpoint.hpp"

ListenEndpoint::ListenEndpoint() : ip(""), port(0) {}

ListenEndpoint::ListenEndpoint(const std::string &ip_, int port_) 
    : ip(ip_), port(port_) {}

ListenEndpoint::~ListenEndpoint() {}

ListenEndpoint::ListenEndpoint(const ListenEndpoint& other)
    : ip(other.ip), port(other.port) {}

ListenEndpoint& ListenEndpoint::operator=(const ListenEndpoint& other){
    if (this != &other){
        ip = other.ip;
        port = other.port;
    }
    return *this;
}

const std::string& ListenEndpoint::getIP() const{
    return ip;
}

int ListenEndpoint::getPort() const{
    return port;
}

void ListenEndpoint::setIP(const std::string &ip_){
    ip = ip_;
}

void ListenEndpoint::setPort(int port_){
    port = port_;
}
