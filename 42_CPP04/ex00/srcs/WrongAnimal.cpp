/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:10:08 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/12 16:10:09 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called." << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy constructor called." << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy assignement operator called." << std::endl;
    if(this != &other)
        this->type = other.getType();
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called." << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a sound" << std::endl;
}
