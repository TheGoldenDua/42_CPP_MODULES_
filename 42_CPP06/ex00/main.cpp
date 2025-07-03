/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:12:47 by del-ganb          #+#    #+#             */
/*   Updated: 2025/07/03 12:12:48 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cout << "--------------Error---------------\n" 
                  << " Usage: ./Convert <literal>"
                  << std::endl;
        return 1;
    }

    ScalarConverter::convert(av[1]);

    return 0;
}
