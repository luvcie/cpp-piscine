#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
  protected:
    std::string type;
  public:
    // OCF
    Animal();
    Animal(const Animal &other);
    Animal(std::string);
    Animal &operator=(const Animal &other);
    virtual ~Animal();
    // methods
    // an abstract function forces every subclass to implement it
    // if Dog forgets to implement makeSound() then it wont compile
    // this way it's impossibl to have a class that makes no sound
    // = 0 means the function doesn't need a body !
    virtual void makeSound() const = 0; // virtual + "= 0" means it's abstract.
    std::string getType() const; // const on the right of a signature means
                                 // "this method promises not to modify the object"
                                 // because a getter should only read and not write
};

#endif
