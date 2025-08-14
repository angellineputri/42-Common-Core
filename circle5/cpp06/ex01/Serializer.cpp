/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:44:23 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 16:44:24 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << GREEN << "Serializer default constructor called" << RESET << std::endl;
}

Serializer::~Serializer()
{
	std::cout << RED << "Serializer destructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
	std::cout << BLUE << "Serializer copy constructor called" << RESET << std::endl;
    (void)other;
}

Serializer&	Serializer::operator=(const Serializer& other)
{
	std::cout << BLUE << "Serializer copy assignment operator called" << RESET << std::endl;
	if (this != &other)
    {
        return (*this);
    }
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

