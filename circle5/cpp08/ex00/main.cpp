#include "easyfind.hpp"
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

template <typename T>
void    print_container(T &container)
{
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        if (it != container.begin())
            std::cout << ", ";
        std::cout << *it;
    }
    std::cout << std::endl;
}

template <typename T>
void    initialize_sq(T &container)
{
    container.push_back(2);
    container.push_back(3);
    container.push_back(5);
}

template <typename T>
void    initialize_adp(T &container)
{
    container.push(2);
    container.push(3);
    container.push(5);
}

template <typename T>
void    test_container(T &container, std::string name, int i)
{
    std::cout << BLUE << "[" << i << "] Test easyfind with " << name  << " container" << RESET << std::endl;
    std::cout << name << ": ";
    print_container(container);
    for (int i = 1; i < 7; ++i)
    {
        try
        {
            std::cout << "finding \'" << YELLOW << i << RESET << "\', ";
            std::cout << "result: " << YELLOW << *easyfind(container, i) << RESET << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;
}

int main()
{
    std::array<int, 3> arr = {2, 3, 5};
    std::vector<int> v;
    std::deque<int> dq;
    std::list<int> l;
    std::stack<int> st;

    initialize_sq(v);
    initialize_sq(dq);
    initialize_sq(l);
    initialize_adp(st);

    test_container(arr, "array", 1);
    test_container(v, "vector", 2);
    test_container(dq, "deque", 3);
    test_container(l, "list", 4);
    test_container(l, "stack", 5);
    
    return (0);
}
