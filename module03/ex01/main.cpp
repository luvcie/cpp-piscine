#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap character2("Geodude");
    std::cout << std::endl;

    std::cout << "ACTIONS " << std::endl;
    character2.attack("the intruder");
    character2.takeDamage(40);
    character2.beRepaired(20);
    character2.guardGate();
    std::cout << std::endl;

    std::cout << "CLAPTRAP FOR COMPARISON " << std::endl;
    ClapTrap character1("Golem");
    character1.attack("nobody");
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "COPY TESTS " << std::endl;
    ScavTrap copy(character2);
    copy.attack("a shadow");
    std::cout << std::endl;

    std::cout << "ASSIGNMENT TEST " << std::endl;
    ScavTrap assigned("Onix");
    assigned = character2;
    assigned.guardGate();
    std::cout << std::endl;

    // NO ENERGY TEST: loop 51 times to drain all 50 energy, last attack is blocked
    // std::cout << "NO ENERGY TEST " << std::endl;
    // ScavTrap tired("Snorlax");
    // for (int i = 0; i <= 50; ++i)
    //     tired.attack("wall");
    // std::cout << std::endl;

    std::cout << "Objects destroy in reverse order of creation within the same scope." << std::endl;
    return 0;
}
