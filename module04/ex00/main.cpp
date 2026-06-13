#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  std::cout << "PDF EXAMPLE" << std::endl;
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << j->getType() << std::endl;
  std::cout << i->getType() << std::endl;
  i->makeSound();
  j->makeSound();
  meta->makeSound();
  delete meta;
  delete j;
  delete i;

  Animal* animals[4];

  animals[0] = new Dog();
  animals[1] = new Cat();
  animals[2] = new Dog();
  animals[3] = new Cat();

  std::cout << std::endl << "VIRTUAL TEST (good)" << std::endl;
  for (int i = 0; i < 4; ++i)
    animals[i]->makeSound();

  std::cout << std::endl << "getType TEST" << std::endl;
  for (int i = 0; i < 4; ++i)
    std::cout << animals[i]->getType() << std::endl;

  for (int i = 0; i < 4; ++i)
    delete animals[i];

  std::cout << std::endl << "NO VIRTUAL TEST USING WRONGANIMAL (wrong on purpose)" << std::endl;
  WrongAnimal* wrong = new WrongCat();
  std::cout << wrong->getType() << std::endl;
  wrong->makeSound();
  delete wrong;

  std::cout << std::endl << "STACK ALLOCATION TEST" << std::endl;
  Dog stackDog;
  Cat stackCat;

  /*
  std::cout << std::endl << "COPY CONSTRUCTOR TEST" << std::endl;
  Dog originalDog;
  Dog copiedDog(originalDog);
  std::cout << copiedDog.getType() << std::endl;

  std::cout << std::endl << "ASSIGNMENT OPERATOR TEST" << std::endl;
  Cat catA;
  Cat catB;
  catB = catA;
  std::cout << catB.getType() << std::endl;
  */

  return 0;
}
