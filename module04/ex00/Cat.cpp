#include "Cat.hpp"
#include <iostream>

void Cat::makeSound() const {
  std::cout << "Meow :3" << std::endl;
}

Cat::Cat() : Animal() {
  type = "Cat";
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
  std::cout << "Cat custom assignment operator called" << std::endl;
 Animal::operator=(other);
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
}