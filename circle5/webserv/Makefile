NAME = webserv

# Include both directories
INCLUDES = -I inc -I inc/config

SRCS = src/main.cpp \
       src/config/CGIConfig.cpp \
       src/config/config.cpp \
       src/config/ListenEndpoint.cpp \
       src/config/RouteConfig.cpp \
       src/config/ServerConfig.cpp \
       src/config/WebservConfig.cpp \
       src/config/Tokenizer.cpp \
       src/config/cgi.cpp \
       src/utils.cpp \
       src/ClientState.cpp \
       src/server_handler.cpp \
       src/Server/Server.cpp \
       src/Server/ServerCGI.cpp \
       src/Server/ServerSocket.cpp \
       src/Server/ServerConnection.cpp \
       src/Server/ServerHTTP.cpp \
       src/Server/ServerReqHandler.cpp \
       src/Server/ServerGetHandler.cpp \
       src/Server/ServerPostHandler.cpp \
       src/Server/ServerRead.cpp \
       src/Server/ServerWrite.cpp \
       src/Server/ServerUtils.cpp \
       src/SessionManager.cpp \
       src/FormUtils.cpp \
       src/http/RequestParser.cpp \
       src/http/ResponseWriter.cpp \
       src/http/HttpHeaders.cpp \
       src/http/HttpResponse.cpp \
       src/http/HttpRequest.cpp \

OBJS = $(SRCS:.cpp=.o)

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	$(CPP) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
