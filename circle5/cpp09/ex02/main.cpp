#include "PmergeMe.hpp"

void    print_result(Result res)
{
    std::vector<int>::iterator it;
    std::cout << YELLOW << "Before: ";
    for (it = res.before.begin(); it != res.before.end(); ++it) {
        std::cout << BLUE << *it << RESET;
        if ((it + 1) != res.before.end())
            std::cout << ", ";
        else
            std::cout << std::endl;
    }

    int prev = *res.v.begin();
    std::cout << YELLOW << "After (std::vector):  ";
    for (it = res.v.begin(); it != res.v.end(); ++it) {
        std::cout << BLUE << *it << RESET;
        if (*it < prev)
        {
            std::cout << RED << std::endl << "not sorted!" << RESET << std::endl;
            exit(1);
        }
        else
            prev = *it;
        if ((it + 1) != res.v.end())
            std::cout << ", ";
        else
            std::cout << std::endl;
    }
    std::cout << GREEN << "sorted!" << RESET << std::endl;
    
    std::deque<int>::iterator itdq;
    std::cout << YELLOW << "After (std::deque):  ";

    prev = *res.dq.begin();
    for (itdq = res.dq.begin(); itdq != res.dq.end(); ++itdq) {
        std::cout << BLUE << *itdq << RESET;
        if (*itdq < prev)
        {
            std::cout << RED << std::endl << "not sorted!" << RESET << std::endl;
            exit(1);
        }
        else
            prev = *it;
        if ((itdq + 1) != res.dq.end())
            std::cout << ", ";
        else
            std::cout << std::endl;   
    }
    std::cout << GREEN << "sorted!" << RESET << std::endl;

    std::cout << YELLOW << "Time to process a range of 5 elements with std::" 
        << BLUE << "vector" << YELLOW << " is: " 
        << BLUE << res.vTime << YELLOW << " us" << RESET << std::endl;

    std::cout << YELLOW << "Time to process a range of 5 elements with std::" 
        << BLUE << "deque" << YELLOW << " is: " 
        << BLUE << res.dqTime << YELLOW << " us" << RESET << std::endl;
}

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
        print_result(res);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    return (0);
}
