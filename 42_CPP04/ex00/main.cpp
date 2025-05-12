/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:10:00 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/12 16:10:01 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    std::cout << " ~ Type: " << meta->getType() << "\n";
    std::cout << " ~ Sound: ";
    meta->makeSound();
    delete (meta);
    std::cout << "\n";

    const Animal* dog = new Dog();
    std::cout << " ~ Type: " << dog->getType() << "\n";
    std::cout << " ~ Sound: ";
    dog->makeSound();
    delete (dog);
    std::cout << "\n";
    
    const Animal* cat = new Cat();
    std::cout << " ~ Type: " << cat->getType() << "\n";
    std::cout << " ~ Sound: ";
    cat->makeSound();
    delete (cat);
    std::cout << "\n";
    
    const WrongAnimal* wrongMeta = new WrongAnimal();
    std::cout << " ~ Type: " << wrongMeta->getType() << "\n";
    std::cout << " ~ Sound: ";
    wrongMeta->makeSound();
    delete (wrongMeta);
    std::cout << "\n";
    
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << " ~ Type: " << wrongCat->getType() << "\n";
    std::cout << " ~ Sound: ";
    wrongCat->makeSound();
    delete (wrongCat);

    return (0);
}
