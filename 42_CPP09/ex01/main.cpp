#include "RPN.hpp"

int main(int ac , char **av)
{
    if(ac != 2)
    {
        std::cerr << ("Error: (usage: ./Rpn expression)") << std::endl ;
        return 1;
    }

    RPN rpn;
    try
    {
        rpn.processInput(av[1]);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}