/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:08:33 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/12 16:08:34 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat default constructor called." << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignment operator called." << std::endl;
    if(this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat meows" << std::endl;
}
