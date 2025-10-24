/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:44:15 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 16:44:15 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <exception>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

class	ScalarConverter
{
	public:
		static void	convert(const std::string& input);
	
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter &other);
		
		static bool	isCharLiteral(const std::string& input);
		static bool isIntLiteral(const std::string& input);
		static bool isFloatLiteral(const std::string& input);
		static bool isDoubleLiteral(const std::string& input);
		static bool isFloatPseudoLiteral(const std::string& str);
		static bool isDoublePseudoLiteral(const std::string& str);

		static void	convertFromCharLiteral(const std::string& input);
		static void convertFromIntLiteral(const std::string& input);
		static void convertFromFloatLiteral(const std::string& input);
		static void convertFromDoubleLiteral(const std::string& input);

		static int	getPrecision(const std::string& input);

		class ImpossibleConvertion : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NonDisplayableCharLiteral : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif