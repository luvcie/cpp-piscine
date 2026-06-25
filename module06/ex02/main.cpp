#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

// takes: nothing
// returns: a randomly created A, B, or C object as a Base pointer
Base* generate(void) {
    switch (std::rand() % 3) { // rand % 3 generates a random nbr, 0, 1, or 2
                               // the switch picks the matching case
        case 0: return new A;
        case 1: return new B;
        default: return new C;
    }
}

// takes: a Base pointer
// returns: nothing, prints "A", "B", or "C"
void identify(Base* basepointer) {
    if (dynamic_cast<A*>(basepointer)) // dynamic_cast tries to cast basepointer to A*
                                       // if it succeeds, print
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(basepointer))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(basepointer))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

// takes: a Base reference
// returns: nothing, prints "A", "B", or "C". dynamic_cast on a reference throws on failure instead of returning NULL, so we use try/catch
void identify(Base& basepointer) { // called when passing a reference
    try { (void)dynamic_cast<A&>(basepointer); std::cout << "A" << std::endl; return; }
    catch (std::exception&) {}
    // try attempts the cast, if it succeeds (object is B) then prints B and returns
    try { (void)dynamic_cast<B&>(basepointer); std::cout << "B" << std::endl; return; }
    catch (std::exception&) {}
    try { (void)dynamic_cast<C&>(basepointer); std::cout << "C" << std::endl; return; }
    catch (std::exception&) {}
}

int main() {
    std::srand(std::time(NULL));

    for (int i = 0; i < 10; ++i) {
        Base* b = generate();
        std::cout << "pointer : "; identify(b);   // calls pointer version
        std::cout << "reference: "; identify(*b); // calls ref version bc dereferences the ptr
        delete b;
    }
    return 0;
}
