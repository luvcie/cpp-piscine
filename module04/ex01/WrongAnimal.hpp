#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
  protected:
    std::string type;
  public:
    // OCF
    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal(std::string);
    WrongAnimal &operator=(const WrongAnimal &other);
    ~WrongAnimal();
    // removed virtual, not polymorphic anymore D:
    void makeSound() const;
    std::string getType() const; // const on the right of a signature means
                                     // "this method promises not to modify the object"
                                     // because a getter should only read and not write
};

#endif
