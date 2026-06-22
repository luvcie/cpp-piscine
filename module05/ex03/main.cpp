#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    Intern someIntern;

    std::cout << "INTERN CREATES SHRUBBERY CREATION FORM" << std::endl;
    try {
        Bureaucrat edward("Edward Elric", 1);
        AForm* form = someIntern.makeForm("shrubbery creation", "Resembool");
        if (form) {
            edward.signForm(*form);
            edward.executeForm(*form);
            delete form;
        }
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "INTERN CREATES ROBOTOMY REQUEST FORM (run twice)" << std::endl;
    try {
        Bureaucrat royMustang("Roy Mustang", 1);
        AForm* form = someIntern.makeForm("robotomy request", "Alphonse");
        if (form) {
            royMustang.signForm(*form);
            royMustang.executeForm(*form);
            royMustang.executeForm(*form);
            delete form;
        }
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "INTERN CREATES PRESIDENTIAL PARDON FORM" << std::endl;
    try {
        Bureaucrat kingBradley("King Bradley", 1);
        AForm* form = someIntern.makeForm("presidential pardon", "Edward Elric");
        if (form) {
            std::cout << *form << std::endl;
            kingBradley.signForm(*form);
            kingBradley.executeForm(*form);
            delete form;
        }
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "INTERN RECEIVES UNKNOWN FORM NAME" << std::endl;
    try {
        AForm* form = someIntern.makeForm("philosopher's stone", "Edward Elric");
        if (form)
            delete form;
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "GRADE TOO LOW TO SIGN (Winry can't sign presidential pardon)" << std::endl;
    try {
        Bureaucrat winry("Winry Rockbell", 100);
        AForm* form = someIntern.makeForm("presidential pardon", "Edward Elric");
        if (form) {
            winry.signForm(*form);
            winry.executeForm(*form);
            delete form;
        }
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }

    return 0;
}
