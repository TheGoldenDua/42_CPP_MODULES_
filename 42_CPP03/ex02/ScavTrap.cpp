/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:39:10 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/09 16:39:11 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("DefaultName") 
{
    std::cout << "ScavTrap default constructor called." << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap parameterized constructor called." << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap& other):ClapTrap(other)
{
    std::cout << "ScavTrap Copy Constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap Assignation operator called." << std::endl;
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(this->_hitPoints > 0 && this->_energyPoints >= 1)
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " 
                  << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;        
    }
    else
    {
        std::cout << "ScavTrap " << this->_name << " can't attack " << target 
                  << " due to insufficient hit points or energy." << std::endl;
    }
}

void ScavTrap::guardGate(void) const
{
    std::cout << "ScavTrap" << this->_name << "has entered Gate Keeper mode!" << std::endl;
}
