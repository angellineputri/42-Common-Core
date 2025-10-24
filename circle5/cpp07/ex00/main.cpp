/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:47:26 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 16:47:28 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

int main()
{
    int a = 2;
    int b = 3;
    std::cout << BLUE << "[1] Test swap function for int" << RESET << std::endl;
    std::cout << MAGENTA << "before: " << RESET << "a = " << a << ", b = " << b << std::endl;
    ::swap( a, b );
    std::cout << MAGENTA << "after : " << RESET << "a = " << a << ", b = " << b << std::endl << std::endl;

    std::cout << BLUE << "[2] Test min and max function for int" << RESET << std::endl;
    std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
    std::cout << "max(a, b) = " << ::max( a, b ) << std::endl << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << BLUE << "[3] Test swap function for str" << RESET << std::endl;
    std::cout << MAGENTA << "before: " << RESET << "c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << MAGENTA << "after : " << RESET << "c = " << c << ", d = " << d << std::endl << std::endl;

    std::cout << BLUE << "[4] Test min and max function for str" << RESET << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    // int e = 6;
    // std::string f = "chaine3";
    // std::cout << BLUE << "[5] Test swap function for str with int" << RESET << std::endl;
    // std::cout << MAGENTA << "before: " << RESET << "e = " << e << ", f = " << f << std::endl;
    // ::swap(e, f);
    // std::cout << MAGENTA << "after : " << RESET << "e = " << e << ", f = " << f << std::endl << std::endl;

    // std::cout << BLUE << "[6] Test min and max function for str" << RESET << std::endl;
    // std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
    // std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
    return (0);
}
