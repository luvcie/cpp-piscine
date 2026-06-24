#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.id    = 111;
    data.name  = "Dratini";
    data.value = 7.77;

    // before serialize &data is a pointer type, so cout sees the pointer and prints hexadecimal
    uintptr_t raw = Serializer::serialize(&data);  // calls serialize with the address of data (&data) which then will use reinterpret_cast to convert to int
    // after serialize raw becomes a uintptr_t (so an integer), cout sees integer and prints decimal
    // and what reinterpret_cast did was telling the compiler that the bits are now an integer type
    // the bits in ram don't change, it's just hte type label and cout uses that type label to decide how to print it
    Data*     ptr = Serializer::deserialize(raw);  // holds memory address of data object

    std::cout << "original pointer : " << &data      << std::endl;  // will show address in hexadecimal, a pointer is passed (&data), so shows in hexa
    std::cout << "serialized raw   : " << raw        << std::endl;  // will show in decimal, bc it was serialized to integer
    std::cout << "deserialized ptr : " << ptr        << std::endl;  // then back to hexa
    std::cout << "match            : " << (ptr == &data ? "yes" : "no") << std::endl; // ptr and &data must point to the same address
    std::cout << "data.id          : " << ptr->id    << std::endl;
    std::cout << "data.name        : " << ptr->name  << std::endl;
    std::cout << "data.value       : " << ptr->value << std::endl;
    return 0;
}
