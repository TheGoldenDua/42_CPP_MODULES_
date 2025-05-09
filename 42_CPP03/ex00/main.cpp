/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:38:14 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/09 16:38:15 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ClapTrap.hpp"

int main()
{
    ClapTrap dua("Dua");
    ClapTrap Sou("Sou");

    dua.attack("Sou");
    dua.takeDamage(5);
    dua.beRepaired(10);

    dua.attack("Sou");
    dua.takeDamage(10);
}
