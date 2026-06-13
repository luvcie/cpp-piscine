#include "WrongCat.hpp"
#include <iostream>

void WrongCat::makeSound() const {
    std::cout << "Meow :3 (wrong)" << std::endl;
}

WrongCat::WrongCat() : WrongAnimal() {
    type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    std::cout << "WrongCat custom assignment operator called" << std::endl;
    WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}
