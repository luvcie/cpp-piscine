#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "NORMAL CONSTRUCTION" << std::endl;
    try {
        Bureaucrat godot("Godot", 42);
        std::cout << godot << std::endl;
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "GRADE TOO HIGH (grade 0)" << std::endl;
    try {
        Bureaucrat vonkarma("Manfred von Karma", 0);
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "GRADE TOO LOW (grade 151)" << std::endl;
    try {
        Bureaucrat butz("Larry Butz", 151);
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "INCREMENT AT GRADE 1 (it should throw)" << std::endl;
    try {
        Bureaucrat edgeworth("Miles Edgeworth", 1);
        std::cout << edgeworth << std::endl;
        edgeworth.incrementGrade();
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "DECREMENT AT GRADE 150 (it should throw)" << std::endl;
    try {
        Bureaucrat franziska("Franziska von Karma", 150);
        std::cout << franziska << std::endl;
        franziska.decrementGrade();
    } catch (std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "INCREMENT AND DECREMENT" << std::endl;
    try {
        Bureaucrat phoenix("Phoenix Wright", 50);
        std::cout << phoenix << std::endl;
        phoenix.incrementGrade();
        std::cout << phoenix << std::endl;
        phoenix.decrementGrade();
        phoenix.decrementGrade();
        std::cout << phoenix << std::endl;
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "COPY AND ASSIGNMENT" << std::endl;
    try {
        Bureaucrat maya("Maya Fey", 30);
        Bureaucrat maya_copy(maya);
        Bureaucrat maya_assign = maya;
        std::cout << maya << std::endl;
        std::cout << maya_copy << std::endl;
        std::cout << maya_assign << std::endl;
    } catch (std::exception& err) {
        std::cout << "Exception: " << err.what() << std::endl;
    }

    return 0;
}
