/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:11:43 by del-ganb          #+#    #+#             */
/*   Updated: 2025/09/11 14:11:44 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    if(ac < 2)
        throw std::runtime_error("Error: Invalid parameters!");

    for(int i = 1; i < ac; i++)
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

static bool comparePairsBySecond(const std::pair<int, int>& a, const std::pair<int, int>& b) 
{
        return a.second < b.second;
}

std::vector<int> PmergeMe::sortVector(std::vector<int>& data)
{
    std::vector<int> bigs;
    std::vector<int> smalls;
    std::vector<std::pair<int, int> > pairs;
    int rest; 
    
    
    for (size_t i = 0; i + 1 < data.size(); i += 2)
    {    
            if(data[i] < data[i + 1])
                pairs.push_back(std::make_pair(data[i], data[i + 1]));
            else
                pairs.push_back(std::make_pair(data[i + 1], data[i]));
    }
    std::sort(pairs.begin(), pairs.end(), comparePairsBySecond);

    bool hasRest = false;
    if(data.size() % 2 != 0)
    {
        rest = data.back();
        hasRest = true;
    }

    for (size_t j = 0; j < pairs.size(); ++j)
    {
        bigs.push_back(pairs[j].second);
        smalls.push_back(pairs[j].first);
    }
    
    std::vector<size_t> order = jacobsthalOrder(smalls.size());
    std::vector<bool> inserted(smalls.size(), false);

    for(size_t index = 0; index < order.size(); ++index)
    {
        size_t pos = order[index];
        if(pos < smalls.size() && !inserted[pos])
        {
            binaryInsert(bigs, smalls[pos], bigs.size() - 1);
            inserted[pos] = true;
        }
    }

    if(hasRest)
        binaryInsert(bigs, rest, bigs.size() - 1);

    return bigs;
}

std::deque<int> PmergeMe::sortDeque(std::deque<int>& data)
{
    std::deque<int> bigs;
    std::deque<int> smalls;
    std::deque<std::pair<int, int> > pairs;
    int rest; 
    size_t i = 0;
    
    for (; i < data.size(); i += 2)
    {
        if(i + 1 < data.size())
        {    
            if(data[i] < data[i + 1])
                pairs.push_back(std::make_pair(data[i], data[i + 1]));
            else
                pairs.push_back(std::make_pair(data[i + 1], data[i]));
        }
    }
    std::sort(pairs.begin(), pairs.end(), comparePairsBySecond);

    bool hasRest = false;
    if(data.size() % 2 != 0)
    {
        rest = data.back();
        hasRest = true;
    }
    
    for (size_t j = 0; j < pairs.size(); j++)
    {
        bigs.push_back(pairs[j].second);
        smalls.push_back(pairs[j].first);
    }
   
    
    std::vector<size_t> order = jacobsthalOrder(smalls.size());
    std::vector<bool> inserted(smalls.size(), false);

    for(size_t index = 0; index < order.size(); index++)
    {
        size_t pos = order[index];
        if(pos < smalls.size() && !inserted[pos])
        {
            int val = smalls[pos];
            binaryInsert(bigs, val, bigs.size() - 1);
            inserted[pos] = true;
        }
    }

    for (size_t k = 0; k < smalls.size(); k++)
    {
        if (!inserted[k])
            binaryInsert(bigs, smalls[k], bigs.size() - 1);
    }

    if(hasRest)
        binaryInsert(bigs, rest, bigs.size() - 1);

    return bigs;
}

std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n)
{
    std::vector<size_t> jacobVec;
    
    jacobVec.push_back(0);
    jacobVec.push_back(1);

    while(jacobVec.back() <= n)
    {
        size_t size = jacobVec.size();
        size_t prev1 = jacobVec[size - 1];
        size_t prev2 = jacobVec[size - 2];

        size_t next = prev1 + prev2 * 2;
        if(next > n)
            break;
        jacobVec.push_back(next);
    }
    return jacobVec;
}

void PmergeMe::run(int ac, char **av)
{
    parseInput(ac, av);

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::clock_t startVec = std::clock();
    std::vector<int> sortedVec = sortVector(vec);
    std::clock_t endVec = std::clock();
    double vectorTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;

    std::clock_t startDeq = std::clock();
    std::deque<int> sortedDeq = sortDeque(deck);
    std::clock_t endDeq = std::clock();
    double dequeTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

    vec = sortedVec;
    deck = sortedDeq;

    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : "
              << std::fixed << std::setprecision(5)
              << vectorTime << " us" << std::endl;

    std::cout << "Time to process a range of " << deck.size()
              << " elements with std::deque : "
              << std::fixed << std::setprecision(5)
              << dequeTime << " us" << std::endl;
}
