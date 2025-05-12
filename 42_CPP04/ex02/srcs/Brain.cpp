/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:07:23 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/12 16:57:20 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called." << std::endl;
    for (size_t i = 0; i < 100; i++)
    {
        this->ideas[i] = other.ideas[i];
    }
    
}
Brain& Brain::operator=(const Brain& other)
{
    int i = 0;

    std::cout << "Brain assignment operator called." << std::endl;
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
