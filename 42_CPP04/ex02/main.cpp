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

    animals[1]->makeSound();
    animals[2]->makeSound();

    for (int i = 0; i < size; ++i)
        delete animals[i]; 

    return 0;
}

