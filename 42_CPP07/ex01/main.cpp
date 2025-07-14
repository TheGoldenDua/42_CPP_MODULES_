#include "iter.hpp"

int main()
{
    std::cout << "printing an array of integers:" << std::endl;
    int I[5] = {1, 2, 3, 4, 5};
    iter(I, 5, print);

    std::cout << "\nprinting an array of strings:" << std::endl;
    std::string S[] = {"hello", "world", "I am", "using", "templates!"};
    iter(S, 5, print);

    std::cout << "\nprinting an array of characters:" << std::endl;
    char C[] = {'h', 'e', 'l', 'l', 'o'};
    iter(C, 5, print);
    return 0;
}