#include "Dog.hpp"
#include <iostream>

void Dog::makeSound() const {
  std::cout << "Woof Woof!" << std::endl;
}

// constructor chaining
// Animal() tells compiler to run Animal's constructor
// before Dog's body
// i want that because Dog is an Animal so the Animal
// part of Dog must exist before Dog can build on top of it
Dog::Dog() : Animal() {
  type = "Dog";
  brain = new Brain();
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog copy constructor called" << std::endl;
  brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog &other) {
  std::cout << "Dog custom assignment operator called" << std::endl;
  if (this != &other) {
    Animal::operator=(other);
    *brain = *other.brain;
  }
  return *this;
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
  delete brain;
}

Brain* Dog::getBrain() const {
  return brain;
}
