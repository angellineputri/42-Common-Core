#include "../../inc/Server.hpp"

void Server::handleAuthLogin(const HttpRequest &req, HttpResponse &resp, ClientState &client)
{
    std::map<std::string, std::string> formData = parsePostData(req.body());
    std::string username = formData["username"];
    std::string password = formData["password"];

    if (username.empty() || password.empty()) {
        resp.setStatus(400, "Bad Request");
        resp.addHeader("Content-Type", "text/html");
        resp.setBody(load_error_page(400, "username and password is required", client));
        return;
    }

    bool loginSuccess = false;
    if (sessionManager.authenticate(username, password, client.sessionId)) {
        loginSuccess = true;
    }

    if (loginSuccess) {
        client.session->username = username;
        client.session->theme = sessionManager.getTheme(username, client.sessionId);
        if (client.session->theme == "")
            client.session->theme = "blue";

        resp.setStatus(302, "Found");
        resp.addHeader("Location", "/");
        
        std::ostringstream cookieName;
        cookieName << "session_id_" << (*(client.server)).getListens()[0].getPort();
        resp.addHeader("Set-Cookie", cookieName.str() + "=" + client.sessionId + "; Path=/; HttpOnly");
        return;
    } else {
        resp.setStatus(401, "Unauthorized");
        resp.addHeader("Content-Type", "text/html");
        resp.setBody(load_error_page(401, "Login failed! Invalid username or password", client));
        return;
    }
}

void Server::handleAuthRegister(const HttpRequest &req, HttpResponse &resp, ClientState &client)
{
    std::map<std::string, std::string> formData = parsePostData(req.body());

    if (formData.find("username") == formData.end() || formData.find("password") == formData.end()) {
        resp.setStatus(400, "Bad Request");
        resp.addHeader("Content-Type", "text/html");
        resp.setBody(load_error_page(400, "Username or password cannot be empty.", client));
        return ;
    }

    std::string username = formData["username"];
    std::string password = formData["password"];

    if (username.empty() || password.empty()) {
        resp.setStatus(400, "Bad Request");
        resp.addHeader("Content-Type", "text/html");
        resp.setBody(load_error_page(400, "Username or password cannot be empty.", client));
        return;
    }

    if (sessionManager.userExist(username, client.sessionId)){
        resp.setStatus(409, "Conflict");
        resp.addHeader("Content-Type", "text/html");
        resp.setBody(load_error_page(409, "User already exists.", client));
        return;
    }

    sessionManager.registerUser(username, password, sessionManager.getSession(client.sessionId)->theme, client.sessionId);
    resp.setStatus(302, "Found");
    resp.addHeader("Location", "/");
    return;
}

void Server::handleThemeChange(HttpResponse &resp, const HttpRequest &req, ClientState &client)
{
    std::map<std::string, std::string> formData = parsePostData(req.body());
    if (formData.find("theme") == formData.end()) {
        resp.setStatus(400, "Bad Request");
        resp.setBody(load_error_page(400, "Invalid theme", client));
        return;
    }

    std::string theme = formData["theme"];
    if (theme != "blue" && theme != "green" && theme != "pink") {
        resp.setStatus(400, "Bad Request");
        resp.setBody(load_error_page(400, "Invalid theme", client));
        return;
    }

    Session* session = sessionManager.getSession(client.sessionId);
    if (session) {
        session->theme = theme;
        sessionManager.setTheme(session->username, theme, client.sessionId);
    }

    resp.setStatus(200, "OK");
    resp.setBody("Theme saved to session");
    return ;
}

void Server::handleFileUpload(const HttpRequest &req, HttpResponse &resp, RouteConfig* route, ClientState &client)
{
    std::string contentType = req.header("content-type");
    std::string boundaryKey = "boundary=";
    size_t boundaryPos = contentType.find(boundaryKey);

    if (boundaryPos == std::string::npos) {
        resp.setStatus(400, "Bad Request");
        resp.setBody(load_error_page(400, "Missing multipart boundary", client));
        return;
    }

    std::string boundary = contentType.substr(boundaryPos + boundaryKey.size());
    FormFile file;

    if (!parse_multipart(req.body(), boundary, file)) {
        resp.setStatus(400, "Bad Request");
        resp.setBody(load_error_page(400, "No file found in request", client));
        return;
    }

    if (file.filename.empty()) {
        resp.setStatus(400, "Bad Request");
        resp.setBody(load_error_page(400, "File name is required", client));
        return;
    }

    std::string upload_dir = route->getUploadStore();
    if (upload_dir.empty()) {
        upload_dir = "www/sandbox";
    }

    std::string mkdir_cmd = "mkdir -p " + upload_dir;
    std::system(mkdir_cmd.c_str());

    if (file.filename.find("..") != std::string::npos || file.filename.find('/') != std::string::npos) {
        resp.setStatus(400, "Bad Request");
        resp.setBody(load_error_page(400, "Invalid file name", client));
        return;
    }

    std::string full_path = upload_dir + "/" + file.filename;

    std::ofstream outfile(full_path.c_str(), std::ios::binary);
    if (!outfile) {
        std::cerr << "[UploadHandler] Failed to open file for writing: " << full_path << std::endl;
        resp.setStatus(500, "Internal Server Error");
        resp.setBody(load_error_page(500, "Failed to create file", client));
        return;
    }

    outfile.write(file.content.c_str(), file.content.size());
    outfile.close();

    resp.setStatus(200, "OK");
    resp.addHeader("Content-Type", "text/html");
    resp.setBody(load_respond_page(file.filename, "upload_file", client));
}

void Server::handleTextFilePost(const HttpRequest &req, HttpResponse &resp, RouteConfig* route, ClientState &client)
{
    std::map<std::string, std::string> formData = parsePostData(req.body());
    std::string filename = formData["filename"];
    std::string content  = formData["content"];

    if (filename.empty()) {
        resp.setStatus(400, "Bad Request");
        resp.setBody(load_error_page(400, "File name is required", client));
        return;
    }

    std::string upload_dir = route->getUploadStore();

    if (upload_dir.empty()) {
        upload_dir = "www/sandbox";
    }

    std::string mkdir_cmd = "mkdir -p " + upload_dir;
    std::system(mkdir_cmd.c_str());

    std::string full_path = upload_dir + "/" + filename;

    std::ofstream outfile(full_path.c_str());
    if (!outfile) {
        std::cerr << "[Upload] Failed to open file for writing: " << full_path << std::endl;
    } else {
        outfile << content;
        outfile.close();
    }

    resp.setStatus(200, "OK");
    resp.addHeader("Content-Type", "text/html");
    resp.setBody(load_respond_page(filename, "create_file", client));
}
