#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>   // size_t

// ::iter applies a function to every element of an array
// so instead of writing a loop every time
// i can just use ::iter
template <typename T, typename F>
void iter(T* array, std::size_t length, F function) {
    for (std::size_t i = 0; i < length; ++i) {
        function(array[i]);
    }
}

#endif
