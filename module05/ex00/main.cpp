#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "NORMAL CONSTRUCTION" << std::endl;
    try {
        Bureaucrat a("Godot", 42);
        std::cout << a << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "GRADE TOO HIGH (grade 0)" << std::endl;
    try {
        Bureaucrat b("Manfred von Karma", 0);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "GRADE TOO LOW (grade 151)" << std::endl;
    try {
        Bureaucrat c("Larry Butz", 151);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "INCREMENT AT GRADE 1 (it should throw)" << std::endl;
    try {
        Bureaucrat d("Miles Edgeworth", 1);
        std::cout << d << std::endl;
        d.incrementGrade();
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "DECREMENT AT GRADE 150 (it should throw)" << std::endl;
    try {
        Bureaucrat e("Franziska von Karma", 150);
        std::cout << e << std::endl;
        e.decrementGrade();
    } catch (std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "INCREMENT AND DECREMENT" << std::endl;
    try {
        Bureaucrat f("Phoenix Wright", 50);
        std::cout << f << std::endl;
        f.incrementGrade();
        std::cout << f << std::endl;
        f.decrementGrade();
        f.decrementGrade();
        std::cout << f << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "COPY AND ASSIGNMENT" << std::endl;
    try {
        Bureaucrat g("Maya Fey", 30);
        Bureaucrat h(g);
        Bureaucrat i = g;
        std::cout << g << std::endl;
        std::cout << h << std::endl;
        std::cout << i << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
