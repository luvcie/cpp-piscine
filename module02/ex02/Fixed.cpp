#include "Fixed.hpp"
#include <cmath>

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

int Fixed::getRawBits() const {
    return this->value;
}

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : value(n << fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatie) : value(roundf(floatie *(1 << fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat() const {
    return (float)this->value / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return this->value >> fractionalBits;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->value > other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->value >= other.value;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->value < other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->value != other.value;
}

// articmetic done with float, float constructor rounds back to a raw val

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->value++;
    return tmp;
}

Fixed& Fixed::operator--() {
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->value--;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b; // [condition] [?] [valueIfTrue] : [valueIfFalse]
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
