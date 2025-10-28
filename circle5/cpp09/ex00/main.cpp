#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED << "Error: Could not open file." << std::endl
            << "./btc [file]" << RESET << std::endl;
        return (1);
    }
    try {
        BitcoinExchange btcExchange(argv[1]);
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    return (0);
}
