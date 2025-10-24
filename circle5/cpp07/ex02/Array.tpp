#include <iostream>
#include "Array.hpp"

template <typename T>
Array<T>::Array()
: capacity(0)
{
	std::cout << GREEN << "Array size '0' default constructor called" << RESET << std::endl;
    arr = new T[capacity]();
}

template <typename T>
Array<T>::Array(unsigned int n)
: capacity(n)
{
	std::cout << GREEN << "Array size \'" << capacity << "\' default constructor called" << RESET << std::endl;
    arr = new T[capacity]();
}

template <typename T>
Array<T>::~Array()
{
	std::cout << RED << "Array size \'" << capacity << "\' destructor called" << RESET << std::endl;
    delete [] arr;
}

template <typename T>
Array<T>::Array(const Array& other)
: capacity(other.capacity)
{
	std::cout << BLUE << "Array copy constructor called" << RESET << std::endl;
    arr = new T[capacity];
    for (unsigned int i = 0; i < capacity; ++i)
    {
        arr[i] = other.arr[i];
    }
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array &other)
{
	std::cout << BLUE << "Array copy assignment operator called" << RESET << std::endl;
	if (this != &other)
    {
        if (arr)
            delete [] arr;
        capacity = other.size();
        arr = new T[capacity];
        for (unsigned int i = 0; i < capacity; ++i)
        {
            arr[i] = other[i];
        }
    }
	return (*this);
}

template <typename T>
T&  Array<T>::operator[](unsigned int i) const
{
    if (!arr || i > capacity - 1 || capacity == 0)
    {
        throw InvalidIndexException();
    }
    return (arr[i]);
}

template <typename T>
unsigned int    Array<T>::size() const
{
    return (capacity);
}

template <typename T>
const char* Array<T>::InvalidIndexException::what() const throw()
{
	return ("Error: invalid index");
}

template <class T>
std::ostream&	operator<<(std::ostream& stream, Array<T>const& cl)
{
	cl.display(stream);
	return (stream);
}