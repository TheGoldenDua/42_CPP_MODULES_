#include "ScavTrap.hpp"
#include "ClavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClavTrap("DefaultName") : _hitPoints(100), _energyPoints(50), _attackDamage(20) 
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}

