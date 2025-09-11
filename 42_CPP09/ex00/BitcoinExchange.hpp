/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:12:22 by del-ganb          #+#    #+#             */
/*   Updated: 2025/09/11 14:12:23 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>  
#include <sstream>   
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cfloat>

class BitcoinExchange 
{
    private:
        std::map<std::string, double> _rates;

    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &databaseFile);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void processInputFile(const std::string &inputFile) const;
};


#endif
