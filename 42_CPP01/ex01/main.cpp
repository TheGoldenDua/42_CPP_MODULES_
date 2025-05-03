/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:53:11 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/03 00:53:12 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    int count = 5;
    Zombie* horde = zombieHorde(count, "HordeZombie");

    int i = 0;
    while(i < count)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return 0;
}
