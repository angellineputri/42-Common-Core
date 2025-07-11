/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:50:45 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/09 12:21:29 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
: type("unknown")
{
	std::cout << GREEN << "AMateria default constructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const& _type)
: type(_type)
{
	std::cout << GREEN << "AMateria type " << _type << " constructor called" << RESET << std::endl;
}

AMateria::~AMateria()
{
	std::cout << RED << "AMateria destructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria& other)
: type(other.type)
{
	std::cout << BLUE << "AMateria copy constructor called" << RESET << std::endl;
}

AMateria&	AMateria::operator=(const AMateria &other)
{
	std::cout << BLUE << "AMateria copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

std::string const&	AMateria::getType() const
{
	return (type);
}

void	AMateria::use(ICharacter& target)
{
	std::string	targetName;

	try
	{
		targetName = target.getName();
	}
	catch(const std::exception& e)
	{
		std::cout << "what am I? who is that? 0.0 (clueless)" << std::endl;
		return ;
	}
	std::cout << "what am I? what am I even supposed to do with " << targetName << " 0.0 (still clueless)" << std::endl;
}


