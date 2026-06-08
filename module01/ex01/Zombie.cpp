#include "Zombie.hpp"
#include <iostream>

// constructor, initializes
Zombie::Zombie() {
}

// destructor, cleans up and prints name of what was released
Zombie::~Zombie() {
    std::cout << name << " burned to death x_x" << std::endl;
}

void Zombie::setName(std::string name){
    this->name = name; // "this" is a C++ keyword, it's a pointer to the current object
}

void Zombie::announce(){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
