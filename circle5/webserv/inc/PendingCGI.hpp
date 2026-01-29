#ifndef PENDINGCGI_HPP
#define PENDINGCGI_HPP

struct PendingCGI
{
    pid_t pid; 
    int out_fd;  
    int in_fd;       
    int client_fd;     
    std::string buffer;  
    std::string post_data; 
    size_t post_offset; 
    std::time_t start_time;
};

#endif