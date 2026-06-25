#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>  // strtod
#include <cmath>    // isnan, isinf
#include <climits>  // INT_MIN, INT_MAX
#include <cctype>   // isprint, isdigit
#include <iomanip>  // setprecision, fixed

static bool isCharLiteral(const std::string& str) { // works without &/ref too but apparently
                                                    // it's better practice to pass a pointer
                                                    // to the xisting string instead of the value
                                                    // std::string is a class, so every std::string is
                                                    // an object. always pass objects by pointer
                                                    // and primitives (char, ) by value.
    // if 1 len so that it's a character, str[0] so it's that char as well
    // and static cast to unsigned char before passing to isdigit which
    // returns true if it's not (!) a digit
    if (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0]))) {
        return true;
    }
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') {
        return true;
    }
    return false;
}
                                     // from <cmath>
static void printChar(double d) {    // isnan(d) returns true if d is nan (not a number)
                                     // isinf(d) returns true if d is +inf or -inf (inf is when it goes past the maximum representable number)
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) {
        std::cout << "impossible" << std::endl;
    }
    else if (!std::isprint(static_cast<int>(d))) { // !isprint returns true if a character is not printable
                                                   // casting to int beause std::isprint takes an int
        std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
                        // converts oduble to char and displays character
}

static void printInt(double d) {
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX)) {
        std::cout << "impossible" << std::endl;
    }
    else
        std::cout << static_cast<int>(d) << std::endl;
}

static void printFloat(double d) {
    float floatie = static_cast<float>(d);          // casting the double to float
    std::cout << "float: ";
    if (std::isnan(floatie)) {
        std::cout << "nanf" << std::endl;
    }
    else if (std::isinf(floatie)) {
        std::cout << (floatie > 0 ? "+inff" : "-inff") << std::endl;
    }
    else if (floatie == std::floor(floatie))  // floor() rounds down to the nearest whole number
                                              // so if x equals its own floor it has no fractional part (like 36.0)
        std::cout << std::fixed << std::setprecision(1) << floatie << "f" << std::endl;  // so force the .0 like the subject wants (42.0f and not just 42)
    else
        std::cout << floatie << "f" << std::endl;  // but if it has actual decimals (93.11) just let it print it as is, otherwise setprecision(1) would reduce it to 93.1
}

static void printDouble(double d) {
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan" << std::endl;
    else if (std::isinf(d))
        std::cout << (d > 0 ? "+inf" : "-inf") << std::endl; // to decide if it should be positive infinite or negative infinite tbqdesu
    else if (d == std::floor(d))    // same idea as printFloat, if d equals its own floor it's a whole number so display the .0
        std::cout << std::fixed << std::setprecision(1) << d << std::endl;
                                    // setprecision sets how many decimal places to print
                                    // std::fixed makes it use fixed point notation instead of scientific (1e+16)
                                    // so for example it would print 16.0 instead of 1.6e1
    else
        // reset the fixed/setprecision(1) that printFloat may have left on cout, otherwise this real-decimal value would print under those leaked settings
        std::cout << std::resetiosflags(std::ios::floatfield) << std::setprecision(6) << d << std::endl;

}

void ScalarConverter::convert(const std::string& literal) {
    double d;
    if (isCharLiteral(literal)) {
                 // the condition of this ternary is if the length of the liteal is 3
                 // then if it's 3 then take the middle character a (because it owuld have the ' thingies, 'a')
                 // if it's not lenght 3 it means its just a bare a
        char characteroid = (literal.length() == 3) ? literal[1] : literal[0];
        d = static_cast<double>(characteroid);   // then cast the character to double a to store in d
                                                 // because all the print functions take a double tbqdesu
    }
    else { // so if isCharLiteral returned false...... the input is not a single char, it's an int float or double or nan/inf ! to be completely honest you know
        char* rest;
        d = std::strtod(literal.c_str(), &rest);  // rest = leftover string strtod couldn't parse
        // reject junk ("", "abc", "42abc"), but allow a single 'f' at the end so 42.0f, +inff and nanf still work
        if (rest == literal.c_str() || (*rest != '\0' && !(rest[0] == 'f' && rest[1] == '\0'))) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }

    printChar(d);                                       // print all of them
    printInt(d);                                        // to be tbh :)
    printFloat(d);
    printDouble(d);
}
