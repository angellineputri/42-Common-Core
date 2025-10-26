/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:07:45 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 19:07:45 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

template <typename T>
class Array
{
    public:
        Array();
        Array(unsigned int n);
        ~Array();

        Array(const Array& other);
        Array&  operator=(const Array &other);
        T&      operator[](unsigned int i) const;

        unsigned int    size() const;

        class InvalidIndexException : public std::exception
		{
			public:
				const char* what() const throw();
		};

    private:
        unsigned int    capacity;
        T               *arr;
};

#include "Array.tpp"

#endif