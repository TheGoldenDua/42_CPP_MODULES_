#include "ClapTrap.hpp"

int main()
{
    ClapTrap test;
    ClapTrap dua("Dua");
    ClapTrap Sou("Sou");

    dua.attack("Sou");
    dua.takeDamage(20);
    dua.beRepaired(10);

    dua.attack("Sou");
    dua.takeDamage(10);

}