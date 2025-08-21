#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <exception>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();

		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&		operator=(const BitcoinExchange &other);

	private:

};

#endif