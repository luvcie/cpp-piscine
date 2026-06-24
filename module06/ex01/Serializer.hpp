#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <stdint.h>  // uintptr_t
#include "Data.hpp"

class Serializer {
  private: // non instantiable
  // having ctors and dtor in private communicates that it's just to be used by the static methods
  // and not to be instantiated! since the class doesn't have data/anything to construct, copy, etc
  // anyway the ctors and dtor are not needed but if i don't declare them c++98 would do it anyway
  // so it's better to just declare them as private
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
  public:
    static uintptr_t  serialize(Data* ptr);     // seraialize returns an unsigned integer big enough to hold a pointer
    static Data*      deserialize(uintptr_t raw); // takes a pointer to a Data struct which is a memory address)
    // static because i call it without an object
};

#endif
