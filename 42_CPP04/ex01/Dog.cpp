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
    _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called." << std::endl;
    if(this != &other)
    {    
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
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

void Dog::setIdea(int i, const std::string& idea) {
    if (_brain)
        _brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const {
    if (_brain)
        return _brain->getIdea(i);
    return "";
}
