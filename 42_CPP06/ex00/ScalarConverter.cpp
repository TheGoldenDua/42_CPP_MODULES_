/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:12:33 by del-ganb          #+#    #+#             */
/*   Updated: 2025/07/09 10:29:10 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter(){}

bool ScalarConverter::check_input(std::string const& str)
{
    if(str.empty())
    {
        std::cout << "Empty input!" << std::endl;
        return (false);
    }
    for (size_t i = 0; i < str.length(); i++)
    {
        if(!isprint(str[i]))
        {
            std::cout << "Non printable charachters!" << std::endl;
            return false;
        }
    }
    return true;
}

std::string ScalarConverter::which_type(std::string const& input)
{
    if(input == "nanf" || input ==  "-inff" || input == "+inff")
        return "float";

    if(input == "nan" || input == "-inf" || input == "+inf")
        return "double"; 

    if(input.length() == 1 && !std::isdigit(input[0]))
        return "char";
        
    char *intEnd;
    long val;
    val = std::strtol(input.c_str(), &intEnd, 10);
    if(*intEnd == '\0' && val >= INT_MIN && val <= INT_MAX)
        return "int";

    if(!input.empty() && input[input.length() - 1] == 'f')
    {
        std::string fltPart;
        char *floatEnd;

        fltPart = input.substr(0, input.length() - 1);
        std::strtod(fltPart.c_str(), &floatEnd);
        if(*floatEnd == '\0')
            return "float";
    }

    char *doublEnd;
    std::strtod(input.c_str(), &doublEnd);
    if(*doublEnd == '\0')
        return "double";

    return "unknown!";
}

void ScalarConverter::print_char(double value)
{
    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127)
        std::cout << "Impossible!" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "Non displayable!" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::print_int(double value)
{
    std::cout << "int: ";
    if (std::isnan(value) || value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
        std::cout << "Impossible!" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::print_float(double value)
{
    std::cout << "float: ";
    std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::print_double(double value)
{
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convert(std::string const& input)
{
    if (!check_input(input))
        return;

    std::string type;
    double val;

    type = which_type(input);
    std::cout << "Detected type: " << type << std::endl;
    
    if(type == "char")
    {
        char c = input[0];
        val = static_cast<double>(c);
    }
    else if(type == "int")
    {
        val = std::atoi(input.c_str());
    }
    else if(type == "float")
    {
        val = static_cast<double> (std::strtof(input.c_str(), NULL));
    }
    else if(type == "double")
    {
        val = std::strtod(input.c_str(), NULL);
    }
    else
    {
        std::cout << "conversion impossible!" << std::endl;
        return ;
    }
    print_char(val);
    print_int(val);
    print_float(val);
    print_double(val);
}
