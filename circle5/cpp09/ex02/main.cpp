#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << RED << "Error: invalid arguments." << std::endl
            << "./PmergeMe [positive integer] [positive integer] ..." << RESET << std::endl;
        return (1);
    }

    PmergeMe    sorter;

    try
    {
        Result res = sorter.mergeInsertSort(argv + 1);
        PmergeMe::print_result(res);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    return (0);
}
