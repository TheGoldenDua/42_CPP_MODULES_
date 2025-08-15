#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <exception>
#include <cstdlib>


class NotValidNumberException : public std::exception
{
    public: 
        const char* what() const throw()
        {
            return "Error: Invalid number (nbrs must to be less than 10)!";
        }
};

class NotValidOperatorException : public std::exception
{
    public: 
        const char* what() const throw()
        {
            return "Error: Invalid operator (allowed operators: +,-,*,/)!";
        }
};

class NotEnoughOperandsException : public std::exception
{
    public: 
        const char* what() const throw()
        {
            return "Error: Not enough operands!";
        }
};

class RPN
{
    private:
        std::stack<int> nbStck;

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        
        void processInput(const std::string input);
};



#endif