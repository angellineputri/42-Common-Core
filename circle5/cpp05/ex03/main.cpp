/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:39:52 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 15:39:52 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

AForm	**test_intern()
{
	std::cout << MAGENTA << std::endl << "[1] Check intern constructor" << RESET << std::endl;
	Intern* intern = new Intern();
	std::string formType[5] = {"shrubbery creation", "ROBOTOMY REQUEST", "PreSidENtiAL pARDon", "PRESIDENTIAL PARD0N", ""};
	AForm** form = new AForm*[5];
	
	std::cout << MAGENTA << std::endl << "[2] check makeForm()" << RESET << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		form[i] = NULL;
		try
		{
			if (i == 1)
				form[i] = intern->makeForm(formType[i], "");
			else
				form[i] = intern->makeForm(formType[i], "target");
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl << std::endl;
			form[i] = NULL;
		}
	}

	std::cout << MAGENTA << std::endl << "printing form with the << operator" << RESET << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		if (form[i])
			std::cout << *form[i] << std::endl;
	}

	delete intern;
	return (form);
}

void test_form_sign_and_execute(AForm **form)
{
	std::cout << MAGENTA << std::endl << "/// preparing bureaucrat ///" << RESET << std::endl;
	Bureaucrat* worstBureau = new Bureaucrat("worst", 150);
	Bureaucrat* bestBureau = new Bureaucrat("best", 1);

	std::cout << MAGENTA << std::endl << "[3] Check whether forms can be executed without being signed" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		bestBureau->executeForm(*form[i]);
	}

	std::cout << MAGENTA << std::endl << "/// sign all forms ///" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		bestBureau->signForm(*form[i]);
	}

	std::cout << MAGENTA << std::endl << "[4] Check whether forms can be executed by an competent bureaucrat" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		worstBureau->executeForm(*form[i]);
	}

	std::cout << MAGENTA << std::endl << "[5] Check whether forms can be executed by a competent bureaucrat" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		bestBureau->executeForm(*form[i]);
		if (i == 1)
		{
			for (int j = 0; j < 5; ++j)
				bestBureau->executeForm(*form[i]);
		}
		std::cout << std::endl;
	}

	delete worstBureau;
	delete bestBureau;
}

void clean_up(AForm** form, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (form[i])
        {
            delete form[i];
            form[i] = NULL;
        }
    }

	delete [] form;
}

int	main()
{
	AForm** form = test_intern();
	test_form_sign_and_execute(form);
	clean_up(form, 5);
	return (0);
}
