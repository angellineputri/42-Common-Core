#include "../../inc/config/mainConfig.hpp"

void parse_directive(const std::vector<t_token> &tokens, size_t &pos, ServerConfig &server, RouteConfig *route) {
    if (pos >= tokens.size())
        return;

    std::string directive = tokens[pos++].value;

    std::vector<std::string> args;

    while (pos < tokens.size() && tokens[pos].type != TOKEN_SEMICOLON) {
        args.push_back(tokens[pos].value);
        ++pos;
    }

    if (pos >= tokens.size() || tokens[pos].type != TOKEN_SEMICOLON)
        throw std::runtime_error("Missing ';' after directive " + directive);
    ++pos;

    if (route != 0) {
        if (directive == "root" && !args.empty())
            route->setRoot(args[0]);
        else if (directive == "methods")
            for (size_t i = 0; i < args.size(); ++i)
                route->addMethod(args[i]);
        else if (directive == "autoindex" && !args.empty())
            route->setAutoindex(args[0] == "on");
        else if (directive == "index" && !args.empty())
            route->setIndexFile(args[0]);
        else if (directive == "upload_store" && !args.empty()) {
            route->setUploadEnabled(true);
            route->setUploadStore(args[0]);
        } else if (directive == "redirect" && !args.empty())
            route->setRedirect(args[0]);
        else if (directive == "cgi_extension" && !args.empty()) {
            CGIConfig cgi;
            cgi.setExtension(args[0]);
            route->addCGI(cgi);
        } else if (directive == "cgi_path" && !args.empty()) {
            std::vector<CGIConfig> &cgis = route->getCGIs();
            if (!cgis.empty())
                cgis.back().setExecutable(args[0]);
        }
    }


    else {
        if (directive == "listen" && !args.empty()) {
            ListenEndpoint ep;
            std::string ip_port = args[0];
            std::string ip = "0.0.0.0";
            int port = 80;

            size_t colon = ip_port.find(':');
            if (colon != std::string::npos) {
                ip = ip_port.substr(0, colon);
                port = std::atoi(ip_port.substr(colon + 1).c_str());
            } else {
                port = std::atoi(ip_port.c_str());
            }

            ep.setIP(ip);
            ep.setPort(port);
            server.addListen(ep);
        } else if (directive == "server_name" && !args.empty())
            server.setServerName(args[0]);
        else if (directive == "root" && !args.empty())
            server.setRoot(args[0]);
        else if (directive == "client_max_body_size" && !args.empty())
            server.setMaxBodySize(std::strtoul(args[0].c_str(), 0, 10));
        else if (directive == "error_page" && args.size() >= 2)
            server.addErrorPage(std::atoi(args[0].c_str()), args[1]);
    }
}

void parse_location(const std::vector<t_token> &tokens, size_t &pos, ServerConfig &server) {
    if (pos >= tokens.size() || tokens[pos].type != TOKEN_KEYWORD)
        throw std::runtime_error("Expected path after 'location'");

    std::string path = tokens[pos++].value;

    if (pos >= tokens.size() || tokens[pos].type != TOKEN_LBRACE)
        throw std::runtime_error("Expected '{' after location path");
    ++pos;

    RouteConfig route;
    route.setPath(path);

    while (pos < tokens.size() && tokens[pos].type != TOKEN_RBRACE) {
            parse_directive(tokens, pos, server, &route);
    }

    if (pos >= tokens.size() || tokens[pos].type != TOKEN_RBRACE)
        throw std::runtime_error("Missing '}' at end of location");
    ++pos;

    server.addRoute(route);
}

ServerConfig parse_server(const std::vector<t_token> &tokens, size_t &pos) {
    ServerConfig server;

    if (pos >= tokens.size() || tokens[pos].type != TOKEN_LBRACE)
        throw std::runtime_error("Expected '{' after server");
    ++pos;

    while (pos < tokens.size() && tokens[pos].type != TOKEN_RBRACE) {
        if (tokens[pos].type == TOKEN_KEYWORD && tokens[pos].value == "location") {
            ++pos;
            parse_location(tokens, pos, server);
        } else {
            parse_directive(tokens, pos, server, 0);
        }
    }

    if (pos >= tokens.size() || tokens[pos].type != TOKEN_RBRACE)
        throw std::runtime_error("Missing '}' at end of server");
    ++pos;

    return server;
}

WebservConfig parse_config(const std::string &filename) {
    std::ifstream infile(filename.c_str());
    if (!infile)
        throw std::runtime_error("Cannot open config file");

    std::stringstream buffer;
    buffer << infile.rdbuf();

    Tokenizer lexer(buffer.str());
    std::vector<t_token> tokens = lexer.tokenizeAll();

    WebservConfig config;
    size_t pos = 0;

    while (pos < tokens.size()) {
        if (tokens[pos].type == TOKEN_KEYWORD && tokens[pos].value == "server") {
            ++pos;
            config.addServer(parse_server(tokens, pos));
        } else {
            ++pos;
        }
    }

    return config;
}
