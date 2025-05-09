/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:38:48 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/09 16:38:49 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
    std::cout << "Parameterized constructor called." << std::endl;
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if(this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "Copy assignement operator called." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(this->_hitPoints > 0 && this->_energyPoints >= 1)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " 
                  << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;        
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " can't attack " << target 
                  << " due to insufficient hit points or energy." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is already destroyed!"
                  << " can't take more damage." << std::endl;
        
    }
    if (amount >= this->_hitPoints)
    {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " took " << amount << " damage, and now has "
               << this->_hitPoints << " hit points, and is now down!" << std::endl;
    }

    if(amount < this->_hitPoints)
    {
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->_name << " took " << amount << " damage, and now has "
               << this->_hitPoints << " hit points." << std::endl;
    }
    return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->_hitPoints > 0 && this->_energyPoints >= 1)
    {
        this->_hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << this->_name << " repairs itself and gains "
                  << amount << " hit points (now at " << this->_hitPoints << ")." << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->_name 
                  << " can't repair itself - no energy or already destroyed." << std::endl;
    }
}