/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:52:25 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/03 00:52:26 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

static Weapon noWeapon("NO waepon");

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){}

void HumanB::attack()
{
    std::cout << _name << "attacks with their" << (*_weapon).getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}
