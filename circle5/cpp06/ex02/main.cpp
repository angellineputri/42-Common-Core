/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:44:45 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 16:44:45 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base    *generate(void);
void    identify(Base* p);
void    identify(Base& p);

int main()
{
    Base    *inventory[10];

    std::cout << BLUE << std::endl << "/// Generate and identify (ptr) ///" << RESET << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        inventory[i] = generate();
        identify(inventory[i]);
        std::cout << std::endl;
    }

    for (int i = 0; i < 10; ++i)
    {
        delete inventory[i];
    }

    std::cout << BLUE << std::endl << "/// Generate and identify (ref) ///" << RESET << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        inventory[i] = generate();
        identify(*inventory[i]);
        std::cout << std::endl;
    }

    for (int i = 0; i < 10; ++i)
    {
        delete inventory[i];
    }

    return (0);
}

