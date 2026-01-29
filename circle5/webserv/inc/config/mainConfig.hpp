#ifndef MAINCONFIG_HPP
#define MAINCONFIG_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
#include <stdexcept>

#include "CGIConfig.hpp"
#include "ListenEndpoint.hpp"
#include "RouteConfig.hpp"
#include "ServerConfig.hpp"
#include "WebservConfig.hpp"
#include "config/Tokenizer.hpp"
#include "config/mainConfig.hpp"

void parse_directive(const std::vector<t_token> &tokens, size_t &pos, ServerConfig &server, RouteConfig *route);
void parse_location(const std::vector<t_token> &tokens, size_t &pos, ServerConfig &server);
ServerConfig parse_server(const std::vector<t_token> &tokens, size_t &pos);
WebservConfig parse_config(const std::string &filename);

void executeCGI(const std::string &script_path, const RouteConfig &route);

#endif
