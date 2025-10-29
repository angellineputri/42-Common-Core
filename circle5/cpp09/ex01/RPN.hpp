#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <map>
#include <algorithm>
#include <stack>
#include <sstream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

class	RPN
{
	public:
		RPN(std::string expression);
		~RPN();

		RPN(const RPN& other);
		RPN&		operator=(const RPN &other);

	private:
		std::stack<int>	st;
	
		int			calculate(std::string sign);
		bool		isNumber(std::string n);
		bool		isOperator(std::string n);

		std::string	ft_to_string(int n);

		class InvalidStackSizeException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif