#include <cctype>
#include <iostream>

// toupper returns an int, so we need to cast
// i'm casting the C++ way which is... interesting
// static_cast is a template function
// it says "hey cpp compiler, copypaste this function
// and use that type i've given it", so in this case char
int main(int argc, char **argv) {
  for (int i = 1; i < argc; ++i) {
    char *str = argv[i];
    while (*str != 0) {
    std::cout << static_cast<char>(toupper(*str));
      ++str;
    }
  }
  std::cout << std::endl;
  return 0;
}
