#include "ScavTrap.hpp"

void ScavTrap::attack(const std::string& target) {
    if (hitPoints == 0 || energyPoints == 0) {
        std::cout << "ScavTrap " << name << " can't attack, no hp or energy left" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " mega-attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}

// pdf says: "When a ScavTrap is created, the program starts by constructing a ClapTrap."
// the ClapTrap part is built first ( this is called constructor chaining i think :o), then customize hte stats
// this constructor is for when it doesnt have a name
ScavTrap::ScavTrap() : ClapTrap() {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

// and this one for when a name is given
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destructor called" << std::endl;
}
