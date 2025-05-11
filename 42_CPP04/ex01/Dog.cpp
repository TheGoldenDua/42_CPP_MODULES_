#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called." << std::endl;
    this->type = "Dog";
    this->_brain = new Brain;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignement operator called." << std::endl;
    if(this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called." << std::endl;
    delete _brain;
}

void Dog::makeSound() const
{
    std::cout << "Dog barks" << std::endl;
}