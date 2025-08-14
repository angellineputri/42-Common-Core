/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:40:01 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 15:40:01 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <math.h>
#include "AForm.hpp"

class	RobotomyRequestForm : virtual public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string _target);
		~RobotomyRequestForm();

		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm&		operator=(const RobotomyRequestForm &other);

		const std::string	getTarget() const;
		void				executeAction(Bureaucrat const & executor) const;

	private:
		const std::string	target;
};

std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm& robotomyRequestForm);

#endif