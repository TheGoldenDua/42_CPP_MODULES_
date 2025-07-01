#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <cctype>
#include <climits>
#include <iomanip> 

class  ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter&  operator=(const ScalarConverter& other);
        ~ScalarConverter();

        static std::string which_type(std::string const& m_type);
        static bool check_input(std::string const &str); 

        static void printFloat(double value);
        static void printDouble(double value);
        static void printInt(double value);
        static void printChar(double value);

    public:
        static void convert(std::string const& m_type);
};

#endif