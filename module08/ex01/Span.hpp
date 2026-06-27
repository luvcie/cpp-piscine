#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm> // sort, min_element, max_element, adjacent difference
#include <numeric> // adjacent difference
#include <stdexcept> // runtime_error

class Span {
    private:
        unsigned int        maxSize;
        std::vector<int>    numbers;
    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        void addNumber(int n);

        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end) {
            if (numbers.size() + (unsigned int)std::distance(begin, end) > maxSize)
                throw std::runtime_error("span is full");
            numbers.insert(numbers.end(), begin, end);
        }
        int shortestSpan() const;
        int longestSpan() const;
};

#endif
