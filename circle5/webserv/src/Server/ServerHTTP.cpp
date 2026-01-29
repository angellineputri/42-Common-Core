#include "../../inc/Server.hpp"

void Server::send_response(int fd, const HttpResponse& resp)
{
    std::ostringstream oss;
    oss << "HTTP/1.1 " << resp.status() << " " << resp.reason() << "\r\n";

    if (!resp.hasHeader("Content-Length"))
        oss << "Content-Length: " << resp.body().size() << "\r\n";
    oss << "Connection: keep-alive\r\n";

    std::map<std::string, std::string>::const_iterator it;
    for (it = resp.headers().map().begin(); it != resp.headers().map().end(); ++it) {
        oss << it->first << ": " << it->second << "\r\n";
    }

    oss << "\r\n";
    oss << resp.body();

    write_some(fd, oss.str().c_str(), oss.str().size());

    for (size_t i = 0; i < pfds.size(); ++i) {
        if (pfds[i].fd == fd) {
            pfds[i].events = POLLIN | POLLOUT;
            break;
        }
    }
    clients[fd].want_write = true;
}

std::string Server::changeResp(std::string buffer, const std::string &username, const std::string &sessionId, const std::string &server_name)
{
    size_t pos = buffer.find("{{username}}");
    if (pos != std::string::npos)
        buffer.replace(pos, 12, username);
    
    Session* session = sessionManager.getSession(sessionId);
    if (sessionManager.getTheme(username, sessionId) != "")
        session->theme = sessionManager.getTheme(username, sessionId);

    pos = buffer.find("{{THEME_CLASS}}");
    if (pos != std::string::npos)
        buffer.replace(pos, 15, "theme-" + session->theme);

    pos = buffer.find("{{SERVERNAME}}");
    if (pos != std::string::npos)
        buffer.replace(pos, 14, server_name);

    return (buffer);
}

std::string Server::load_error_page(int status_code, const std::string& custom_msg, ClientState &client)
{
    std::string filename = find_error_page_path(status_code, client);
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        return "<h1>" + ft_to_string(status_code) + " Error</h1>";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    size_t pos = content.find("{{CUSTOM_MSG}}");
    if (pos != std::string::npos) {
        content.replace(pos, 14, custom_msg);
    }

    return content;
}

std::string Server::find_error_page_path(int status_code, ClientState &client)
{
    const std::vector<ServerConfig>& servers = _cfg.getServers();
    if (!servers.empty()) {
        const ServerConfig& server_cfg = *client.server;
        const std::map<int, std::string>& error_pages = server_cfg.getErrorPages();

        std::map<int, std::string>::const_iterator it = error_pages.find(status_code);
        if (it != error_pages.end() && !it->second.empty()) {
            std::ifstream file(it->second.c_str());
            if (!file.is_open()) {
                return "www/errors/" + ft_to_string(status_code) + ".html";
            }
            return it->second;
        }
    }
    return "www/errors/" + ft_to_string(status_code) + ".html";
}

std::string Server::load_respond_page(std::string filename, std::string type, ClientState &client)
{
    std::string path;
    if (type == "create_file")
        path = "www/mandatory/post/file_created.html";
    else if (type == "upload_file")
        path = "www/mandatory/upload/file_uploaded.html";

    std::ifstream file(path.c_str());
    if (!file.is_open()) {
        return "<h1>file " + filename + " created successfully</h1>";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    size_t pos = content.find("{{FILENAME}}");
    if (pos != std::string::npos) {
        content.replace(pos, 12, filename);
    }

    content = changeResp(content, client.username, client.sessionId, client.server_name);
    return content;
}
