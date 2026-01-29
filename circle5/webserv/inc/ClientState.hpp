#ifndef CLIENTSTATE_HPP
#define CLIENTSTATE_HPP

#include <string>
#include "http/RequestParser.hpp"
#include "http/HttpRequest.hpp"
#include "http/HttpResponse.hpp"
#include "http/HttpHeaders.hpp"
#include "http/ResponseWriter.hpp"
#include "config/ServerConfig.hpp"
#include "SessionManager.hpp"

struct ClientState
{
    ServerConfig        *server;
    HttpRequestParser   parser;
    HttpRequest         request;
    
    Session             *session;
    std::string         sessionId;
    std::string         username;

    size_t              maxBodySize;
    bool                keep_alive;

    int                 fd;
    int                 port;
    std::string         server_name;
    std::string         ip;
    
    bool                want_write;
    std::string         read_buf;
    std::string         write_buf;
    std::string         parse_err;

    pid_t               cgi_pid;
    int                 cgi_fd;
    time_t              cgi_start_time;
    std::string         cgi_buffer;
    bool                 cgi_active;

    ClientState();
};

#endif
