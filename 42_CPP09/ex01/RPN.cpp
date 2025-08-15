#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
    if(this != &other)
        *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if(this != &other)
        *this = other;
    return *this;
}

RPN::~RPN()
{
}

void RPN::processInput(const std::string input)
{
    std::string copy = input;
    std::string token;
    
    while(!copy.empty())
    {
        std::size_t pos = copy.find(" ");
        if (pos != std::string::npos)
        {
            token = copy.substr(0, pos);
            copy.erase(0, pos + 1);
        }
        else
        {
            token = copy;
            copy.clear();
        }

        if(token == "+" || token == "-" || token == "*" || token == "/")
        {
            if(nbStck.size() < 2)
                throw std::runtime_error("Error: Not enough operands!");
                
            int a = nbStck.top();
            nbStck.pop();
             int b = nbStck.top();
            nbStck.pop();
      
            int nb;
            if(token == "+")
                nb = b + a;
            else if (token == "-")
                nb = b - a;
            else if (token == "*")
                nb = a * b;
            else if(token == "/")
            {
                if (a == 0)
                    throw std::runtime_error("Error: Division by zero");
                nb = b / a;
            }
            else
                throw std::runtime_error("Error: Invalid operator (allowed operators: +,-,*,/)!");

            nbStck.push(nb);
        }
        else
        {
            int nbr = std::atoi(token.c_str());
            if(nbr < 0 || nbr >= 10)
                throw std::runtime_error("Error: Invalid number (nbrs must to be less than 10)!");
            nbStck.push(nbr);
        }  
    }
    
    if (nbStck.size() != 1)
        throw std::runtime_error("Error: Invalid RPN expression");

    std::cout << nbStck.top() << std::endl;
}