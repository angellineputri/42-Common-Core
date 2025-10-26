#include "../inc/webserv.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << RED << "Error: Wrong argument call!" << std::endl
            << "./webserv [configuration file]" << RESET << std::endl;
        return (1);
    }
    (void)argv;
    return (0);
}
