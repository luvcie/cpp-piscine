#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void) {
    std::cout << "VECTOR TEST" << std::endl;
    std::vector<int> v;
    v.push_back(3);            // push_back() comes from <vector>
    v.push_back(36);           // and adds an element to the end of a vector
    v.push_back(93);
    v.push_back(777);
    v.push_back(111);
                                // *easyFind needs to dereference
                                // otherwise it would print
                                // the iterator object instead of the number
    std::cout << "looking for 3 (first): " << *easyFind(v, 3) << std::endl;
    std::cout << "looking for 93: " << *easyFind(v, 93) << std::endl;
    std::cout << "looking for 111 (last): " << *easyFind(v, 111) << std::endl;
    std::cout << "looking for 108... ";
    try {
        easyFind(v, 108);
    } catch (std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "LIST TEST" << std::endl;
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    std::cout << "looking for 2: " << *easyFind(l, 2) << std::endl;
    std::cout << "looking for 999... ";
    try {
        easyFind(l, 999);
    } catch (std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }

    return 0;
}
