#ifndef WEBSERV_HPP
# define WEBSERV_HPP

#include <iostream>
#include <iomanip>
#include <ctime>
#include "config/WebservConfig.hpp"
#include "SessionManager.hpp"
#include "config/mainConfig.hpp"
#include "Server.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

#define ERR_RET 1
#define SUCCESS 0

// from utils.cpp
std::string ft_to_string(int n);

// from server_handler.cpp
int start_server(WebservConfig cfg);

#endif