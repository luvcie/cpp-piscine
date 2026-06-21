#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "BUREAUCRAT CONSTRUCTION FAILURE (grade 0)" << std::endl;
    try {
        Bureaucrat bad("Bad Bureaucrat", 0);
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "BUREAUCRAT CONSTRUCTION FAILURE (grade 151)" << std::endl;
    try {
        Bureaucrat bad("Bad Bureaucrat", 151);
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "SUCCESSFUL SIGN" << std::endl;
    try {
        Bureaucrat recklessBen("Reckless Ben", 1);
        std::cout << recklessBen << std::endl;
        Form consignment("Consignment Agreement", 10, 50);
        std::cout << consignment << std::endl;
        recklessBen.signForm(consignment);
        std::cout << consignment << std::endl;
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "GRADE TOO LOW TO SIGN" << std::endl;
    try {
        Bureaucrat brandonBest("Brandon Best", 150);
        Form consignment("Consignment Agreement", 10, 50);
        brandonBest.signForm(consignment);
        std::cout << consignment << std::endl;
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "FORM GRADE TOO HIGH (0)" << std::endl;
    try {
        Form bad("Franchise Fraud Contract", 0, 50);
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "FORM GRADE TOO LOW (151)" << std::endl;
    try {
        Form bad("Extortion Claim", 151, 50);
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "SIGN ALREADY SIGNED FORM" << std::endl;
    try {
        Bureaucrat ammonMcNeff("Ammon McNeff", 5);
        Form restrainingOrder("Restraining Order", 10, 50);
        ammonMcNeff.signForm(restrainingOrder);
        ammonMcNeff.signForm(restrainingOrder);
        std::cout << restrainingOrder << std::endl;
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }

    return 0;
}
