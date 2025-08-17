#include "Span.hpp"

Span::Span()
: max_capacity(0)
{
    std::cout << GREEN << "Span default constructor of size \'" << max_capacity << "\' is called" << RESET << std::endl;
}

Span::Span(unsigned int n)
: max_capacity(n)
{
    std::cout << GREEN << "Span constructor of size \'" << max_capacity << "\' is called" << RESET << std::endl;
}

Span::~Span()
{
    std::cout << RED << "Span destructor called" << RESET << std::endl;
}

Span::Span(const Span& other)
{
    std::cout << BLUE << "Span copy constructor called" << RESET << std::endl;
    *this = other;
}

Span&	Span::operator=(const Span &other)
{
    std::cout << BLUE << "Span copy assignment operator called" << RESET << std::endl;
	if (this != &other)
    {
        max_capacity = other.max_capacity;
        v = other.v;
    }
	return (*this);
}

void    Span::addNumber(int newN)
{
    if ((unsigned int)v.size() >= max_capacity)
        throw FullCapacityException();
    try
    {
        v.push_back(newN);
    }
    catch(const std::exception& e)
    {
        throw;
    }
}

void    Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator it = begin; it != end; ++it) {
        if (v.size() >= max_capacity)
            throw FullCapacityException();
        v.push_back(*it);
    }
}

int     Span::shortestSpan()
{
    if (v.size() <= 1)
        throw InsufficientDataException();
    std::vector<int>    tmp = v;
    std::sort(tmp.begin(), tmp.end());
    int dist = tmp[1] - tmp[0];
    for (unsigned int i = 1; i < tmp.size(); ++i)
    {
        if (tmp[i] - tmp[i - 1] < dist)
            dist = tmp[i] - tmp[i - 1];
    }
    return (dist);
}

int     Span::longestSpan()
{
    if (v.size() <= 1)
        throw InsufficientDataException();

    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());
    return (max - min);
}

const char* Span::FullCapacityException::what() const throw()
{
	return ("Error: unable to add any more data, capacity is already full!");
}

const char* Span::InsufficientDataException::what() const throw()
{
	return ("Error: unable to get span since data is insufficient!");
}

void    Span::print(int full)
{
    int tooLong = 0;
    if (v.size() > 20)
        tooLong = 1;

    for (unsigned int i = 0; i < v.size(); ++i)
    {
        if (!full && i == 18 && tooLong == 1)
        {
            std::cout << ", " << MAGENTA << "..." << RESET << ", " << MAGENTA << v[v.size() - 1] << RESET;
            return ;
        }
        if (i != 0)
            std::cout << ", ";
        std::cout << MAGENTA << v[i] << RESET;
    }
}
