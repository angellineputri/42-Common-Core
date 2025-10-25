#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
: std::stack<T>()
{
    std::cout << GREEN << "MutantStack default constructor is called" << RESET << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << RED << "MutantStack destructor called" << RESET << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other)
: std::stack<T, std::deque<T> >(other)
{
    std::cout << BLUE << "MutantStack copy constructor called" << RESET << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &other)
{
    std::cout << BLUE << "MutantStack copy assignment operator called" << RESET << std::endl;
	if (this != &other)
    {
        std::stack<T, std::deque<T> >::operator=(other);
    }
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
    return (this->c.end());
}
