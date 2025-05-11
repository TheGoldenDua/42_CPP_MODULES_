#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
    std::cout << "Animal default constructor called." << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor called." << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignement operator called." << std::endl;
    if(this != &other)
        this->type = other.getType();
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called." << std::endl;
}

std::string Animal::getType(void) const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Animal makes a sound" << std::endl;
}