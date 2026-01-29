#include "../../inc/Server.hpp"

bool Server::is_cgi_request(const HttpRequest& req, const ClientState& client)
{
    const std::string& target = req.target();

    size_t dot_pos = target.find_last_of('.');
    if (dot_pos == std::string::npos)
        return false;
    std::string ext = target.substr(dot_pos);

    const ServerConfig* server = client.server;
    if (!server)
        return false;

    RouteConfig* route = matchRoute(client.server, req.target());
    if (!route)
        return false;

    const std::vector<CGIConfig>& cgis = route->getCGIs();
    for (size_t c = 0; c < cgis.size(); ++c) {
        if (cgis[c].getExtension() == ext) {
            return true;
        }
    }

    return false;
}

void Server::handle_cgi_request(int fd, const HttpRequest &req, ClientState &client)
{
    log("[CGI] Request: " + req.method() + " " + req.target(), MAGENTA);

    const RouteConfig* route = matchRoute(client.server, req.target());
    if (!route) { 
        send_error(fd, 404, client); 
        return; 
    }

    const CGIConfig* cgi = find_cgi(route, req.target());
    if (!cgi) { 
        send_error(fd, 501, client); 
        return; 
    }

    std::string script_path = build_script_path(client.server->getRoot(), *route, req.target());

    int in_pipe[2], out_pipe[2];
    if (pipe(in_pipe) < 0 || pipe(out_pipe) < 0) { 
        perror("pipe"); 
        return; 
    }

    pid_t pid = fork();
    if (pid < 0) { 
        perror("fork"); 
        return; 
    }

    if (pid == 0)
        exec_cgi_child(cgi, script_path, req, in_pipe, out_pipe); 

    PendingCGI pending;
    pending.pid = pid;
    pending.out_fd = out_pipe[0];
    pending.in_fd = (req.method() == "POST" && !req.body().empty()) ? in_pipe[1] : -1;
    pending.client_fd = fd;
    pending.buffer = "";
    pending.start_time = std::time(0);
    pending.post_data = (req.method() == "POST") ? req.body() : "";
    pending.post_offset = 0;

    close(in_pipe[0]);
    close(out_pipe[1]); 

    struct pollfd pfd_out;
    pfd_out.fd = pending.out_fd;
    pfd_out.events = POLLIN;
    pfds.push_back(pfd_out);

    if (pending.in_fd >= 0)
    {
        struct pollfd pfd_in;
        pfd_in.fd = pending.in_fd;
        pfd_in.events = POLLOUT;
        pfds.push_back(pfd_in);
    }

    pending_cgis.push_back(pending);
}

const CGIConfig* Server::find_cgi(const RouteConfig* route, const std::string &target)
{
    std::string ext = target.substr(target.find_last_of('.'));
    const std::vector<CGIConfig>& cgis = route->getCGIs();
    for (size_t i = 0; i < cgis.size(); ++i)
        if (cgis[i].getExtension() == ext) 
            return &cgis[i];
    return 0;
}

std::string Server::build_script_path(const std::string &root, const RouteConfig &route, const std::string &target)
{
    std::string path = target;
    if (path.find(route.getPath()) == 0) 
        path = path.substr(route.getPath().length());
    if (!path.empty() && path[0] == '/')
        path = path.substr(1);
    return root + route.getRoot() + "/" + path;
}

void Server::exec_cgi_child(const CGIConfig* cgi, const std::string &script_path, const HttpRequest &req, int in_pipe[2], int out_pipe[2])
{
    dup2(out_pipe[1], STDOUT_FILENO);
    dup2(out_pipe[1], STDERR_FILENO);

    if (req.method() == "POST" && !req.body().empty())
        dup2(in_pipe[0], STDIN_FILENO);
    else
    {
        int devnull = open("/dev/null", O_RDONLY);
        dup2(devnull, STDIN_FILENO);
        close(devnull);
    }

    close(in_pipe[0]); close(in_pipe[1]);
    close(out_pipe[0]); close(out_pipe[1]);

    std::string request_uri = req.target();  
    std::string url_path    = request_uri.substr(0, request_uri.find('?'));
    std::string contentType = req.header("Content-Type");      

    std::vector<const char*> envp = buildCGIEnv(
        script_path,  
        url_path,      
        request_uri,
        req.method(),
        req.body().size(),
        contentType
    );

    char* argv[3];
    argv[0] = const_cast<char*>(cgi->getExecutable().c_str());
    argv[1] = const_cast<char*>(script_path.c_str());
    argv[2] = 0;

    execve(argv[0], argv, const_cast<char* const*>(envp.data()));
    perror("execve");
    _exit(1);
}

std::string Server::parse_cgi_output(const std::string &cgi_output)
{
    size_t pos = cgi_output.find("\r\n\r\n");
    if (pos != std::string::npos) 
        return cgi_output.substr(pos + 4);

    pos = cgi_output.find("\n\n");
    if (pos != std::string::npos) 
        return cgi_output.substr(pos + 2);

    return cgi_output;
}

void Server::send_error(int fd, int code, ClientState &client)
{
    HttpResponse resp;
    resp.setStatus(code, (code == 404) ? "Not Found" : "Not Implemented");
    resp.setBody(load_error_page(code, "", client));
    send_response(fd, resp);
}

std::vector<const char*> Server::buildCGIEnv(const std::string &script_fs_path,
                                             const std::string &url_path,
                                             const std::string &request_uri,
                                             const std::string &method,
                                             size_t contentLength,
                                             const std::string &contentType)
{
    static std::vector<std::string> envStrings;
    std::vector<const char*> envp; envStrings.clear();

    envStrings.push_back("REQUEST_METHOD=" + method);
    envStrings.push_back("CONTENT_LENGTH=" + ft_to_string(contentLength));
    if (!contentType.empty()) 
        envStrings.push_back("CONTENT_TYPE=" + contentType);

    envStrings.push_back("GATEWAY_INTERFACE=CGI/1.1");
    envStrings.push_back("SERVER_PROTOCOL=HTTP/1.1");
    envStrings.push_back("REDIRECT_STATUS=200");
    envStrings.push_back("SCRIPT_NAME=" + url_path);   
    envStrings.push_back("REQUEST_URI=" + request_uri);  

    std::string qs;
    size_t qpos = request_uri.find('?');
    if (qpos != std::string::npos) 
        qs = request_uri.substr(qpos + 1);

    envStrings.push_back("QUERY_STRING=" + qs);
    envStrings.push_back("SCRIPT_FILENAME=" + script_fs_path);

    for (size_t i = 0; i < envStrings.size(); ++i) envp.push_back(envStrings[i].c_str());
    envp.push_back(0);
    return envp;
}
