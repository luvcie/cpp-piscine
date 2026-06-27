#include "Span.hpp"
#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

int main(void) {
    std::cout << "PDF EXAMPLE TEST" << std::endl;
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;  // expected: 2
    std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl;  // expected: 14

    std::cout << std::endl;

    std::cout << "ADD WHEN FULL EXCEPTION" << std::endl;
    try {
        sp.addNumber(999);
    } catch (std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "TOO FEW NUMBERS EXCEPTION" << std::endl;
    Span tiny(1);
    tiny.addNumber(36);
    try {
        tiny.shortestSpan();
    } catch (std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "RANGE OF ITERATORS (10000 numbers)" << std::endl;
    Span big(10000);
    std::vector<int> source;
    std::srand(std::time(NULL));
    for (int i = 0; i < 10000; i++)
        source.push_back(std::rand());
    big.addNumbers(source.begin(), source.end());
    std::cout << "shortestSpan: " << big.shortestSpan() << std::endl;
    std::cout << "longestSpan:  " << big.longestSpan()  << std::endl;

    std::cout << std::endl;

    std::cout << "ADDNUMBERS OVERFLOW EXCEPTION" << std::endl;
    Span small(3);
    small.addNumber(1);
    small.addNumber(2);
    std::vector<int> toomany;
    toomany.push_back(111);
    toomany.push_back(777);
    try {
        small.addNumbers(toomany.begin(), toomany.end());
    } catch (std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "IDENTICAL NUMBERS (shortestSpan = 0)" << std::endl;
    Span twins(2);
    twins.addNumber(156);
    twins.addNumber(156);
    std::cout << "shortestSpan: " << twins.shortestSpan() << std::endl;
    std::cout << "longestSpan:  " << twins.longestSpan()  << std::endl;

    return 0;
}
