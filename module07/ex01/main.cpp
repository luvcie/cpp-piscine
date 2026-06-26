#include "iter.hpp"
#include <iostream>
#include <string>
#include <cctype>  // toupper

template <typename T>
void print(T const& x) {
    std::cout << x << std::endl;
}

template <typename T>
void doubleIt(T& x) {
    x = x * 2;
}

void scream(std::string& str) {
    for (std::size_t i = 0; i < str.length(); i++)
        str[i] = static_cast<char>(std::toupper(str[i]));
    str += "!!!";
}

int main(void) {
    std::cout << "INT ARRAY PRINT TEST" << std::endl;
    int arr[10] = {0, 1, 2, 3, 4, 93, 36, 777, 111, 333};
    iter(arr, 10, print<int>);

    std::cout << std::endl;

    std::cout << "DOUBLE INT ARRAY TEST" << std::endl;
    iter(arr, 10, doubleIt<int>);
    iter(arr, 10, print<int>);

    std::cout << std::endl;

    std::cout << "STRING ARRAY PRINT TEST" << std::endl;
    std::string words[3] = {"lucie", "loves", "cats"};
    iter(words, 3, print<std::string>);

    std::cout << std::endl;

    std::cout << "SCREAM TEST" << std::endl;
    iter(words, 3, scream);
    iter(words, 3, print<std::string>);

    return 0;
}
