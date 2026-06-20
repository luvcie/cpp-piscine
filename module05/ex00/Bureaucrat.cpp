#include "Bureaucrat.hpp"

// what() returns a string in c style describing the exception
// in std::exception what() is defined as returning const char* so yeah
const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}
// "i have a function called what which takes no parameters,
// and you can expect it to throw an exception with no parameters"
const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
  if (grade < 1)
    throw GradeTooHighException();
  if (grade > 150)
    throw GradeTooLowException();
  std::cout << "Bureaucrat " << name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat() : name("default"), grade(75) {
  std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
  std::cout << "Bureaucrat copy constructor called" << std::endl; 
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "Bureaucrat copy assignment operator called" << std::endl;
  if (this != &other)
    this->grade = other.grade;
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const {
  return name;
}

int Bureaucrat::getGrade() const {
  return grade;
}

// 1 = highest grade, 150 = lowest grade
void Bureaucrat::incrementGrade() {
  if (grade - 1 < 1) { // would the new grade be less than 1?
    throw GradeTooHighException(); // this is ridiculous just return; omg
  }
  grade--;
}

void Bureaucrat::decrementGrade() {
  if (grade + 1 > 150) {
    throw GradeTooLowException();
  }
  grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& brcrt) {
  os << brcrt.getName() << ", bureaucrat grade " << brcrt.getGrade() << ".";
  return os;
}
