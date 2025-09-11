/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:11:59 by del-ganb          #+#    #+#             */
/*   Updated: 2025/09/11 14:12:00 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void RPN::processInput(const std::string input)
{
    std::string copy = trim(input);
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
                nb = b * a;
            else if(token == "/")
            {
                if (a == 0)
                    throw std::runtime_error("Error: Division by zero!");
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
                throw std::runtime_error("Error: Invalid number (nbrs have to be less than 10)!");
            nbStck.push(nbr);
        }  
    }
    
    if (nbStck.size() != 1)
        throw std::runtime_error("Error: Invalid RPN expression!");

    std::cout << nbStck.top() << std::endl;
}
