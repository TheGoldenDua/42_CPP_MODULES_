/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:38:32 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/09 16:39:40 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
   
    ScavTrap scav("scav");

    
    scav.attack("Target");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate(); 

   
    scav.attack("Target");
    scav.takeDamage(100); 
    scav.beRepaired(20); 

    return 0;
}
