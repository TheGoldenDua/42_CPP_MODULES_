#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    if(this != &other)
        *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if(this != &other)
        *this = other;
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::parseInput(int ac, char **av)
{
    if(ac <= 1)
        throw std::runtime_error("Error: Invalid parameters!");

    for(size_t i = 1; i < ac; i++)
    {
        std::string arg(av[i]);

        if(arg.empty())
            throw std::runtime_error("Error: empty parameter!");
       
        for(size_t j = 0; j < arg.size() ; j++)
        {
            if(!std::isdigit(static_cast<unsigned char>(arg[j])))
                throw std::runtime_error("Error: parameters must be positive integers!");
        }
        long nb = std::atol(arg.c_str());
        if(nb <= 0 || nb < INT_MIN || nb > INT_MAX)
            throw std::runtime_error("Error: parametrs must fits in int!");

        if (std::find(vec.begin(), vec.end(), nb) != vec.end())
            throw std::runtime_error("Error: duplicate parameter detected!");

        vec.push_back(static_cast<int> (nb));
        deck.push_back(static_cast<int> (nb));
    }
}