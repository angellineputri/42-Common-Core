#include "../../inc/Server.hpp"

std::string Server::toLowerStr(const std::string &s)
{
    std::string t = s;
    for (size_t i = 0; i < t.size(); ++i)
        if (t[i] >= 'A' && t[i] <= 'Z') t[i] = char(t[i]-'A'+'a');
    return t;
}

bool Server::request_keep_alive(const HttpRequest &req)
{
    std::string conn = toLowerStr(req.header("connection"));
    if (req.version() == "HTTP/1.1") {
        if (conn == "close") return false;
        return true;
    } else {
        if (conn == "keep-alive") return true;
        return false;
    }
}

void    Server::handle_signal(int sig)
{
    if (sig == SIGINT)
        s_signal_received = 1;
}

void Server::log(const std::string& message, const std::string& color)
{
	time_t timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);

	std::cout << BLUE << "["
	    << std::setfill('0') << std::setw(4) << datetime.tm_year + 1900 << "-"
		<< std::setfill('0') << std::setw(2) << datetime.tm_mon + 1 << "-"
		<< std::setfill('0') << std::setw(2) << datetime.tm_mday
		<< " "
		<< std::setfill('0') << std::setw(2) << datetime.tm_hour << ":"
		<< std::setfill('0') << std::setw(2) << datetime.tm_min << ":"
		<< std::setfill('0') << std::setw(2) << datetime.tm_sec
		<< "] ";
    
    std::cout << color << message << RESET << std::endl;
}

RouteConfig* Server::matchRoute(ServerConfig *server, const std::string &target)
{
    if (!server)
        return NULL;

    RouteConfig* bestMatch = NULL;
    size_t longestMatch = 0;

    const std::vector<RouteConfig>& routes = server->getRoutes();
    for (size_t i = 0; i < routes.size(); ++i) {
        const RouteConfig &r = routes[i];
        const std::string &path = r.getPath();

        if (target.find(path) == 0) {
            if (path.length() > longestMatch) {
                bestMatch = const_cast<RouteConfig*>(&r);
                longestMatch = path.length();
            }
        }
    }

    return bestMatch;
}

int Server::make_nonblocking(int fd)
{
    int flags = fcntl(fd, F_GETFL, 0);

    if (flags == -1)
        return ERR_RET;

    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1)
        return ERR_RET;

    return (SUCCESS);
}

void Server::add_pollfd(int fd, short events)
{
    struct pollfd p;

    p.fd = fd;
    p.events = events;
    p.revents = 0;

    pfds.push_back(p);
}

void Server::remove_pollfd(int fd)
{
    for (std::vector<struct pollfd>::iterator it = pfds.begin(); it != pfds.end(); ++it) {
        if (it->fd == fd) {
            pfds.erase(it);
            break ;
        }
    }
}

bool Server::is_listener(int fd)
{
    return (std::find(listen_fds.begin(), listen_fds.end(), fd) != listen_fds.end());
}

std::string Server::urlDecode(const std::string &src)
{
    std::string ret;
    char ch;
    std::string::size_type i;

    for (i = 0; i < src.length(); ++i) {
        if (src[i] == '%') {
            if (i + 2 < src.length()) {
                std::istringstream iss(src.substr(i + 1, 2));
                int hexVal;
                iss >> std::hex >> hexVal;
                ch = static_cast<char>(hexVal);
                ret += ch;
                i += 2;
            }
        } else if (src[i] == '+') {
            ret += ' ';
        } else {
            ret += src[i];
        }
    }
    return ret;
}

// bool Server::looks_like_cgi(const std::string& s)
// {
//     size_t sep = s.find("\r\n\r\n");
//     if (sep == std::string::npos)
//         sep = s.find("\n\n");
//     if (sep == std::string::npos)
//         return false;

//     std::string headers = s.substr(0, sep);
//     return (headers.find("Content-Type:") != std::string::npos || headers.find("Status:") != std::string::npos);
// }
