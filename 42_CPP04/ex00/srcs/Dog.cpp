/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:10:13 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/12 16:10:14 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called." << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignement operator called." << std::endl;
    if(this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog barks" << std::endl;
}
