/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:10:17 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/12 16:10:18 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called." << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignement operator called." << std::endl;
    if(this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat meows" << std::endl;
}
