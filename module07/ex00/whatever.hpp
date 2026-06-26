#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// needs to be exactly above the function it applies to
template <typename T> 
void swap(T& a, T& b) {
  T var = a;
  a = b;
  b = var;
}

template <typename T>
T const& min(T const& a, T const& b) {
  return (a < b) ? a : b;
}

template <typename T>
T const& max(T const& a, T const& b) {
  return (a > b) ? a : b;
}

#endif
