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

bool comparePairsBySecond(const std::pair<int, int>& a, const std::pair<int, int>& b) 
{
        return a.second < b.second;
}

std::vector<int> PmergeMe::sortVector(std::vector<int>& data)
{
    std::vector<int> res;
    std::vector<int> pending;
    std::vector<std::pair<int, int>> pairs;
    int rest; 
    size_t i = 0;
    
    for (i; i < data.size(); i += 2)
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

    if(data.size() % 2 != 0)
        rest = data[i];
    
    for (size_t j = 0; j < pairs.size(); j++)
    {
        res.push_back(pairs[j].second);
        pending.push_back(pairs[j].first);
    }
    return res;
}

std::deque<int> PmergeMe::sortDeque(std::deque<int>& data)
{
    std::deque<int> res;
    std::deque<int> pending;
    std::deque<std::pair<int, int>> pairs;
    int rest; 
    size_t i = 0;
    
    for (i; i < data.size(); i += 2)
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

    if(data.size() % 2 != 0)
        rest = data[i];
    
    for (size_t j = 0; j < pairs.size(); j++)
    {
        res.push_back(pairs[j].second);
        pending.push_back(pairs[j].first);
    }
    return res;
}

std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n)
{
    std::vector<size_t> vec;

    for (size_t i = 0; i < n; i++)
    {
       if(i == 0)
        vec.push_back(0);
        
       else if(i == 1)
        vec.push_back(1);

       else
       {
            size_t res = vec[i - 1] +  2 * vec[i - 2];
            vec.push_back(res);
       }

    }
    return vec;
}
