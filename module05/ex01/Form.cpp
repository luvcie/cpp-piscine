#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is too high to sign";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade too low to sign";
}

Form::Form() : name("default"), isSigned(false), gradeToSign(75), gradeToExecute(75) {
  std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
  : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooHighException();
  if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooLowException();
  std::cout << "Form " << name << " constructor called" << std::endl;
}

Form::Form(const Form& other)
  : name(other.name), isSigned(other.isSigned),
    gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
  std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
  std::cout << "Form copy assignment operator called" << std::endl;
  if (this != &other)
    this->isSigned = other.isSigned;
  return *this;
}

Form::~Form() {
  std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(const Bureaucrat& brcrt) {
  if (brcrt.getGrade() > gradeToSign)
    throw GradeTooLowException();
  isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
  os << "Form " << f.getName()
     << " | Signed: " << (f.getIsSigned() ? "yes" : "no")
     << " | Grade to sign: " << f.getGradeToSign()
     << " | Grade to execute: " << f.getGradeToExecute();
  return os;
}