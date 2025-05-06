#include "Fixed.hpp"

Fixed::Fixed() : fPointval(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed&  Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
        this->fPointval = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->fPointval;
}

void Fixed::setRawbits(int const raw)
{
    this->fPointval = raw;
}

int Fixed::toInt(void) const
{

}

float Fixed::toFloat(void) const
{

}