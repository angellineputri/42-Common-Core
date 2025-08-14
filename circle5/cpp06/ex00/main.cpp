/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:44:04 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 16:45:21 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED << "Error: Wrong argument call!" << std::endl
            << "./convert [arg]" << RESET << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}
