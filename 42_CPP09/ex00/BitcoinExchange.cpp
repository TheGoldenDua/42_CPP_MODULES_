/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:12:17 by del-ganb          #+#    #+#             */
/*   Updated: 2025/09/11 14:12:18 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

static std::string trim(const std::string &str)
{
    size_t start = 0;
    size_t end = str.size();

    while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start])))
        start++;

    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
        end--;

    return str.substr(start, end - start);
}

static bool isValidInt(const std::string& nbr)
{
    if(nbr.empty())
        return false;
    
    size_t i = 0;
    if(nbr[i] == '+' || nbr[i] == '-')
        i++;
    
    while (i < nbr.size())
    {
        if(!std::isdigit(static_cast<unsigned char>(nbr[i])))
            return false;
        i++;
    }

    long nb = std::atol(nbr.c_str());
    if(nb < INT_MIN || nb > INT_MAX)
        return false;
    return true;
}

static bool isValidDouble(const std::string& nbr)
{
    if(nbr.empty())
        return false;

    size_t i = 0;
    bool hasDec = false;
    bool hasDigit = false;
    if(nbr[i] == '+' || nbr[i] == '-')
        i++;
    
    while(i < nbr.size())
    {
        if (nbr[i] == '.')
        {
            if (hasDec)
                return false;
            hasDec = true;
        }
        else if(std::isdigit(static_cast<unsigned char>(nbr[i])))
            hasDigit = true;
        else
            return false;

        i++;
    }
    if(!hasDigit)
        return false;

    char *endptr;
    std::strtod(nbr.c_str(), &endptr);
    if (*endptr != '\0')
        return false;

    return true;
}

BitcoinExchange::BitcoinExchange(const std::string &databaseFile)
{
    std::string line;
    std::ifstream infile(databaseFile.c_str());

    if(!infile.is_open())
    {
        std::cout << "Error: Unable to open file!" << std::endl;
        exit(1);
    }
    
    if(!std::getline(infile, line))
    {
        std::cout <<"Error: Empty file!" << std::endl;
        exit(1);
    }
    while(std::getline(infile, line))
    {
        std::size_t it = line.find(',');
        if(it == line.size())
        {
            std::cout << "invalid data file syntax (no comma found)" << std::endl;
            continue;
        }

        std::string date = line.substr(0, it);
        std::string rateStr = line.substr(it + 1);

        date = trim(date);
        rateStr = trim(rateStr);
        if(date[4] == '-' && date[7] == '-')
        {
            std::string year = date.substr(0, 4);
            std::string month = date.substr(5, 2);
            std::string day = date.substr(8, 2);

            if(!isValidInt(year) || !isValidInt(month) || !isValidInt(day))
            {
                std::cout << "Error: Invalid digit!" << std::endl;
                continue;
            }

            int y = std::atoi(year.c_str());
            int m = std::atoi(month.c_str());
            int d = std::atoi(day.c_str());

            if (y < 0 || m < 1 || m > 12 || d < 1 || d > 31)
            {
                std::cout << "Error: Invalid date ranges!" << std::endl;
                continue;
            }

            if(!isValidDouble(rateStr))
            {
                std::cout << "Error: Invalid rate!" << std::endl;
                continue;
            }
            double value = std::atof(rateStr.c_str());
            this->_rates.insert(std::make_pair(date, value));
        }
        else
            std::cout << "Error: Invalid date format!" << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    if(this != &other)
        *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if(this != &other)
        *this = other;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::processInputFile(const std::string &inputFile) const
{
    std::string line;
    std::ifstream infile(inputFile.c_str());

    if(!infile.is_open())
    {
        std::cout << "Error: Unable to open file!" << std::endl;
        exit(1);
    }

    if(!std::getline(infile, line))
    {
        std::cout <<"Error: Empty file!" << std::endl;
        exit(1);
    }
    
    line = trim(line);
    if(line != "date | value")
    {
        std::cout << "Error: input file must start with 'date | value'" << std::endl;
        exit(1);
    }

    while(std::getline(infile, line))
    {
        std::size_t it = line.find('|');
        if(it == line.size())
        {
            std::cout << "invalid data file syntax (usage: date | rate)" << std::endl;
            continue;
        }

        std::string date = line.substr(0, it);
        std::string rateStr = line.substr(it + 1);

        date = trim(date);
        rateStr = trim(rateStr);
        if(date[4] == '-' && date[7] == '-')
        {
            std::string year = date.substr(0, 4);
            std::string month = date.substr(5, 2);
            std::string day = date.substr(8, 2);

            if(!isValidInt(year) || !isValidInt(month) || !isValidInt(day))
            {
                std::cout << "Error: Invalid digit!" << std::endl;
                continue;
            }

            int y = std::atoi(year.c_str());
            int m = std::atoi(month.c_str());
            int d = std::atoi(day.c_str());

            if (y < 0 || m < 1 || m > 12 || d < 1 || d > 31)
            {
                std::cout << "Error: Invalid date ranges!" << std::endl;
                continue;
            }
            
            if(!isValidDouble(rateStr))
            {
                std::cout << "Error: Invalid rate!" << std::endl;
                continue;
            }

            double value = std::atof(rateStr.c_str());
            if(value < 0)
            {
                std::cout << "Error: not a positive number!" << std::endl;
                continue;
            }
            if(value > 1000)
            {
                std::cout << "Error: too large number!" << std::endl;
                continue;
            }

            std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
            double amount = 0.0;
            if(it != _rates.end() && it->first == date)
            {
                amount = it->second;
            }
            else if(it == _rates.begin() && it->first > date)
            {
                std::cout << "Error: No earlier date exist!";
                continue;
            }
            else if(it ==_rates.end() || it->first > date)
            {
                --it;
                amount = it->second;
            }
            else
                amount = it->second;

            double res = amount * value;
            std::cout << it->first << " => " << value << " = " << res << std::endl;
        }
        else
            std::cout << "Error: Invalid date format!" << std::endl;
    }
}
