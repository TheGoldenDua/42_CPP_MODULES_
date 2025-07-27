#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>


class NoOccurenceException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "No occurence is found!";
        }
};

template <typename T>
typename T::iterator easyfind(T& container, int i)
{
    typename T::iterator j = std::find(container.begin(), container.end(), i);
    
    if(j == container.end())
    {
        throw NoOccurenceException();
    }
    return(j);
}

#endif