#include "ScalarConverter.hpp"

static  std::string which_type(std::string const m_type)
{
    if(m_type == "int")
        return("int");
    else if(m_type == "char")
        return("char");
    else if(m_type == "float")
        return("float");
    else if(m_type == "double")
        return ("double");
    else
        return(NULL);
}

void ScalarConverter::convert(std::string const& m_type)
{
    std::string type;

    type = which_type(m_type);
}