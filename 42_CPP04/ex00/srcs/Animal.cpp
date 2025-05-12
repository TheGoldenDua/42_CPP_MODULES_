/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:10:21 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/12 16:10:22 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include <iostream>

Animal::Animal()
{
    std::cout << "Animal default constructor called." << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor called." << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignement operator called." << std::endl;
    if(this != &other)
        this->type = other.getType();
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called." << std::endl;
}

std::string Animal::getType(void) const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Animal makes a sound" << std::endl;
}
