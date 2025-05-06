#include "Fixed.hpp"

Fixed::Fixed() : fPointval(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    fPointval = roundf(f * (1 << fractbit));
}

Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
    fPointval = i << fractbit;
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
    return (int) fPointval >> fractbit ;
}

float Fixed::toFloat(void) const
{
    return (float) fPointval / (1 << fractbit);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}