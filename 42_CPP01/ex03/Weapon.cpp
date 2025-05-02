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


