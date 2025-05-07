/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:24:50 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/07 12:24:51 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const float f)
{
    value = roundf(f * (1 << fractbit));
}

Fixed::Fixed(const int i)
{
    value = i << fractbit;
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed&  Fixed::operator=(const Fixed& other)
{
    if(this != &other)
        this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{

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

std::ostream &operator<<(std::ostream &str, const Fixed &fixed)
{
    str << fixed.toFloat();
    return str;
}

bool Fixed::operator>(const Fixed &other) const
{
	return value > other.value;
}

bool Fixed::operator<(const Fixed &other) const
{
	return value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return value != other.value;
}


Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
    value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    value += 1;
    return tmp;
}

Fixed &Fixed::operator--()
{
    value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    value -= 1;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}
