#include "Array.hpp"
#include <iostream>

int main() {
    std::cout << "EMPTY ARRAY" << std::endl;
    // Array<int> tells compiler to generate the array class but replace
    // every T with int
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;
    std::cout << std::endl;

    std::cout << "ARRAY OF 5 INTEGERS" << std::endl;
    Array<int> ints(5);
    for (unsigned int i = 0; i < ints.size(); ++i)
        ints[i] = i * 36;
    for (unsigned int i = 0; i < ints.size(); ++i)
        std::cout << ints[i] << std::endl;

    std::cout << std::endl;

    std::cout << "MODIFYING COPY DOESN'T AFFECt THE ORIGINAL" << std::endl;
    Array<int> copy(ints); // passing existing object of the same type, so uses copy ctor
    copy[0] = 777;
    std::cout << "original[0]: " << ints[0] << std::endl;
    std::cout << "copy[0]: " << copy[0] << std::endl;

    std::cout << std::endl;

    std::cout << "STRING ARRAY" << std::endl;
    Array<std::string> words(3);
    words[0] = "lucie";
    words[1] = "loves";
    words[2] = "cats";
    for (unsigned int i = 0; i < words.size(); ++i)
        std::cout << words[i] << std::endl;

   std::cout << std::endl;

    std::cout << "ASSIGNMENT OPERATOR (DEEP COPY)" << std::endl;
    Array<int> assigned(3);
    assigned = ints;
    assigned[0] = 111;
    std::cout << "ints[0] after modifying assigned: " << ints[0] << std::endl;
    std::cout << "assigned[0]: " << assigned[0] << std::endl;

    std::cout << std::endl;

    std::cout << "SELF ASSIGNMENT" << std::endl;
    ints = ints;
    std::cout << "ints[0] after self-assignment: " << ints[0] << std::endl;

    std::cout << std::endl;

    std::cout << "SIZE CHECK" << std::endl;
    std::cout << "empty.size(): " << empty.size() << std::endl;
    std::cout << "ints.size(): " << ints.size() << std::endl;
    std::cout << "copy.size(): " << copy.size() << std::endl;

    std::cout << std::endl;

    std::cout << "OUT OF BOUNDS EXCEPTION" << std::endl;
    try {
        std::cout << ints[999] << std::endl;
    } catch (std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "NEGATIVE INDEX EXCEPTION" << std::endl; // -1 in unsigned wraps around to maximum value of unsigned int so it's too high and it throws
    try {
        std::cout << ints[-1] << std::endl;
    } catch (std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }

    return 0;
}
