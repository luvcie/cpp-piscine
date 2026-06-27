#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // std::find
#include <stdexcept> // std::runtime_error

// easyFind doesn't know or care what T is
// it just assumes T has begin(), end(), and a nested ::iterator type
// all STL containers have those
template <typename T>
typename T::iterator easyFind(T& container, int value) {
    // every STL container has begin() and end() built in
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("value not found") ;
    }
    return it;
}


#endif
