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
    original.setIdea(0, "I want a bone");

    Dog copy = original; // call the copy constructor

    std::cout << "Original idea: " << original.getIdea(0) << std::endl;
    std::cout << "Copied idea:   " << copy.getIdea(0) << std::endl;

    copy.setIdea(0, "I want to sleep");

    std::cout << "\nAfter changing copy's idea:" << std::endl;
    std::cout << "Original idea: " << original.getIdea(0) << std::endl;
    std::cout << "Copied idea:   " << copy.getIdea(0) << std::endl;

    return 0;
}
