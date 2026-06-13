#include "Cat.hpp"
#include <iostream>

void Cat::makeSound() const {
  std::cout << "Meow :3" << std::endl;
}

Cat::Cat() : Animal() {
  type = "Cat";
  brain = new Brain();
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat copy constructor called" << std::endl;
 brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat &other) {
  std::cout << "Cat custom assignment operator called" << std::endl;
  if (this != &other) {
    Animal::operator=(other);
    *brain = *other.brain;
  }
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
  delete brain;
}
