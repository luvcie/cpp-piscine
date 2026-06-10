#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int value;
        static const int fractionalBits  = 8;
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float floatie);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits() const; // const method promises not to change object it's called on
        void setRawBits(int const raw) ;
        float toFloat() const;
        int toInt() const;

        //comparison operators overloading, they compare the raw value
        bool operator>(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        // arithmeticks
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        // step up and down
        Fixed& operator++(); // ++a (pre) change then return new value
        Fixed operator++(int); // a++ post, return old value then change
        Fixed& operator--(); // --a pre,
        Fixed operator--(int); // a-- post

        // static so you call them as Fixed::min(a, b) without object
        // return  a reference to the smaller (mix) or greater (max) of the two
        // two versions of each to work on both normal and const Fixed
        static Fixed & min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

// free function (left operand is the stream, not a Fixed), prints the float value
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
