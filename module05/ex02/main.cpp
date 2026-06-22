#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    std::cout << "EXECUTE UNSIGNED FORM" << std::endl;
    try {
        Bureaucrat edward("Edward Elric", 1);
        ShrubberyCreationForm resembool("Resembool");
        edward.executeForm(resembool);
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "GRADE TOO LOW TO EXECUTE" << std::endl;
    try {
        Bureaucrat roy("Roy", 60);
        RobotomyRequestForm robotomy("Alphonse");
        roy.signForm(robotomy);
        roy.executeForm(robotomy);
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "GRADE TOO LOW TO SIGN" << std::endl;
    try {
        Bureaucrat winry("Winry Rockbell", 100);
        PresidentialPardonForm pardon("Edward Elric");
        winry.signForm(pardon);
        winry.executeForm(pardon);
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "SHRUBBERY CREATION FORM" << std::endl;
    try {
        Bureaucrat ike("Ike", 1);
        ShrubberyCreationForm resembool("Resembool");
        std::cout << resembool << std::endl;
        ike.signForm(resembool);
        ike.executeForm(resembool);
        std::cout << resembool << std::endl;
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "ROBOTOMY REQUEST FORM (run twice to show 50/50)" << std::endl;
    try {
        Bureaucrat royMustang("Roy Mustang", 1);
        RobotomyRequestForm robotomy("Alphonse");
        royMustang.signForm(robotomy);
        royMustang.executeForm(robotomy);
        royMustang.executeForm(robotomy);
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "PRESIDENTIAL PARDON FORM" << std::endl;
    try {
        Bureaucrat kingBradley("King Bradley", 1);
        PresidentialPardonForm pardon("Edward Elric");
        std::cout << kingBradley << std::endl;
        kingBradley.signForm(pardon);
        kingBradley.executeForm(pardon);
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "MARTH FAILS TO SIGN (grade 145, needs 25)" << std::endl;
    try {
        Bureaucrat marth("Marth", 145);
        PresidentialPardonForm pardon("Ike");
        marth.signForm(pardon);
        marth.executeForm(pardon);
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }

    return 0;
}
