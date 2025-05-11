#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called." << std::endl;
    this->type = "Cat";
    this->_brain = new Brain;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) 
{
    std::cout << "Cat copy assignement operator called." << std::endl;
    if(this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called." << std::endl;
    delete _brain;
}

void Cat::makeSound() const
{
    std::cout << "Cat meows" << std::endl;
}