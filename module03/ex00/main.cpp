#include "ClapTrap.hpp"

int main() {
    ClapTrap character1("R.O.B.");
    ClapTrap character2("Rotom-Wash");
    std::cout << std::endl;

    character1.attack("Master Hand");
    character2.takeDamage(0);
    character2.beRepaired(5);
    std::cout << std::endl;

    std::cout << "Draining all energy " << std::endl;
    for(int i = 0; i < 11; ++i)
        character1.attack("Master Hand");
    std::cout << std::endl;

    std::cout << "MEGADAMAGE " << std::endl;
    character2.takeDamage(9999);
    character2.attack("Master Hand");
    std::cout << std::endl;

    std::cout << "copy" << std::endl;
    ClapTrap character3(character1);
    ClapTrap character4;
    character4 = character1;
    std::cout << std::endl;

    return 0;
}
