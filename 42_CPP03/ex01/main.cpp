#include "ClapTrap.hpp"

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
   
    ClapTrap test;
    ClapTrap dua("Dua");
    ClapTrap Sou("Sou");

    std::cout << std::endl;
    dua.attack("Sou");
    dua.takeDamage(20);
    dua.beRepaired(10);

    dua.attack("Sou");
    dua.takeDamage(10);

   
    std::cout << std::endl;
    ScavTrap scav1; 
    ScavTrap scav2("ScavTrap2");

    
    scav2.attack("Target");
    scav2.takeDamage(30);
    scav2.beRepaired(10);
    scav2.guardGate(); 

   
    scav2.attack("Target");
    scav2.takeDamage(100); 
    scav2.beRepaired(20); 

    return 0;
}
