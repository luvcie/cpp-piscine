#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

// to inherit "keep the parents public things public in the child"
class Dog : public Animal {
  private:
    Brain* brain;
    
  public:
    Dog();
    Dog(const Dog &other);
    Dog & operator=(const Dog &other);
    ~Dog();
    // method
    void makeSound() const;
    Brain* getBrain() const;
};

#endif
