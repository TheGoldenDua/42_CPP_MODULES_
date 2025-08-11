
#include "BitcoinExchange.hpp"


BitcoinExchange()
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

BitcoinExchange(const std::string &databaseFile)
{
    std::string line;
    std::ifstream infile(databasefile);

    if(!infile.is_open())
    {
        std::cout << "Error: Unable to open file!" << std::endl;
        exit(1);
    }
    
    std::getline(infile, line);
    while(std::getline(infile, line))
    {
        auto it = line.find(',');
        if(it == line.end())
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
            }
        }
        else
        {
            std::cout << "Error: Invalid date format!" << std::endl;
        }
    }

}

BitcoinExchange(const BitcoinExchange& other);
BitcoinExchange& operator=(const BitcoinExchange& other);
~BitcoinExchange();