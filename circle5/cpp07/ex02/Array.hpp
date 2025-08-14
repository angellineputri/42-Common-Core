#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

template <typename T>
class Array
{
    public:
        Array();
        Array(unsigned int n);
        ~Array();

        Array(const Array& other);
        Array&  operator=(const Array &other);
        T&      operator[](unsigned int i);

        unsigned int    size() const;

        class InvalidIndexException : public std::exception
		{
			public:
				const char* what() const _NOEXCEPT;
		};

    private:
        unsigned int    capacity;
        T               *arr;
};

#include "Array.tpp"

#endif