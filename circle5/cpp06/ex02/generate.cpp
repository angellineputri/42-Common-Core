/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:44:39 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 16:44:40 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base    *generate(void)
{
    int i = rand() % 3;
    Base *p;

    std::cout << "Address \'";
    switch (i)
    {
        case 0:
            p = new A();
            std::cout << MAGENTA << p << RESET << "\':" << MAGENTA << " Generating object A" << RESET << std::endl;
            return (p);
        case 1:
            p = new B();
            std::cout << MAGENTA << p << RESET << "\':" << MAGENTA << " Generating object B" << RESET << std::endl;
            return (p);
        default:
            p = new C();
            std::cout << MAGENTA << p << RESET << "\'" << MAGENTA << " Generating object C" << RESET << std::endl;
            return (p);
    }
}
