/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:08:18 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/12 16:47:29 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/Brain.hpp"
#include <iostream>

int main()
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n--- Animal Sounds ---" << std::endl;
    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << "\n--- Deep Copy Example ---" << std::endl;

    Dog original;
    original.setIdea(0, "I want to eat");

    Dog copy = original;

    std::cout << "Original idea: " << original.getIdea(0) << std::endl;
    std::cout << "Copied idea:   " << copy.getIdea(0) << std::endl;

    copy.setIdea(0, "I want to sleep");

    std::cout << "\nAfter changing copy's idea:" << std::endl;
    std::cout << "Original idea: " << original.getIdea(0) << std::endl;
    std::cout << "Copied idea:   " << copy.getIdea(0) << std::endl;

    return 0;
}


// int main()
// {
//     std::cout << "\n--- Deep Copy Example ---" << std::endl;

//     Dog* original = new Dog();
//     original->setIdea(0, "I want to eat");

//     Dog copy = *original;
//     std::cout << "Original idea: " << original->getIdea(0) << std::endl;
//     std::cout << "Copied idea:   " << copy.getIdea(0) << std::endl;

//     delete original;

//     std::cout << "\nAfter deleting original and changing copy's idea:" << std::endl;

//     std::cout << "Copied idea:   " << copy.getIdea(0) << std::endl;

//     return 0;
// }