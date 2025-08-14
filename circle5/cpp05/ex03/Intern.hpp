#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern();
		~Intern();

		Intern(const Intern& other);
		
		AForm*	makeForm(std::string name, std::string target);
		
		class InvalidFormType : public std::exception
		{
			public:
			const char* what() const _NOEXCEPT;
		};
		
	private:
		Intern&		operator=(const Intern &other);
		AForm*		makeShrubberyForm(const std::string& target);
		AForm*		makeRobotomyForm(const std::string& target);
		AForm*		makePresidentialForm(const std::string& target);
		std::string	strToLower(const std::string& str);
};

#endif