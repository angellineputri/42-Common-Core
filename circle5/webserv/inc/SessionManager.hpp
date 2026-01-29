#ifndef SESSION_MANAGER_HPP
#define SESSION_MANAGER_HPP

#include <map>
#include <string>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include "http/HttpRequest.hpp"
#include "http/HttpResponse.hpp"
#include "config/ServerConfig.hpp"

struct Session {
    ServerConfig*   server;
    std::string     username;
    std::string     theme;
};

class SessionManager {
    public:
        SessionManager() {}
        ~SessionManager() {}

        std::string generateSessionId();
        std::string createSession(const std::string &username, ServerConfig &server);
        Session*    getSession(const std::string &sessionId);
        void        setCookie(const HttpRequest &req, std::string &sessionId, HttpResponse &resp, ServerConfig &server);
        bool        registerUser(const std::string &username, const std::string &password, const std::string &theme, const std::string &sessionId);
        
        void        setTheme (const std::string &username, const std::string &theme, const std::string &sessionId);
        std::string getTheme(const std::string &username, const std::string &sessionId);
        bool        authenticate(const std::string &username, const std::string &password, const std::string &sessionId);
        bool        userExist(const std::string &username, const std::string &sessionId);
    
    private:
        std::map<std::string, Session> sessions;
};

#endif
