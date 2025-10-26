/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:44:42 by aputri-a          #+#    #+#             */
/*   Updated: 2025/10/26 15:00:33 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void    identify(Base* p)
{
    std::cout << "Address \'" << MAGENTA << p << RESET << "\' points to the object \'" << MAGENTA;
    if (dynamic_cast<A*>(p))
        std::cout << "A";
    else if (dynamic_cast<B*>(p))
        std::cout << "B";
    else if (dynamic_cast<C*>(p))
        std::cout << "C";
    else
        std::cout << "Unknown";
     std::cout << RESET << "\'" << std::endl;
}

void    identify(Base& p)
{
    std::cout << "Address \'" << MAGENTA << &p << RESET << "\' points to the object \'" << MAGENTA;

    try
    {
        Base &new_p = dynamic_cast<A&>(p);
        (void)new_p;
        std::cout << "A" << RESET << "\'" << std::endl;
        return ;
    }
    catch(const std::exception& e){}

    try
    {
        Base &new_p = dynamic_cast<B&>(p);
        (void)new_p;
        std::cout << "B" << RESET << "\'" << std::endl;
        return ;
    }
    catch(const std::exception& e){}

    try
    {
        Base &new_p = dynamic_cast<C&>(p);
        (void)new_p;
        std::cout << "C" << RESET << "\'" << std::endl;
        return ;
    }
    catch(const std::exception& e){}
}
