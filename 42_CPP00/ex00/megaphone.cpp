#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    int i;
    int j;

    if(ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        i =1;
        while(i < ac)
        {
            std::string str(av[i]);
            j = 0;
            while(j < str.length())
            {
                std::cout << (char)std::toupper(str[j]);
                j++;
            }
            if(i < ac - 1)
                std::cout << " ";
            i++;
        }
        std::cout << std::endl;
    }
    return 0;
}