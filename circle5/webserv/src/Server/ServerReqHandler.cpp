#include "../../inc/Server.hpp"

void Server::handle_http_request(int fd, const HttpRequest &req, ClientState &client)
{
    RouteConfig* route = matchRoute(client.server, req.target());
    if (!validate_route(fd, req, route, client))
        return;

    if (handle_redirect(fd, route))
        return ;

    std::string path = client.server->getRoot();

    HttpResponse resp;
    setup_session(req, resp, client);

    if (req.method() == "GET") {
        handleGET(fd, req, resp, client, route);
    } else if (req.method() == "POST") {
        handlePOST(fd, req, resp, client, route);
    } else if (req.method() == "DELETE") {
        handleDELETE(fd, req, resp, route, client.server->getRoot(), client);
    } else {
        resp.setStatus(405, "Method Not Allowed");
        resp.setBody(load_error_page(405, "", client));
        send_response(fd, resp);
    }
}

bool Server::validate_route(int fd, const HttpRequest &req, RouteConfig *route, ClientState &client)
{
    if (!route) {
        HttpResponse resp;
        resp.setStatus(404, "Not Found");
        resp.setBody(load_error_page(404, "", client));
        send_response(fd, resp);
        return false;
    }

    if (!route->getMethods().empty() && 
        std::find(route->getMethods().begin(), route->getMethods().end(), req.method()) == route->getMethods().end())
    {
        HttpResponse resp;
        resp.setStatus(405, "Method Not Allowed");
        resp.setBody(load_error_page(405, "", client));
        send_response(fd, resp);
        return false;
    }

    return true;
}

bool Server::handle_redirect(int fd, RouteConfig *route)
{
    if (route->getRedirect().empty())
        return false;

    HttpResponse resp;
    resp.setStatus(301, "Moved Permanently");
    resp.addHeader("Location", route->getRedirect());
    resp.setBody("");                           
    send_response(fd, resp);
    return true;
}

void Server::setup_session(const HttpRequest &req, HttpResponse &resp, ClientState &client)
{
    std::string sessionId;
    sessionManager.setCookie(req, sessionId, resp, *(client.server));
    client.session = sessionManager.getSession(sessionId);
    client.sessionId = sessionId;
    client.username = client.session->username;
}

void Server::handleGET(int fd, const HttpRequest &req, HttpResponse &resp, ClientState &client, RouteConfig* route )
{
    log("GET request", MAGENTA);
    std::string main_path = client.server->getRoot();
    std::string target = req.target();
    

    if (req.target() == "/bonus/login.html") {
        handleAuthLoginCheck(resp, client);
    } else if (route->getIndexFile() != "") {
        handleStaticFile(req, resp, client, route, main_path);
    } else {
        handleFileDownload(resp, target, route, main_path, client);
    }
    send_response(fd, resp);
}

void Server::handlePOST(int fd, const HttpRequest &req, HttpResponse &resp, ClientState &client, RouteConfig* route)
{
    log("POST request", MAGENTA);
    if (req.target() == "/bonus/login.html") {
        handleAuthLogin(req, resp, client);
    } else if (req.target() == "/bonus/register.html"){
        handleAuthRegister(req, resp, client);
    } else if (req.target() == "/bonus/theme.html") {
        handleThemeChange(resp, req, client);
    } else if (req.header("content-type").find("multipart/form-data") != std::string::npos)
        handleFileUpload(req, resp, route, client);
    else {
        handleTextFilePost(req, resp, route, client);
    }
    send_response(fd, resp);
}

void Server::handleDELETE(int fd, const HttpRequest &req, HttpResponse &resp, const RouteConfig* route, const std::string &serverRoot, ClientState &client)
{
    log("DELETE request", MAGENTA);
    std::string filename = extract_delete_filename(req, route, resp, client);
    if (filename.empty()) {
        send_response(fd, resp);
        return;
    }

    std::string filepath = serverRoot + route->getRoot() + urlDecode(filename);
    if (std::remove(filepath.c_str()) == 0) {
        resp.setStatus(200, "OK");
        resp.setBody("File deleted successfully.");
    } else {
        resp.setStatus(404, "Not Found");
        resp.setBody(load_error_page(404, "File does not exist or cannot be deleted", client));
    }

    send_response(fd, resp);
}

std::string Server::extract_delete_filename(const HttpRequest &req, const RouteConfig *route, HttpResponse &resp, ClientState &client)
{
    std::string target = req.target();
    const std::string routePath = route->getPath();

    if (target.find(routePath) != 0) {
        resp.setStatus(400, "Bad Request");
        resp.setBody(load_error_page(400, "Invalid delete URL", client));
        return "";
    }

    std::string filename = target.substr(routePath.length());
    if (filename.empty() || filename.find("..") != std::string::npos) {
        resp.setStatus(400, "Bad Request");
        resp.setBody(load_error_page(400, "Invalid file path", client));
        return "";
    }

    return filename;
}
