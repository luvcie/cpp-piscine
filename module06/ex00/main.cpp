#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Odin and Thor have been angered." << std::endl;
        std::cerr << "Use it like this instead to appease them:" << std::endl;
        std::cerr << "./convert <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
