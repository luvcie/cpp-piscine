#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

/*
    // test 1: comparisons (all compare the raw value, return true/false as 1/0)
    Fixed x(3);
    Fixed y(7);
    std::cout << (x < y) << std::endl;   // expected: 1
    std::cout << (x > y) << std::endl;   // expected: 0
    std::cout << (x <= y) << std::endl;  // expected: 1
    std::cout << (x >= y) << std::endl;  // expected: 0
    std::cout << (x == x) << std::endl;  // expected: 1
    std::cout << (x != y) << std::endl;  // expected: 1

    // test 2: arithmetic (done through float, returns a new Fixed)
    std::cout << (x + y) << std::endl;   // expected: 10
    std::cout << (x - y) << std::endl;   // expected: -4
    std::cout << (x * y) << std::endl;   // expected: 21
    std::cout << (y / x) << std::endl;   // expected: 2.33203

    // test 3: decrement (moves the raw value by one epsilon)
    Fixed z(1);
    std::cout << --z << std::endl;       // expected: 0.996094 (pre, new value)
    std::cout << z-- << std::endl;       // expected: 0.996094 (post, old value before the step)
    std::cout << z << std::endl;         // expected: 0.992188

    // test 4: min and max, both the normal and the const versions
    std::cout << Fixed::min(x, y) << std::endl;   // expected: 3
    std::cout << Fixed::max(x, y) << std::endl;   // expected: 7
    Fixed const cx(2);
    Fixed const cy(9);
    std::cout << Fixed::min(cx, cy) << std::endl; // expected: 2
    std::cout << Fixed::max(cx, cy) << std::endl; // expected: 9
*/

return 0;
}
