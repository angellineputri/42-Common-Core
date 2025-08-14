/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:37:35 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 15:37:36 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm	**test_form_constructors()
{
	std::cout << MAGENTA << std::endl << "[1] Check all forms construction" << RESET << std::endl;
	AForm** form = new AForm*[3];
	std::string	target[3] = {"targetS", "targetR", ""};
	
	for (int i = 0; i < 3; ++i)
	{
		form[i] = NULL;
		try
		{
			switch (i)
			{
				case 0:
					form[i] = new ShrubberyCreationForm(target[i]);
					break ;
				case 1:
					form[i] = new RobotomyRequestForm(target[i]);
					break ;
				case 2:
					form[i] = new PresidentialPardonForm(target[i]);
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
			form[i] = NULL;
		}
	}

	std::cout << MAGENTA << std::endl << "printing form with the << operator" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		if (form[i])
			std::cout << *form[i] << std::endl;
	}

	return (form);
}

void test_form_sign_and_execute(AForm **form)
{
	std::cout << MAGENTA << std::endl << "/// preparing bureaucrat ///" << RESET << std::endl;
	Bureaucrat* worstBureau = new Bureaucrat("worst", 150);
	Bureaucrat* bestBureau = new Bureaucrat("best", 1);

	std::cout << MAGENTA << std::endl << "[2] Check whether forms can be executed without being signed" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		bestBureau->executeForm(*form[i]);
	}

	std::cout << MAGENTA << std::endl << "/// sign all forms ///" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		bestBureau->signForm(*form[i]);
	}

	std::cout << MAGENTA << std::endl << "[3] Check whether forms can be executed by an competent bureaucrat" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		worstBureau->executeForm(*form[i]);
	}

	std::cout << MAGENTA << std::endl << "[4] Check whether forms can be executed by a competent bureaucrat" << RESET << std::endl;
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
	AForm **form = test_form_constructors();
	test_form_sign_and_execute(form);
	clean_up(form, 3);
	return (0);
}
