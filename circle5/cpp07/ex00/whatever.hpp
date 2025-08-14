/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:47:31 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 16:47:32 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
#include <iostream>

template <typename type>
void    swap(type &a, type &b)
{
    type c = a;
    a = b;
    b = c;
}

template <typename type>
type    max(type a, type b)
{
    if (a > b)
        return a;
    else
        return b;
}

template <typename type>
type    min(type a, type b)
{
    if (a < b)
        return a;
    else
        return b;
}

#endif
