#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called." << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    int i = 0;

    std::cout << "Brain assignement operator called." << std::endl;
    if(this != &other)
    {
        while(i < 100)
        {
            this->ideas[i] = other.ideas[i];
            i++;
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called." << std::endl;
}

std::string Brain::getIdea(int i) const
{
    if(i >= 0 && i <= 99)
        return this->ideas[i];
    return "";
}

void Brain::setIdea(int i, const std::string& idea)
{
    if(i >= 0 && i <= 99)
        this->ideas[i] = idea;
    else
    std::cerr << "Invalid index in setIdea. Must be between 0 and 99." << std::endl;
}