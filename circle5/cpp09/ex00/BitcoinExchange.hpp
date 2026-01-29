#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <map>
#include <algorithm>
#include <stdlib.h>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

struct	dateFormat {
	std::string	str;
	std::string	year;
	std::string	mon;
	std::string	date;
};

struct	fileMeta {
	std::string	filename;
	std::string	header1;
	std::string	header2;
	std::string	delimiter;
	bool		limitValue;
};

struct fileElements
{
	dateFormat	date;
	float		value;
};

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();

		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&		operator=(const BitcoinExchange &other);

		void	calculate(std::string	filename);

	private:
		std::map<std::string, float>	database;

		std::map<std::string, float>	tokenizer(fileMeta data);
		void							processInputFile(fileMeta data);
		void							printResult(dateFormat date, float value);
		fileElements					*validateLine(fileMeta data, std::string line, int lineNumber);

		fileMeta 						createMetaData(std::string filename, std::string header1, std::string header2, bool limitValue);
		void							getDelimiter(std::string line, fileMeta &data);
		bool							checkValue(float value);
		bool							checkDate(dateFormat &date);	
		void							logError(std::string filename, std::string type, std::string typeValue, int lineNumber);

		class FailedToOpenFileException : public std::exception
		{
			public:
				const char* what() const throw();
		};	

		class WrongHeaderException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class ExchangeRateNotFound : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

#endif