#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>

class ScalarConverter {
  private: // non instantiable
  // having ctors and dtor in private communicates that it's just to be used by the convert function
  // and not to be used outside it! since the class doesn't have data/anyhting to construct, copy, etc
  // anyway the ctors and dtor are not needed but if i don't declare them c++98 would do it anyway
  // so it's better tojust declare them as private
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
  public:
    static void convert(const std::string& literal);
    // static because i call it without an object
};

#endif
