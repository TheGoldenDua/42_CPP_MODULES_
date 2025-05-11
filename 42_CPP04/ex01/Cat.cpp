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
    _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) 
{
    std::cout << "Cat copy assignment operator called." << std::endl;
    if(this != &other)
    {    
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
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

void Cat::setIdea(int i, const std::string& idea) {
    if (_brain)
        _brain->setIdea(i, idea);
}

std::string Cat::getIdea(int i) const {
    if (_brain)
        return _brain->getIdea(i);
    return "";
}
