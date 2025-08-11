#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>  
#include <sstream>   
#include <stdexcept>
#include <cctype>

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