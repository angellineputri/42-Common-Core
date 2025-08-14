#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "ScalarConverter default constructor called" << RESET << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "ScalarConverter destructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	std::cout << BLUE << "ScalarConverter copy constructor called" << RESET << std::endl;
    (void)other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	std::cout << BLUE << "ScalarConverter copy assignment operator called" << RESET << std::endl;
	if (this != &other)
    {
        return (*this);
    }
	return (*this);
}

bool    ScalarConverter::isCharLiteral(const std::string& input)
{
    return (input.size() == 3 && input[0] == '\'' && input [2] == '\'');
}

bool    ScalarConverter::isIntLiteral(const std::string& input)
{
    int sign = 0;

    if (input.empty())
        return (false);
    if (input[0] == '-' || input[0] == '+')
        sign = 1;
    for (size_t i = 0 + sign; i < input.size(); ++i)
    {
        if (!isdigit(input[i]))
            return (false);
    }
    return (true);
}

bool    ScalarConverter::isFloatLiteral(const std::string& input)
{
    size_t sign = 0;
    int pt = 1;
    int f = 0;

    if (ScalarConverter::isFloatPseudoLiteral(input))
        return (true);
    if (input.empty())
        return (false);
    if (input[0] == '-' || input[0] == '+')
        sign = 1;
    for (size_t i = 0 + sign; i < input.size(); ++i)
    {
        if (input[i] == '.' && i != 0 + sign && i != input.size() - 1 && pt)
            pt = 0;
        else if (input[i] == 'f' && i != input.size() - 1)
            return (false);
        else if (input[i] == 'f' && i == input.size() - 1)
            f++;
        else if (!isdigit(input[i]))
            return (false);
    }
    if (f != 1 || pt == 1)
        return (false);
    return (true);
}

bool    ScalarConverter::isDoubleLiteral(const std::string& input)
{
    size_t sign = 0;
    int pt = 1;

    if (ScalarConverter::isDoublePseudoLiteral(input))
        return (true);
    if (input.empty())
        return (false);
    if (input[0] == '-' || input[0] == '+')
        sign = 1;
    for (size_t i = 0 + sign; i < input.size(); ++i)
    {
        if (input[i] == '.' && i != 0 + sign && i != input.size() - 1 && pt)
            pt = 0;
        else if (!isdigit(input[i]))
            return (false);
    }
    return (true);
}

bool ScalarConverter::isFloatPseudoLiteral(const std::string& input)
{
    if (input.empty())
        return (false);
    return (input == "nanf" || input == "+inff" || input == "-inff");
}

bool ScalarConverter::isDoublePseudoLiteral(const std::string& input)
{
    if (input.empty())
        return (false);
    return (input == "nan" || input == "+inf" || input == "-inf");
}

void    ScalarConverter::convertFromCharLiteral(const std::string& input)
{
    std::string	type[4] = {"char: ", "int: ", "float: ", "double: "};
    char base = input[1];
    for (int i = 0; i < 4; ++i)
    {
        std::cout << type[i];
        try
        {
            if (i == 0 && !std::isprint(base))
                throw ScalarConverter::NonDisplayableCharLiteral();
            else if (i == 0)
                std::cout << base;
            else if (i == 1)
                std::cout << static_cast<int>(base);
            else if (i == 2)
                std::cout << std::fixed << std::setprecision(1) << static_cast<float>(base) << "f";
            else
                std::cout << std::fixed << std::setprecision(1) << static_cast<double>(base);
        }
        catch(const ScalarConverter::NonDisplayableCharLiteral&)
        {
            std::cout << "non displayable";
        }
        catch(const std::exception& e)
        {
            std::cout << "impossible";
        }
        std::cout << std::endl;
    }
}

void    ScalarConverter::convertFromIntLiteral(const std::string& input)
{
    std::string	type[4] = {"char: ", "int: ", "float: ", "double: "};
    int base = std::stoi(input);
    char c = static_cast<char>(base);
    for (int i = 0; i < 4; ++i)
    {
        std::cout << type[i];
        try
        {
            if (i == 0 && (base < 0 || base > 127))
                throw ScalarConverter::ImpossibleConvertion();
            else if (i == 0 && !std::isprint(c))
                throw ScalarConverter::NonDisplayableCharLiteral();
            else if (i == 0)
                std::cout << c;
            else if (i == 1)
                std::cout << base;
            else if (i == 2)
                std::cout << std::fixed << std::setprecision(1) << static_cast<float>(base) << "f";
            else
                std::cout << std::fixed << std::setprecision(1) << static_cast<double>(base);
        }
        catch(const ScalarConverter::NonDisplayableCharLiteral&)
        {
            std::cout << "non displayable";
        }
        catch(const std::exception& e)
        {
            std::cout << "impossible";
        }
        std::cout << std::endl;
    }
}

void    ScalarConverter::convertFromFloatLiteral(const std::string& input)
{
    std::string	type[4] = {"char: ", "int: ", "float: ", "double: "};
    float base = std::stof(input);
    char c = static_cast<char>(base);
    int integer = static_cast<int>(base);
    for (int i = 0; i < 4; ++i)
    {
        std::cout << type[i];
        try
        {
            if (ScalarConverter::isFloatPseudoLiteral(input) && (i == 0 || i == 1))
                throw ScalarConverter::ImpossibleConvertion();
            else if (i == 0 && (integer < 0 || integer > 127))
                throw ScalarConverter::ImpossibleConvertion();
            else if (i == 0 && !std::isprint(c))
                throw ScalarConverter::NonDisplayableCharLiteral();
            else if (i == 0)
                std::cout << c;
            else if (i == 1)
                std::cout << integer;
            else if (i == 2)
                std::cout << std::fixed << std::setprecision(ScalarConverter::getPrecision(input)) << base << "f";
            else
                std::cout << std::fixed << std::setprecision(ScalarConverter::getPrecision(input)) << static_cast<double>(base);
        }
        catch(const ScalarConverter::NonDisplayableCharLiteral&)
        {
            std::cout << "non displayable";
        }
        catch(const std::exception& e)
        {
            std::cout << "impossible";
        }
        std::cout << std::endl;
    }
}

void    ScalarConverter::convertFromDoubleLiteral(const std::string& input)
{
    std::string	type[4] = {"char: ", "int: ", "float: ", "double: "};
    double base = std::stod(input);
    char c = static_cast<char>(base);
    int integer = static_cast<int>(base);
    for (int i = 0; i < 4; ++i)
    {
        std::cout << type[i];
        try
        {
            if (ScalarConverter::isDoublePseudoLiteral(input) && (i == 0 || i == 1))
                throw ScalarConverter::ImpossibleConvertion();
            else if (i == 0 && (integer < 0 || integer > 127))
                throw ScalarConverter::ImpossibleConvertion();
            else if (i == 0 && !std::isprint(c))
                throw ScalarConverter::NonDisplayableCharLiteral();
            else if (i == 0)
                std::cout << c;
            else if (i == 1)
                std::cout << integer;
            else if (i == 2)
                std::cout << std::fixed << std::setprecision(ScalarConverter::getPrecision(input)) << static_cast<float>(base) << "f";
            else
                std::cout << std::fixed << std::setprecision(ScalarConverter::getPrecision(input)) << base;
        }
        catch(const ScalarConverter::NonDisplayableCharLiteral&)
        {
            std::cout << "non displayable";
        }
        catch(const std::exception& e)
        {
            std::cout << "impossible";
        }
        std::cout << std::endl;
    }
}

int ScalarConverter::getPrecision(const std::string& input)
{
    int pt = 1;
    int precision = 0;

    if (ScalarConverter::isFloatPseudoLiteral(input) || ScalarConverter::isDoublePseudoLiteral(input))
        return (0);
    for (size_t i = 0; i < input.size(); ++i)
    {
        if (input[i] == '.')
            pt = 0;
        else if (pt == 0 && input[i] != 'f')
            precision++;
    }
    if (precision > 7)
        return (7);
    return (precision);
}

void	ScalarConverter::convert(const std::string& input)
{
    std::string	label[4] = {"char: ", "int: ", "float: ", "double: "};
	bool		(*type[4])(const std::string& input) = {
		&ScalarConverter::isCharLiteral,
		&ScalarConverter::isIntLiteral,
		&ScalarConverter::isFloatLiteral,
        &ScalarConverter::isDoubleLiteral
	};

    void		(*action[4])(const std::string& input) = {
		&ScalarConverter::convertFromCharLiteral,
		&ScalarConverter::convertFromIntLiteral,
		&ScalarConverter::convertFromFloatLiteral,
        &ScalarConverter::convertFromDoubleLiteral
	};

    for (int i = 0; i < 4; ++i)
    {
        if (type[i](input) == true)
        {
            std::cout << MAGENTA << "The program detects that this is " << RED << label[i] << RESET << std::endl;
            action[i](input);
            return ;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        std::cout << label[i] << "impossible" << std::endl;
    }
}

const char* ScalarConverter::ImpossibleConvertion::what() const _NOEXCEPT
{
	return ("impossible");
}

const char* ScalarConverter::NonDisplayableCharLiteral::what() const _NOEXCEPT
{
	return ("non displayable");
}