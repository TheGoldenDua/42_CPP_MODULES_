#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    int count = 5;
    Zombie* horde = zombieHorde(count, "HordeZombie");

    int i = 0;
    while(i < count)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return 0;
}