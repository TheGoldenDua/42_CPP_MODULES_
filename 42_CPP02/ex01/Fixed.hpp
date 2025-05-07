/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:24:27 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/07 12:24:28 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int value;
        static const int fractbit = 8;
    public:
        Fixed();
        Fixed(const int i);
        Fixed(const float f);
        Fixed(const Fixed &other);
        Fixed&  operator=(const Fixed& other);
        ~Fixed();
        
        int getRawBits(void) const;
        void setRawbits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed);

#endif
