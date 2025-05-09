/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:39:03 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/09 16:39:23 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() 
{
    FragTrap Frag("Frag");

    
    Frag.attack("Target");
    Frag.takeDamage(30);
    Frag.beRepaired(10);
    Frag.highFivesGuys(); 

   
    Frag.attack("Target");
    Frag.takeDamage(100); 
    Frag.beRepaired(20); 
    

    return 0;
}
