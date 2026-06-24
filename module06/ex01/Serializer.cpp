#include "Serializer.hpp"

// serialization means converting data into a format that can be stored or transmitted
// a file, a network packet, a database...
// pointers can't be serialized directly because they're memory addresses that only
// make sense in the current running process, the address will  be different every time the program is run
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);  // converts pointer to unsigned integer (now the addrss is just a number and it can be stored or sent)
        // reinterpret_cast doesn't change anything in memory, the bits stay exactly the same
        // it just tells the compiler "treat these bits as a uintptr_t now instead of a pointer"
        // (the decimal printed is just how cout displays integers, not a memory change)
}

// deserialize converts it back
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);      // converts unsigned integer back to pointer so it can use the object again
}
