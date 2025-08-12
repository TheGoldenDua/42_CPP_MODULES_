
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

BitcoinExchange::BitcoinExchange(const std::string &databaseFile)
{
    std::string line;
    std::ifstream infile(databaseFile);

    if(!infile.is_open())
    {
        std::cout << "Error: Unable to open file!" << std::endl;
        exit(1);
    }
    
    std::getline(infile, line);
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

            int y = std::stoi(year);
            int m = std::stoi(month);
            int d = std::stoi(day);

            if (y < 0 || m < 1 || m > 12 || d < 1 || d > 31)
            {
                std::cout << "Error: Invalid date ranges!" << std::endl;
                continue;
            }
            double value = std::stod(rateStr);
            this->_rates.insert({date, value});
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
    std::ifstream infile(inputFile);

    if(!infile.is_open())
    {
        std::cout << "Error: Unable to open file!" << std::endl;
        exit(1);
    }

    std::getline(infile, line);
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

            int y = std::stoi(year);
            int m = std::stoi(month);
            int d = std::stoi(day);

            if (y < 0 || m < 1 || m > 12 || d < 1 || d > 31)
            {
                std::cout << "Error: Invalid date ranges!" << std::endl;
                continue;
            }

            double value = std::stod(rateStr);
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
            std::cout << it->first << "=>" << value << "=" << res << std::endl;
        }
        else
            std::cout << "Error: Invalid date format!" << std::endl;
    }
}