#include "../../inc/Server.hpp"

void Server::handleAutoIndexHtml(HttpResponse &resp, const std::string &folderPath, const std::string &requestPath, ClientState &client)
{
    DIR *dir = opendir(folderPath.c_str());
    if (!dir) {
        resp.setStatus(404, "Not Found");
        resp.setBody(load_error_page(404, "", client));
        return;
    }

    struct dirent *entry;
    struct stat info;
    std::stringstream html;

    html << "<!DOCTYPE html><html><head><meta charset=\"UTF-8\">";
    html << "<title>Index of " << requestPath << "</title>";
    html << "<style>"
            "body { background:#F6F6F2; font-family:Arial,sans-serif; margin:0; padding:20px; }"
            ".container { max-width:1000px; margin:auto; text-align:center; }"
            "h1 { color:#338087; margin-bottom:20px; }"
            ".divider { border:none; border-top:3px solid #338087; margin:20px auto; width:50%; }"
            ".card { display:inline-block; background:#BADFE7; border-radius:12px; padding:15px 20px; margin:10px; text-align:left; width:200px; box-shadow:0 4px 6px rgba(0,0,0,0.1); }"
            ".card:hover { background:#C2EDCE; }"
            ".card a { text-decoration:none; color:#338087; font-weight:bold; }"
            ".folder h3, .file h3 { margin:0 0 8px 0; font-size:1.1rem; }"
            "</style>";
    html << "</head><body>";
    html << "<div class=\"container\">";
    html << "<h1>Index of " << requestPath << "</h1>";
    html << "<hr class=\"divider\">";

    if (requestPath != "/") {
        std::string parent = requestPath.substr(0, requestPath.find_last_of('/', requestPath.length() - 2) + 1);
        html << "<div class=\"card folder\"><h3>⬆ Parent Directory</h3>";
        html << "<a href=\"" << parent << "\">Go Up</a></div>";
    }

    while ((entry = readdir(dir)) != NULL) {
        std::string name = entry->d_name;
        if (name == "." || name == "..") continue;

        std::string fullpath = folderPath + "/" + name;
        if (stat(fullpath.c_str(), &info) == 0) {
            if (S_ISDIR(info.st_mode)) {
                html << "<div class=\"card folder\">";
                html << "<h3>📁 " << name << "/</h3>";
                html << "<a href=\"" << requestPath;
                if (!requestPath.empty() && requestPath[requestPath.size() - 1] != '/') html << "/";
                html << name << "/\">Open Folder</a></div>";
            } else {
                html << "<div class=\"card file\">";
                html << "<h3>📄 " << name << "</h3>";
                html << "<a href=\"" << requestPath;
                if (!requestPath.empty() && requestPath[requestPath.size() - 1] != '/') html << "/";
                html << name << "\">Download</a></div>";
            }
        }
    }

    closedir(dir);
    html << "</div></body></html>";

    resp.setStatus(200, "OK");
    resp.addHeader("Content-Type", "text/html");
    resp.setBody(html.str());
}

void Server::handleFileDownload(HttpResponse &resp, std::string &target, RouteConfig* route, std::string main_path, ClientState &client)
{
    if (!route) {
        resp.setStatus(500, "Internal Server Error");
        resp.addHeader("Content-Type", "text/html");
        resp.setBody(load_error_page(500, "Route not provided", client));
        return;
    }
    
    std::string routePath = route->getPath(); 
    std::string folder = route->getRoot();
    
    std::string filename;
    if (target.size() > routePath.size())
        filename = target.substr(routePath.size() + 1); 
    else {
        resp.setStatus(400, "Bad Request");
        resp.addHeader("Content-Type", "text/html");
        resp.setBody(load_error_page(400, "No file specified", client));
        return;
    }

    filename = urlDecode(filename);

    std::string filepath = main_path + folder + "/" + filename;

    struct stat info;
    if (stat(filepath.c_str(), &info) != 0 || !S_ISREG(info.st_mode)) {
        resp.setStatus(404, "Not Found");
        resp.addHeader("Content-Type", "text/html");
        resp.setBody(load_error_page(404, "", client));
        return;
    }

    std::ifstream file(filepath.c_str(), std::ios::binary);
    if (!file) {
        resp.setStatus(500, "Internal Server Error");
        resp.addHeader("Content-Type", "text/html");
        resp.setBody(load_error_page(500, "", client));
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    resp.setStatus(200, "OK");
    resp.addHeader("Content-Type", "application/octet-stream");
    resp.addHeader("Content-Disposition", "attachment; filename=\"" + filename + "\"");
    resp.setBody(buffer.str());
}

void    Server::handleStaticFile(const HttpRequest &req, HttpResponse &resp, ClientState &client, RouteConfig* route, std::string main_path)
{
    std::string suffix;

    if (!req.target().empty() && req.target()[req.target().size() - 1] == '/') {
        suffix = route->getIndexFile();
    }
    
    std::string path = main_path + route->getRoot() + req.target() + suffix;
    path = urlDecode(path);

    std::ifstream file(path.c_str(), std::ios::binary);
    if (!file.is_open()) {
        std::string target = req.target();
        if (route->getAutoindex()) {
            handleAutoIndexHtml(resp, main_path + route->getRoot() + req.target() , req.target(), client);
            return ;
        }
        resp.setStatus(404, "Not Found");
        resp.addHeader("Content-Type", "text/html");
        resp.setBody(load_error_page(404, "", client));
    } else {
        std::stringstream buffer;
        buffer << file.rdbuf();
        file.close();

        std::string html = changeResp(buffer.str(), client.username, client.sessionId, client.server_name);

        std::string contentType = "text/plain";
        if (path.find(".html") != std::string::npos)
            contentType = "text/html";
        else if (path.find(".css") != std::string::npos)
            contentType = "text/css";
        else if (path.find(".js") != std::string::npos)
            contentType = "application/javascript";

        resp.setStatus(200, "OK");
        resp.addHeader("Content-Type", contentType);
        resp.setBody(html);
    }
}

void Server::handleAuthLoginCheck(HttpResponse &resp, ClientState &client)
{
    Session* session = sessionManager.getSession(client.sessionId);

    resp.addHeader("Content-Type", "text/plain");

    if (session && !session->username.empty()) {
        resp.setStatus(200, "OK");
        resp.setBody("session id: " + client.sessionId + "\nuser session: " + session->username);
    } else {
        resp.setStatus(401, "Unauthorized");
        resp.setBody("no active session found.");
    }
}
