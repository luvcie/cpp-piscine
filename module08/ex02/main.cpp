#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
    std::cout << "EXAMPLE FROM THE PDF" << std::endl;
    MutantStack<int>    mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << std::endl;

    std::cout << "SAME BUT WITH std::list (it should give the same output)" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "top: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "size after pop: " << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::cout << std::endl;

    std::cout << "CONST ITERATOR" << std::endl; // tests that iteration works on a const MutantStack
    const MutantStack<int> cmstack(mstack);
    MutantStack<int>::const_iterator citstart = cmstack.begin();
    MutantStack<int>::const_iterator citend = cmstack.end();
    while (citstart != citend) {
        std::cout << *citstart << std::endl;
        ++citstart;
    }

    std::cout << std::endl;

    std::cout << "COPY IS INDEPENDENT" << std::endl; // tests that copy constructor does a deep copy, so modifying the copy doesn't affect the original
    MutantStack<int> mstack2(mstack);
    mstack2.push(156);
    std::cout << "original size: " << mstack.size() << std::endl;
    std::cout << "copy size:     " << mstack2.size() << std::endl;

    std::cout << std::endl;

    std::cout << "EMPTY STACK ITERATION" << std::endl; // iterate on empty stack doesn't crash
    MutantStack<int> empty;
    MutantStack<int>::iterator eit = empty.begin();
    MutantStack<int>::iterator eite = empty.end();
    while (eit != eite) {
        std::cout << *eit << std::endl;
        ++eit;
    }
    std::cout << "no crash, size: " << empty.size() << std::endl;

    // std::cout << "BIG STACK TEST" << std::endl;
    // MutantStack<int> big;
    // big.push(108); big.push(111); big.push(93);  big.push(156); big.push(777);
    // big.push(36);  big.push(12);  big.push(333); big.push(444); big.push(999);
    // big.push(72);  big.push(216); big.push(432); big.push(864); big.push(1728);
    // big.push(11);  big.push(22);  big.push(33);  big.push(44);  big.push(55);
    // MutantStack<int>::iterator bit = big.begin();
    // MutantStack<int>::iterator bite = big.end();
    // while (bit != bite) {
    //     std::cout << *bit << std::endl;
    //     ++bit;
    // }

    return 0;
}
