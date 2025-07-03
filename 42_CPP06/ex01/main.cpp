/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:11:46 by del-ganb          #+#    #+#             */
/*   Updated: 2025/07/03 12:11:47 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data data;
    data.i = 42;
    data.str = (char *)"42 Network";
    data.c = 'Z';

    uintptr_t raw = Serializer::serialize(&data);

    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "\n----------Address-----------\n" << std::endl;
    std::cout << "Original pointer:     " << &data << std::endl;
    std::cout << "Deserialized pointer: " << deserialized << std::endl;

    std::cout << "\n----------values-----------\n" << std::endl;
    std::cout << "Original values:\n";
    std::cout << " i: " << data.i << "\n str: " << data.str << "\n c: " << data.c << std::endl;

    std::cout << "\nDeserialized values:\n";
    std::cout << " i: " << deserialized->i << "\n str: " << deserialized->str << "\n c: " << deserialized->c << std::endl;

    return 0;
}
