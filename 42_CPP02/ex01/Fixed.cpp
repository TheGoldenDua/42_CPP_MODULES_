#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(f * (1 << fractbit));
}

Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
    value = i << fractbit;
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
        this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->value;
}

void Fixed::setRawbits(int const raw)
{
    this->value = raw;
}

int Fixed::toInt(void) const
{
    return (int) value >> fractbit ;
}

float Fixed::toFloat(void) const
{
    return (float) value / (1 << fractbit);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}