/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:06:57 by del-ganb          #+#    #+#             */
/*   Updated: 2025/05/12 16:52:18 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/AAnimal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/Brain.hpp"
#include <iostream>


int main() {
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; ++i) {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    std::cout << std::endl;
    for (int i = 0; i < size; ++i) {
        animals[i]->makeSound();
    }
    std::cout << std::endl;
    for (int i = 0; i < size; ++i)
        delete animals[i]; 

    return 0;
}
