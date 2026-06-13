#include "Animal.hpp"
#include <iostream>

void Animal::makeSound() const {
  std::cout << "..." << std::endl;
}

std::string Animal::getType() const{
    return type;
}

Animal::Animal(){
  type = "Default";
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string t) : type(t) {
  std::cout << "Animal string constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
  std::cout << "Animal copy constructor called" << std::endl;
  *this = other;
}

Animal::~Animal(){
  std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other){
  if (this != &other) {
    this->type = other.type;
  }
  std::cout << "Animal custom assignment operator called" << std::endl;
  return *this;
}
