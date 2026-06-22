#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

AForm* Intern::makeShrubbery(const std::string& target) const { return new ShrubberyCreationForm(target); }
AForm* Intern::makeRobotomy(const std::string& target) const  { return new RobotomyRequestForm(target); }
AForm* Intern::makePardon(const std::string& target) const    { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
  const std::string names[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
  AForm* (Intern::*creators[3])(const std::string&) const = { // array of pointers to member functions
    								// same trick as the harl exercise lol
    &Intern::makeShrubbery,
    &Intern::makeRobotomy,
    &Intern::makePardon
  };

  for (int i = 0; i < 3; i++) {
    if (names[i] == formName) {
      std::cout << "Intern creates " << formName << std::endl;
      return (this->*creators[i])(target);
    }
  }
  std::cout << "Intern: unknown form name: " << formName << std::endl;
  return NULL;
}
