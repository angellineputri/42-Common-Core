#ifndef LISTENENDPOINT_HPP
#define LISTENENDPOINT_HPP

#include <iostream>

class ListenEndpoint {
private:
    std::string ip;
    int port;

public:
    ListenEndpoint();
    ListenEndpoint(const std::string &ip_, int port_);
    ~ListenEndpoint();
    ListenEndpoint(const ListenEndpoint &other);
    ListenEndpoint &operator=(const ListenEndpoint &other);

    const std::string &getIP() const;
    int getPort() const;

    void setIP(const std::string &ip_);
    void setPort(int port_);
};

#endif
