#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdexcept> // std::out_of_range

// class template array
template <typename T>
class Array {
    private:
    // contains elements of type T
    T*  data;       // pointer to the allocated memory (the array)
    unsigned int    len; // how many elements were allocated
                         // so that size can return it and operator[] can check bounds
    public:
    // 1. constructor with no parameter: creates an empty array
    Array() : data(NULL), len(0) {} // it's a template so it's ok to implement in header
    // 2. constructor with an unsigned int n as a parameter:
    // creates an array of n elements initialized by default
    Array(unsigned int n) : data(new T[n]()), len(n) {}
    // 3. consructor by copy
    Array(const Array& other) : data(new T[other.len]()), len(other.len) {
        for (unsigned int i = 0; i < len; ++i)
            data[i] = other.data[i];
    }
    // 4. assignment operator
    Array& operator=(const Array& other) {
        if (this == &other)
            return *this;
        delete[] data;
        len = other.len;
        data = new T[len]();
        for (unsigned int i = 0; i < len; ++i)
            data[i] = other.data[i];
        return *this;
    }

    // 5. subscript operator: [] overloaded two times so that the
    // compiler picks one or the other based on whether the array
    // object is const or not
    // Array<int> arr(5);
    // const Array<int> arr(5);
    T& operator[](unsigned int i) {
        if (i >= len)
            throw std::out_of_range("index out of range");
        return data[i];
    }

    T const& operator[](unsigned int i) const {
        if (i >= len)
            throw std::out_of_range("index out of range");
        return data[i];
    }

    // 6. a member function size() that returns the numbers of elements in the array
    // it takes no parameters and must not modify the current instance
    unsigned int size() const { return len; }

    // 7. destructor ofc
    ~Array() { delete[] data; }
};

#endif
