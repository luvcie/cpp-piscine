#include "FragTrap.hpp"
// FragTrap uses ClapTrap's attack() directly
// PDF says "It is very similar to ScavTrap" but does NOT require a custom attack message.

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " requests a high five! (•⩊•)੭୧(^ ᵕ ^ )っ" << std::endl;
}

FragTrap::FragTrap() : ClapTrap() {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " destructor called" << std::endl;
}
