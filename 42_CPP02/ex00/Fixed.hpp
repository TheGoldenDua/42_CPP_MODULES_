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