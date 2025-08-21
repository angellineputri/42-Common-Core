#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED << "Error: Wrong argument call!" << std::endl
            << "./btc [file]" << RESET << std::endl;
        return (1);
    }
    return (0);
}
