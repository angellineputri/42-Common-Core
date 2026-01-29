#ifndef SERVER_HPP
# define SERVER_HPP

#include "webserv.hpp"
#include "ClientState.hpp"
#include "FormUtils.hpp"
#include "PendingCGI.hpp"

#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <signal.h>
#include <dirent.h>
#include <sys/stat.h>

class Server
{
	public:
		Server();
		~Server();

		void init(const WebservConfig& cfg);
		void run();

		static void	log(const std::string& message, const std::string& color);

	private:
		static volatile sig_atomic_t s_signal_received;

		WebservConfig 				_cfg;
		SessionManager				sessionManager;
		bool						running;
		std::vector<int>			listen_fds;
		std::vector<struct pollfd>	pfds; 
		std::map<int, ClientState>	clients;
		std::map<int, std::string>	listener_to_server;
		std::vector<PendingCGI> 	pending_cgis;
		static const int CGI_TIMEOUT = 5;

		void handle_listener_event(struct pollfd &pe);
		void handle_client_event(struct pollfd &pe);
		void handle_client_disconnect(struct pollfd &pe);

		//ServerUtils.cpp
		std::string		toLowerStr(const std::string &s);
		bool			request_keep_alive(const HttpRequest &req);
		static void		handle_signal(int sig);
		RouteConfig*	matchRoute(ServerConfig *server, const std::string &target);
		int				make_nonblocking(int fd);
		void			add_pollfd(int fd, short events);
		void			remove_pollfd(int fd);
		bool			is_listener(int fd);
		std::string		urlDecode(const std::string &src);

		//ServerSocket.cpp
		void		add_listener(std::string ip, int port, std::string server_name);
		int			create_listening_socket();
		void		configure_socket(int fd);
		void		bind_and_listen(int fd, std::string ip, int port);

		//ServerConnection.cpp
		void		handle_new_connection(int listen_fd);
		int			accept_new_client(int listen_fd, struct sockaddr_in &cli);
		void		setup_client_state(int cfd, int listen_f, struct sockaddr_in &cli);
		void		assign_server_config(ClientState &client);

		//ServerRead.cpp
		ssize_t 	read_some(int fd, char* data, size_t len);
		void		handle_client_read(int fd);
		void		handle_received_data(int fd, char* buf, size_t len);
		void		handle_parse_error(int fd, ClientState &client);
		void		handle_complete_request(int fd, ClientState &client);
		void		disconnect_client(int fd, std::string reason);
		void		handle_recv_error(int fd);

		//ServerWrite.cpp
		ssize_t 	write_some(int fd, const char* data, size_t len);
		void		update_poll_event(int fd, short new_events);
		void		disable_write_event(int fd, ClientState &state);
		void		handle_client_write(int fd);
		void		handle_write_success(int fd, ClientState &state, ssize_t n);
		void		handle_write_failure(int fd);
		
		//ServerHTTP.cpp
		void		send_response(int fd, const HttpResponse& resp);
		std::string	changeResp(std::string buffer, const std::string &username, const std::string &sessionId, const std::string &server_name);		
		std::string load_error_page(int status_code, const std::string& custom_msg, ClientState &client);
		std::string find_error_page_path(int status_code, ClientState &client);
		std::string load_respond_page(std::string filename, std::string type, ClientState &client);

		//ServerReqHandler.cpp
		void 		handle_http_request(int fd, const HttpRequest& req, ClientState &client);
		bool		validate_route(int fd, const HttpRequest &req, RouteConfig *route, ClientState &client);
		bool		handle_redirect(int fd, RouteConfig *route);
		void		setup_session(const HttpRequest &req, HttpResponse &resp, ClientState &client);
		void		handleGET(int fd, const HttpRequest &req, HttpResponse &resp, ClientState &clien, RouteConfig* route );
		void		handlePOST(int fd, const HttpRequest &req, HttpResponse &resp, ClientState &client, RouteConfig* route);
		void		handleDELETE(int fd, const HttpRequest &req, HttpResponse &resp, const RouteConfig* route, const std::string &serverRoot, ClientState &client);
		std::string	extract_delete_filename(const HttpRequest &req, const RouteConfig *route, HttpResponse &resp, ClientState &client);
		
		//ServerGetHandler.cpp
		void	handleAutoIndexHtml(HttpResponse &resp, const std::string &folderPath, const std::string &requestPath, ClientState &client);
		void    handleFileDownload(HttpResponse &resp, std::string &target, RouteConfig* route, std::string main_path, ClientState &client);
		void    handleStaticFile(const HttpRequest &req, HttpResponse &resp, ClientState &client, RouteConfig* route, std::string main_path);

		//ServerPostHandler.cpp
		void	handleAuthLogin(const HttpRequest &req, HttpResponse &resp, ClientState &client);
		void	handleAuthLoginCheck(HttpResponse &resp, ClientState &client);
		void	handleAuthRegister(const HttpRequest &req, HttpResponse &resp, ClientState &client);
		void	handleThemeChange(HttpResponse &resp, const HttpRequest &req, ClientState &client);
		void	handleFileUpload(const HttpRequest &req, HttpResponse &resp, RouteConfig* route, ClientState &client);
		void	handleTextFilePost(const HttpRequest &req, HttpResponse &resp, RouteConfig* route, ClientState &client);

		//ServerCGI.cpp
		bool						is_cgi_request(const HttpRequest& req, const ClientState& client);
		std::vector<const char*> 	buildCGIEnv(const std::string &script_fs_path, const std::string &url_path, 
												const std::string &request_uri, const std::string &method, 
												size_t contentLength, const std::string &contentType);
		const CGIConfig* 			find_cgi(const RouteConfig* route, const std::string &target);
		std::string 				build_script_path(const std::string &root, const RouteConfig &route, const std::string &target);
		void 						exec_cgi_child(const CGIConfig* cgi, const std::string &script_path, const HttpRequest &req, int in_pipe[2], int out_pipe[2]);
		void 						exec_cgi_parent(int fd, const HttpRequest &req, ClientState &client, pid_t pid, int in_pipe[2], int out_pipe[2]);
		std::string 				parse_cgi_output(const std::string &cgi_output);
		void 						send_error(int fd, int code, ClientState &client);
		void 						handle_cgi_request(int fd, const HttpRequest &req, ClientState &client);
		void 						handle_cgi_event(struct pollfd &pe);
		bool 						is_cgi_fd(int fd);
};

#endif