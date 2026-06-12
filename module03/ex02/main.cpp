#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap character1("Toon Link");
    std::cout << std::endl;

    std::cout << "ACTIONS " << std::endl;
    character1.attack("the wall");
    character1.takeDamage(50);
    character1.beRepaired(25);
    character1.highFivesGuys();
    std::cout << std::endl;

    std::cout << "CLAPTRAP FOR COMPARISON " << std::endl;
    ClapTrap character2("Golem");
    character2.attack("nobody");
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "COPY TESTS " << std::endl;
    FragTrap copy(character1);
    copy.attack("a shadow");
    std::cout << std::endl;

    std::cout << "ASSIGNMENT TEST " << std::endl;
    FragTrap assigned("Kirby");
    assigned = character1;
    assigned.highFivesGuys();
    std::cout << std::endl;

    // NO ENERGY TEST: loop 101 times to drain all 100 energy, last attack is blocked
    // std::cout << "NO ENERGY TEST " << std::endl;
    // FragTrap snorlax("Snorlax");
    // for (int i = 0; i <= 100; ++i)
    //     snorlax.attack("wall");
    // std::cout << std::endl;


    std::cout << "Objects destroy in reverse order of creation within the same scope." << std::endl;
    return 0;
}
