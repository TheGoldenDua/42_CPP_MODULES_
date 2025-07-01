#include "ScalarConverter.hpp"

bool ScalarConverter::check_input(std::string const& str)
{
    int i = 0;
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

    if(input.back() == 'f')
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

    return "unknown";
}

void ScalarConverter::convert(std::string const& input)
{
    if (!check_input(input))
        return;

    std::string type;
    type = which_type(input);
    std::cout << "Detected type: " << type << std::endl;
}


