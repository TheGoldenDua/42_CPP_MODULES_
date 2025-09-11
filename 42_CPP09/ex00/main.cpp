/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:12:28 by del-ganb          #+#    #+#             */
/*   Updated: 2025/09/11 14:12:29 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "Error: could not open file!" << std::endl;
        return (1);
    }

    BitcoinExchange btc("data.csv");
    btc.processInputFile(av[1]);
    return 0;
}
