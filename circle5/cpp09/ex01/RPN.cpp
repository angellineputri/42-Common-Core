#include "RPN.hpp"

RPN::RPN(std::string expression)
{
	// std::cout << GREEN << "RPN default constructor called" << RESET << std::endl;
	size_t i = 0;

	while (i < expression.size())
	{
		size_t pos = expression.find(' ', i);
		if (pos == std::string::npos)
			pos = expression.size();
		std::string token = expression.substr(i, pos - i);
		if (pos - i > 1)
		{
			std::cerr << RED << "Error: invalid token found \'" << MAGENTA << token << RED << "\'" << RESET << std::endl;
			return ;
		}
		if (!token.empty())
		{
			if (isNumber(token))
				st.push(std::stoi(token));
			else if (isOperator(token))
			{
				try {
					st.push(calculate(token));
				} catch(const std::exception& e) {
					std::cerr << RED << e.what() << RESET << std::endl;
					return ;
				}
			}
			else
			{
				std::cerr << RED << "Error: invalid token found \'" << MAGENTA << token << RED << "\'" << RESET << std::endl;
				return ;
			}
		}
		i = pos + 1;
	}

	if (st.size() == 1)
		std::cout << BLUE << "result is " << YELLOW << st.top() << std::endl;
	else
		std::cerr << RED << "Error: not enough operators to do calculation." << std::endl;
}

RPN::~RPN()
{
	// std::cout << RED << "RPN destructor called" << RESET << std::endl;
}

RPN::RPN(const RPN& other)
{
	// std::cout << BLUE << "RPN copy constructor called" << RESET << std::endl;
	*this = other;
}

RPN&	RPN::operator=(const RPN &other)
{
	// std::cout << BLUE << "RPN copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

int	RPN::calculate(std::string sign)
{
	std::string types[4] = {"+", "-", "*", "/"};
	int i = 0;

	for (; i < 4; ++i)
	{
		if (sign == types[i])
			break ;
	}

	if (st.size() < 2)
		throw InvalidStackSizeException();

	int	b = st.top();
	st.pop();
	int a = st.top();
	st.pop();
	
	switch (i) {
		case 1:
			return (a - b);

		case 2:
			return (a * b);

		case 3:
			return (a / b);

		default:
			return (a + b);
	}
}

bool	RPN::isNumber(std::string n)
{
	if (isdigit(n[0]))
		return true;
	else
		return false;
}

bool	RPN::isOperator(std::string n)
{
	if (n[0] == '+' || n[0] == '-' || n[0] == '*' || n[0] == '/')
		return true;
	else
		return false;
}

std::string	RPN::ft_to_string(int n)
{
	std::stringstream ss;
	ss << n;
	return ss.str();
}

const char* RPN::InvalidStackSizeException::what() const throw()
{
	return ("Error: not enough numbers to do operation.");
}
