#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: needs a list of positive integers to sort" << std::endl;
        std::cerr << "use like this: ./PmergeMe 3 5 9 7 4" << std::endl;
        return 1;
    }
    try {
        PmergeMe sorter;
        sorter.parse(argc, argv);
        sorter.run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
