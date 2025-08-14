/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:35:39 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 15:35:39 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Bureaucrat.hpp"

void	test_bureaucrat_constructor()
{
	std::cout << MAGENTA << std::endl << "[1] Check bureaucrat construction" << RESET << std::endl;
	Bureaucrat* bureau[8];

	int gradeArr[8] = {1, 2, 149, 150, 70, 151, 0, -1};
	for (int i = 0; i < 8; ++i)
	{
		bureau[i] = NULL;
		try
		{
			if (i == 4)
				bureau[i] = new Bureaucrat("", gradeArr[i]);
			else
				bureau[i] = new Bureaucrat("hello", gradeArr[i]);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
			bureau[i] = NULL;
		}
	}

	std::cout << MAGENTA << std::endl << "printing bureaucrat with the << operator" << RESET << std::endl;
	for (int i = 0; i < 8; ++i)
	{
		if (bureau[i])
			std::cout << *bureau[i] << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < 8; ++i)
	{
		if (bureau[i])
			delete bureau[i];
	}
}

void	test_grade_functions()
{
	std::cout << MAGENTA << std::endl << "/// preparing bureaucrat ///" << RESET << std::endl;
	Bureaucrat* bureau[4];

	int gradeArr[4] = {1, 70, 150, 150};
	for (int i = 0; i < 4; ++i)
	{
		bureau[i] = NULL;
		try
		{
			bureau[i] = new Bureaucrat("hello", gradeArr[i]);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
			bureau[i] = NULL;
		}
	}

	std::cout << MAGENTA << std::endl << "[2] Checking incrementGrade()" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "before: " << *bureau[i] << std::endl;
		try
		{
			bureau[i]->incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		}
		std::cout << "after: " << *bureau[i] << std::endl << std::endl;
	}

	std::cout << MAGENTA << "[2] Checking decrementGrade()" << RESET << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "before: " << *bureau[i] << std::endl;
		try
		{
			bureau[i]->decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		}
		std::cout << "after: " << *bureau[i] << std::endl << std::endl;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (bureau[i])
			delete bureau[i];
	}
}

int	main()
{
	test_bureaucrat_constructor();
	test_grade_functions();
	return (0);
}
