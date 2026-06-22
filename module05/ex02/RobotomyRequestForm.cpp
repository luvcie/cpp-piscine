#include "RobotomyRequestForm.hpp"
#include <cstdlib> // for rand() , for the coin flip

void RobotomyRequestForm::action() const {
    std::cout << "Drilling noises !!!" << std::endl;
    if (std::rand() % 2) {
        std::cout << target << " has been robotomized succesfully!" << std::endl;
    }
    else std::cout << target << " robotomy failed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
  : AForm(other), target(other.target) {
  std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
  std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
  if (this != &other) {
    AForm::operator=(other);
    target = other.target;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor called" << std::endl;
}
