#include "iter.hpp"

int main()
{
    std::cout << "printing an array of integers" << std::endl;
    int T[5] = {1, 2, 3, 4, 5};
    iter(T, 5, print);

    std::cout << "\nprinting an array of strings" << std::endl;
    std::string S[] = {"hello", "world", "I am", "using", "templates!"};
    iter(S, 5, print);
    return 0;
}