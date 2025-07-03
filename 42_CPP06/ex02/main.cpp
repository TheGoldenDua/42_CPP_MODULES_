#include "Base.hpp"

int main()
{
    srand(time(NULL));

    Base *ptr = generate();

    std::cout << "Using pointer: ";
    identify(ptr);

    std::cout << "Using reference: ";
    identify(*ptr);

    delete ptr;
    return 0;
}
