#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void) {
    /* ABSTRACT TEST
    if it gets uncommented then compiler error because
    Animal is abstract and can't instantiate (instantiate means create an object) */

    // Animal test;
    
    std::cout << "PDF EXAMPLE" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << std::endl << "ARRAY OF 10 ANIMALS" << std::endl;
    Animal* animals[10];

    for (int k = 0; k < 5; k++)
        animals[k] = new Dog();
    for (int k = 5; k < 10; k++)
        animals[k] = new Cat();

    std::cout << std::endl << "getType TEST" << std::endl;
    for (int k = 0; k < 10; k++)
        std::cout << animals[k]->getType() << std::endl;

    for (int k = 0; k < 10; k++)
        delete animals[k];

    std::cout << std::endl << "DEEP COPY CHECK" << std::endl;
    Dog original;
    original.getBrain()->setIdea(0, "eat chicken numgets");
    Dog copy = original;
    std::cout << "original brain address: " << original.getBrain() << std::endl;
    std::cout << "copy brain address:     " << copy.getBrain() << std::endl;
    std::cout << "original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "copy idea[0]:     " << copy.getBrain()->getIdea(0) << std::endl;

    std::cout << std::endl << "SCOPE TEST (shallow copy would crash here)" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    }
    std::cout << "basic survived tmp going out of scope :3" << std::endl;

    std::cout << std::endl << "STACK ALLOCATION TEST" << std::endl;
    Dog stackDog;
    Cat stackCat;

    return 0;
}
