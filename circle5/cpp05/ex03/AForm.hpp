/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:39:39 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 15:40:17 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm();
		AForm(std::string _name, int _gradeToSign, int _gradeToExecute);
		virtual ~AForm();

		AForm(const AForm& other);
		AForm&		operator=(const AForm &other);

		const std::string			getName() const;
		bool						getIsSigned() const;
		int							getGradeToSign() const;
		int							getGradeToExecute() const;
		virtual const std::string	getTarget() const = 0;

		void				beSigned(Bureaucrat& bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const;
		virtual void		executeAction(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class FormIsAlreadySignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		const std::string	name;
		const int			gradeToSign;
		const int			gradeToExecute;
		bool				isSigned;

	protected:
		std::string			resolveName(std::string name);
};

std::ostream&	operator<<(std::ostream& out, const AForm& aForm);

#endif