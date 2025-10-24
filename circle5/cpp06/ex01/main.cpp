/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:44:20 by aputri-a          #+#    #+#             */
/*   Updated: 2025/08/14 16:44:21 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data    original;
    original.name = "kitty";
    original.fav_number = 42;

    uintptr_t   raw = Serializer::serialize(&original);
    Data*   deserialized = Serializer::deserialize(raw);

    std::cout << MAGENTA << std::endl << "/// original, serialized, and deserialized address/values /// " << RESET << std::endl;
    std::cout << "original pointer: " << &original << std::endl;
    std::cout << "serialized uintptr_t: " << raw << std::endl;
    std::cout << "deserialized pointer: " << deserialized << std::endl;

    std::cout << MAGENTA << std::endl << "/// comparison of the data /// " << RESET << std::endl;
    std::cout << "original data: " << std::endl
        << "name: " << original.name << std::endl
        << "fav number: " << original.fav_number << std::endl
        << "address: " << &original << std::endl << std::endl;

    std::cout << "deserialized data: " << std::endl
        << "name: " << deserialized->name << std::endl
        << "fav number: " << deserialized->fav_number << std::endl
        << "address: " << deserialized << std::endl;

    return (0);
}

