/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:39:46 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 15:39:47 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << GREEN << "Intern default constructor called" << RESET << std::endl;
}

Intern::~Intern()
{
	std::cout << RED << "Intern destructor called" << RESET << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << BLUE << "Intern copy constructor called" << RESET << std::endl;
	(void)other;
}

Intern&	Intern::operator=(const Intern &other)
{
	std::cout << BLUE << "Intern copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		return (*this);
	}
	return (*this);
}

AForm*	Intern::makeShrubberyForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomyForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePresidentialForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	name = strToLower(name);
	AForm*		(Intern::*action[3])(const std::string& target) = {
		&Intern::makeShrubberyForm,
		&Intern::makeRobotomyForm,
		&Intern::makePresidentialForm
	};

	std::string	formType[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	while (i < 3)
	{
		if (name == formType[i])
		{
			try
			{
				std::cout << "Intern creates \'" << name << "\' form" << std::endl;
				AForm*	newForm = (this->*action[i])(target);
				return (newForm);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
				throw ;
			}
		}
		i++;
	}

	throw InvalidFormType();
}

const char* Intern::InvalidFormType::what() const throw()
{
	return ("Invalid form type!");
}

std::string	Intern::strToLower(const std::string& str)
{
	std::string result = str;

	for (size_t i = 0; i < result.size(); ++i) {
		result[i] = std::tolower(static_cast<unsigned char>(result[i]));
	}
	return (result);
}
