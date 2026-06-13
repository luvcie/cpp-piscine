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
    virtual void makeSound() const;
    std::string getType() const; // const on the right of a signature means
                                 // "this method promises not to modify the object"
                                 // because a getter should only read and not write
};

#endif
