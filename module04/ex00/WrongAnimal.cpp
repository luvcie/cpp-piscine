#include "WrongAnimal.hpp"
#include <iostream>

void WrongAnimal::makeSound() const {
  std::cout << "..." << std::endl;
}

std::string WrongAnimal::getType() const{
    return type;
}

WrongAnimal::WrongAnimal(){
  type = "Default";
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string t) : type(t) {
  std::cout << "WrongAnimal String constructor called"  << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
  *this = other;
}

WrongAnimal::~WrongAnimal(){
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
  if (this != &other) {
    this->type = other.type;
  }
  std::cout << "WrongAnimal custom assignment operator called" << std::endl;
  return *this;
}
