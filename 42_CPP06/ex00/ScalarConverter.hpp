/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:12:25 by del-ganb          #+#    #+#             */
/*   Updated: 2025/07/03 12:12:26 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <cctype>
#include <climits>
#include <iomanip> 
#include <stdlib.h>

class  ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter&  operator=(const ScalarConverter& other);
        ~ScalarConverter();

        static std::string which_type(std::string const& m_type);
        static bool check_input(std::string const &str); 

        static void print_float(double value);
        static void print_double(double value);
        static void print_int(double value);
        static void print_char(double value);

        static void convert(std::string const& m_type);
};

#endif
