#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename)
{
	// std::cout << GREEN << "BitcoinExchange default constructor called" << RESET << std::endl;
	fileMeta	dbFileMeta = createMetaData("data.csv", "date", "exchange_rate", false);
	fileMeta	inputFileMeta = createMetaData(filename, "date", "value", true);
	try { 
		database = tokenizer(dbFileMeta);
	} catch(const std::exception& e){
		std::string msg = std::string(e.what()) + " data.csv";
    	throw std::runtime_error(msg);
	}
	
	try { 
		processInputFile(inputFileMeta);
	} catch(const std::exception& e){
		std::string msg = std::string(e.what()) + " " + filename;
    	throw std::runtime_error(msg);
	}
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << RED << "BitcoinExchange destructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	// std::cout << BLUE << "BitcoinExchange copy constructor called" << RESET << std::endl;
	*this = other;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &other)
{
	// std::cout << BLUE << "BitcoinExchange copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

std::map<std::string, float>	BitcoinExchange::tokenizer(fileMeta data)
{
	std::ifstream	file(data.filename);
    if (!file.is_open()) {
		throw FailedToOpenFileException() ;
    }

	std::map<std::string, float> 	res;
    std::string						line;
	int								lineNumber = 1;

    while (std::getline(file, line))
	{
		if (lineNumber == 1) {
			try {
				getDelimiter(line, data);
			}
			catch(const std::exception& e) {
    			throw ;
			}
			lineNumber++;
			continue;
		}

		fileElements *fe = validateLine(data, line, lineNumber);
		if (fe) {
			res[fe->date.str] = fe->value;
			delete fe;
		}
		lineNumber++;
	}
    file.close();
	return res;
}

void	BitcoinExchange::processInputFile(fileMeta data)
{
	std::ifstream	file(data.filename);
    if (!file.is_open()) {
		throw FailedToOpenFileException() ;
    }

    std::string	line;
	int			lineNumber = 1;

    while (std::getline(file, line))
	{
		if (lineNumber == 1) {
			try {
				getDelimiter(line, data);
			}
			catch(const std::exception& e) {
				throw ;
			}
			lineNumber++;
			continue;
		}

		fileElements *fe = validateLine(data, line, lineNumber);
		if (fe) {
			printResult(fe->date, fe->value);
			delete fe;
		}
		lineNumber++;
	}

    file.close();
}

void	BitcoinExchange::printResult(dateFormat date, float value)
{
	std::map<std::string, float>::const_iterator	closest_date;

	for (std::map<std::string, float>::const_iterator it = database.begin(); it != database.end(); ++it) 
	{
		std::string itYear = it->first.substr(0, 4);
		std::string itMon = it->first.substr(5, 2);
		std::string itDate = it->first.substr(8, 2);
        if (itYear < date.year){
			closest_date = it;
			continue ;
		}
		if (itYear > date.year)
			break ;
		if (itMon < date.mon){
			closest_date = it;
			continue ;
		}
		if (itMon > date.mon)
			break ;
		if (itDate < date.date) {
			closest_date = it;
			continue ;
		}
		if (itDate > date.date)
			break ;
		if (itDate == date.date) {
			closest_date = it;
			break ;
		}
    }

	float result = closest_date->second * value;
	std::cout << BLUE << "[" << date.str << "]" RESET << " => " << value << " = " << GREEN << result << RESET
		<< " (taken from " << YELLOW << closest_date->first << RESET 
		<< " rate " << YELLOW << closest_date->second << RESET << ")" << std::endl;
}

fileElements	*BitcoinExchange::validateLine(fileMeta data, std::string line, int lineNumber)
{
	fileElements	*fe = new fileElements();
	bool	valid = true;
	size_t delimiterPos = line.find(data.delimiter);

	if (delimiterPos == std::string::npos)
		logError(data.filename, "delimiter", data.delimiter, lineNumber);
	else
	{
		fe->date.str = line.substr(0, delimiterPos);
		std::string valueStr = line.substr(delimiterPos + data.delimiter.size());
		try {
			fe->value = std::stof(valueStr);
		} catch(const std::exception& e) {
			logError(data.filename, data.header2, valueStr, lineNumber);
			valid = false;
		}
		if (data.limitValue && !checkValue(fe->value))
		{
			logError(data.filename, data.header2, valueStr, lineNumber);
			valid = false;
		}
		if (!checkDate(fe->date))
		{
			logError(data.filename, data.header1, fe->date.str, lineNumber);
			valid = false;
		}
		
		if (valid)
			return fe;
	}
	delete fe;
	return nullptr;
}

fileMeta BitcoinExchange::createMetaData(std::string filename, std::string header1, std::string header2, bool limitValue)
{
	fileMeta	newMeta;

	newMeta.filename = filename;
	newMeta.header1 = header1;
	newMeta.header2 = header2;
	newMeta.limitValue = limitValue;

	return newMeta;
}

void	BitcoinExchange::getDelimiter(std::string line, fileMeta &data)
{
	size_t pos1 = line.find(data.header1);
	size_t pos2 = line.find(data.header2);

    if (pos1 == std::string::npos || pos2 == std::string::npos || pos2 <= pos1 + data.header1.size() || pos2 < pos1) {
        throw WrongHeaderException();
    }

	size_t delimStart = pos1 + data.header1.size();
    size_t delimLen = pos2 - delimStart;
	data.delimiter = line.substr(delimStart, delimLen);
}

bool	BitcoinExchange::checkValue(float value)
{
	if (value < 0 || value > 1000)
		return false;
	return true;
}

bool	BitcoinExchange::checkDate(dateFormat &date)
{
	if (date.str.size() != 10)
		return false;
	if (date.str[4] != '-' || date.str[7] != '-')
		return false;

	date.year = date.str.substr(0, 4);
	date.mon = date.str.substr(5, 2);
	date.date = date.str.substr(8, 2);
	int monInt = std::stoi(date.mon);
	int dateInt = std::stoi(date.date);
	int yearInt = std::stoi(date.year);

	std::string	element[3] = {date.year, date.mon, date.date};
	for (int i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < element[i].size(); ++j)
		{
			if (!std::isdigit(element[i][j]))
				return false;
		}
	}

	int thirtyDays[4] = {4, 6, 9, 11};
	int febDay = 28;
	if (yearInt % 4 == 0 && (yearInt % 100 != 0 || yearInt % 400 == 0))
		febDay = 29;

	if (monInt < 1 || monInt > 12)
		return false;
	if (dateInt < 1 || dateInt > 31)
		return false;
	if (monInt == 2 && dateInt > febDay)
		return false;

    int* it = std::find(thirtyDays, thirtyDays + 4, monInt);
    if (it != thirtyDays + 4) {
        if (dateInt > 30)
			return false;
    }

	return true;
}

void	BitcoinExchange::logError(std::string filename, std::string type, std::string typeValue, int lineNumber)
{
	std::string problem = "invalid";

	if (type == "delimiter")
		problem = "missing";

	std::cerr << RED << "Error ["
		<< MAGENTA << filename
		<< RED << "] : " << problem << " " << type << " \'"
		<< MAGENTA << typeValue
		<< RED << "\' on line \'"
		<< MAGENTA << lineNumber 
		<< RED << "\'" << RESET << std::endl;
}

const char* BitcoinExchange::FailedToOpenFileException::what() const throw()
{
	return ("Error: could not open file");
}

const char* BitcoinExchange::WrongHeaderException::what() const throw()
{
	return ("Error: wrong header in file");
}
