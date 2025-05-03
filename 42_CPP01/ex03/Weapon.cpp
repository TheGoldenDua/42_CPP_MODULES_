/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:52:05 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/03 00:52:06 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type)
{
    setType(type);
}

void Weapon::setType(std::string type)
{
    _type = type;
}

const std::string &Weapon::getType() const
{
    return (_type);
}
