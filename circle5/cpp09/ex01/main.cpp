#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED << "Error: invalid arguments." << std::endl
            << "./RPN [inverted polish mathematical expression]" << RESET << std::endl;
        return (1);
    }

    RPN rpn(argv[1]);
    return (0);
}
