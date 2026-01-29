#include "../inc/SessionManager.hpp"

std::string SessionManager::generateSessionId() {
    static const char chars[] =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string id;
    for (int i = 0; i < 16; ++i) {
        id += chars[rand() % (sizeof(chars) - 1)];
    }
    return id;
}

std::string SessionManager::createSession(const std::string &username, ServerConfig &server) {
    std::string sessionId = generateSessionId();
    sessions[sessionId].username = username;
    sessions[sessionId].theme = "blue";
    sessions[sessionId].server = &server;
    return sessionId;
}

Session* SessionManager::getSession(const std::string &sessionId) {
    std::map<std::string, Session>::iterator it = sessions.find(sessionId);
    if (it == sessions.end()) 
        return NULL;
    return &it->second;
}

void SessionManager::setCookie(const HttpRequest &req, std::string &sessionId, HttpResponse &resp, ServerConfig &server)
{
    std::string cookieHeader = req.header("cookie");

    if (!cookieHeader.empty()) {
        std::ostringstream cookieName;
        cookieName << "session_id_" << server.getListens()[0].getPort();
        std::string cookieHeader = req.header("cookie");
        size_t pos = cookieHeader.find(cookieName.str() + "=");

        if (pos != std::string::npos) {
            std::string key = cookieName.str() + "=";
            sessionId = cookieHeader.substr(pos + key.size(), 16);
        }
    }

    Session* currentSession = getSession(sessionId);
    if (!currentSession) {
        sessionId = createSession("Guest", server);
        currentSession = getSession(sessionId);
    }

    std::ostringstream cookieName;
    cookieName << "session_id_" << server.getListens()[0].getPort();
    resp.addHeader("Set-Cookie", cookieName.str() + "=" + sessionId + "; Path=/; HttpOnly");
}

bool SessionManager::registerUser(const std::string &username, const std::string &password, const std::string &theme, const std::string &sessionId) {
    return(sessions[sessionId].server->registerUser(username, password, theme));
}

bool SessionManager::authenticate(const std::string &username, const std::string &password, const std::string &sessionId) {
    return(sessions[sessionId].server->authenticate(username, password));
}

std::string SessionManager::getTheme(const std::string &username, const std::string &sessionId)
{
    return(sessions[sessionId].server->getTheme(username));
}

bool    SessionManager::userExist(const std::string &username, const std::string &sessionId)
{
    return(sessions[sessionId].server->userExist(username));
}

void SessionManager::setTheme (const std::string &username, const std::string &theme, const std::string &sessionId)
{
    return(sessions[sessionId].server->setTheme(username, theme));
}
