/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:23:48 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/07 12:23:49 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
        int value;
        static const int fractbit = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed&  operator=(const Fixed& other);
        ~Fixed();
        
        int getRawBits(void) const;
        void setRawbits(int const raw);
};

#endif
