#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << GREEN << "BitcoinExchange default constructor called" << RESET << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << RED << "BitcoinExchange destructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	std::cout << BLUE << "BitcoinExchange copy constructor called" << RESET << std::endl;
	*this = other;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &other)
{
	std::cout << BLUE << "BitcoinExchange copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}
