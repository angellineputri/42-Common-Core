/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:37:07 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 15:37:07 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test_form()
{
	std::cout << MAGENTA << std::endl << "[1] Check form construction" << RESET << std::endl;
	Form* form[5];
	int gradeSignArr[5] = {1, 70, -1, 1, 151};
	int gradeExecuteArr[5] = {1, 70, 1, -1, 151};

	for (int i = 0; i < 5; ++i)
	{
		form[i] = NULL;
		try
		{
			if (i == 1)
				form[i] = new Form("", gradeSignArr[i], gradeExecuteArr[i]);
			else
				form[i] = new Form("formname", gradeSignArr[i], gradeExecuteArr[i]);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
			form[i] = NULL;
		}
	}

	std::cout << MAGENTA << std::endl << "printing form with the << operator" << RESET << std::endl;
	for (int i = 0; i < 2; ++i)
	{
		if (form[i] != NULL)
			std::cout << *form[i] << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < 5; ++i)
	{
		if (form[i])
			delete form[i];
	}
}

void test_sign()
{
	std::cout << MAGENTA << std::endl << "/// preparing bureaucrat and form ///" << RESET << std::endl;
	Bureaucrat* worstBureau = new Bureaucrat("worst", 150);
	Bureaucrat* bestBureau = new Bureaucrat("best", 2);
	Form* minorForm = new Form("minor", 149, 150);
	Form* importantForm = new Form("important", 3, 1);

	std::cout << MAGENTA << std::endl << "/// Form sign status ///" << RESET << std::endl;
	std::cout << *minorForm << std::endl;
	std::cout << *importantForm << std::endl;

	std::cout << MAGENTA << std::endl << "[2] Check that incompetent bureaucrat can't sign " << RESET << std::endl;
	worstBureau->signForm(*importantForm);
	worstBureau->signForm(*minorForm);

	std::cout << MAGENTA << std::endl << "/// Form sign status ///" << RESET << std::endl;
	std::cout << *minorForm << std::endl;
	std::cout << *importantForm << std::endl;

	std::cout << MAGENTA << std::endl << "[3] Check that competent bureaucrat can sign " << RESET << std::endl;
	bestBureau->signForm(*importantForm);
	bestBureau->signForm(*minorForm);

	std::cout << MAGENTA << std::endl << "/// Form sign status ///" << RESET << std::endl;
	std::cout << *minorForm << std::endl;
	std::cout << *importantForm << std::endl;

	std::cout << MAGENTA << std::endl << "[3] Check that competent bureaucrat can't sign a signed form" << RESET << std::endl;
	bestBureau->signForm(*importantForm);
	bestBureau->signForm(*minorForm);

	std::cout << MAGENTA << std::endl << "/// Form sign status ///" << RESET << std::endl;
	std::cout << *minorForm << std::endl;
	std::cout << *importantForm << std::endl;

	std::cout << std::endl;
	delete bestBureau;
	delete worstBureau;
	delete importantForm;
	delete minorForm;
}

int	main()
{
	test_form();
	test_sign();
	return(0);
}
