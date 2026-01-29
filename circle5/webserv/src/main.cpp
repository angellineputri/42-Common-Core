#include "../inc/webserv.hpp"
#include <iostream>
#include "config/Tokenizer.hpp"
#include "config/mainConfig.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << RED << "Error: Wrong argument call!" << std::endl
            << "./webserv [configuration file]" << RESET << std::endl;
        return (ERR_RET);
    }
    
    WebservConfig cfg;
    try
    {
        cfg = parse_config(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (ERR_RET);
    }

    if (start_server(cfg) == ERR_RET)
        return (ERR_RET);

    return (SUCCESS);
}

