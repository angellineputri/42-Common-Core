/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:39:59 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 15:39:59 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << GREEN << "RobotomyRequestForm target \'" << target << "\' default constructor called (gradeToSign: \'" << getGradeToSign() << "\' & gradeToExecute: \'" << getGradeToExecute() << "\')" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target)
: AForm("RobotomyRequestForm", 72, 45), target(resolveName(_target))
{
	std::cout << GREEN << "RobotomyRequestForm target \'" << target << "\' constructor called (gradeToSign: \'" << getGradeToSign() << "\' & gradeToExecute: \'" << getGradeToExecute() << "\')" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm target \'" << target << "\' destructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), target(other.target)
{
	std::cout << BLUE << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << BLUE << "RobotomyRequestForm copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

const std::string	RobotomyRequestForm::getTarget() const
{
	return (target);
}

void	RobotomyRequestForm::executeAction(Bureaucrat const & executor) const
{
	int robotomized = rand() % 2;

	std::cout << "Bureaucrat " << executor.getName() << " will now try to robotomize " << target << "!" << std::endl;
	std::cout << "* drilling noises *" << std::endl;
	if (robotomized)
		std::cout << "Target \"" << target << "\" has been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm& robotomyRequestForm)
{
	out << static_cast<const AForm&>(robotomyRequestForm);
	out << ", target: " << robotomyRequestForm.getTarget();
	return (out);
}
