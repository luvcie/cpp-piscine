#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high to sign";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade too low to sign";
}

const char* AForm::FormNotSignedException::what() const throw() {
  return "Form is not signed";
}

AForm::AForm() : name("default"), isSigned(false), gradeToSign(75), gradeToExecute(75) {
  std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
  : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooHighException();
  if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooLowException();
  std::cout << "AForm " << name << " constructor called" << std::endl;
}

AForm::AForm(const AForm& other)
  : name(other.name), isSigned(other.isSigned),
    gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
  std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
  std::cout << "AForm copy assignment operator called" << std::endl;
  if (this != &other)
    this->isSigned = other.isSigned;
  return *this;
}

AForm::~AForm() {
  std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(const Bureaucrat& brcrt) {
  if (brcrt.getGrade() > gradeToSign)
    throw GradeTooLowException();
  isSigned = true;
}

void AForm::execute(Bureaucrat const& executor) const {
  if (!isSigned)
    throw FormNotSignedException();
  if (executor.getGrade() > gradeToExecute)
    throw GradeTooLowException();
  action();
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
  os << "AForm " << f.getName()
     << " | Signed: " << (f.getIsSigned() ? "yes" : "no")
     << " | Grade to sign: " << f.getGradeToSign()
     << " | Grade to execute: " << f.getGradeToExecute();
  return os;
}
