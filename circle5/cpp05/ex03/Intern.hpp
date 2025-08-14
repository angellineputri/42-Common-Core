/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:39:49 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 15:39:50 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			const char* what() const throw();
		};
		
	private:
		Intern&		operator=(const Intern &other);
		AForm*		makeShrubberyForm(const std::string& target);
		AForm*		makeRobotomyForm(const std::string& target);
		AForm*		makePresidentialForm(const std::string& target);
		std::string	strToLower(const std::string& str);
};

#endif