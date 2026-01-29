#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED << "Error: invalid arguments." << std::endl
            << "./RPN [inverted polish mathematical expression]" << RESET << std::endl;
        return (1);
    }

    RPN rpn;

    try
    {
        int result = rpn.calculateRPN(argv[1]);
        std::cout << BLUE << "result is " << YELLOW << result << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    return (0);
}
