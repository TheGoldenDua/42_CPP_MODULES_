/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:52:54 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/03 00:52:55 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if(N <= 0)  
        return NULL;

    Zombie * horde = new Zombie[N];
    int i = 0;
    while(i < N)
    {
        horde[i].setName(name);
        i++;
    }
    return horde;

}
