#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n) {}

Span::Span(const Span& other) : maxSize(other.maxSize), numbers(other.numbers) {}

Span& Span::operator=(const Span& other) {
    if (this == &other)
        return *this;
    maxSize = other.maxSize;
    numbers = other.numbers;
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (numbers.size() >= maxSize) {
        throw std::runtime_error("span is full");
    }
    numbers.push_back(n);
}

int Span::longestSpan() const {
    if (numbers.size() < 2)
        throw std::runtime_error("not enough numbers to find a span");
    return *std::max_element(numbers.begin(), numbers.end())
         - *std::min_element(numbers.begin(), numbers.end());
}

// a vector is a dynamic array
// it grows when you push_back and it shrinks with pop_back()
// .size() is a method in std::vector that returns how many elements are inside
int Span::shortestSpan() const {
    if (numbers.size() < 2)
        throw std::runtime_error("not enough numbers to find a span");
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end()); // sorts elements in ascending order, takes begin and end iterators, it modifies the container directly
    std::vector<int> diffs(sorted.size()); // pre-alocating space so that adjacent_difference has a place to write the output
    std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin()); // takes 3 args, where to start reading, where to stop reading, and where to start writing the output
    // adjacent_difference calculates all gaps but doesn't say which one is smallest, it just fills diffs
    // so with min_element() i scan diffs and pick the smallest one
    return *std::min_element(diffs.begin() + 1, diffs.end()); // stD::min_element scans a range and returns an iterator pointing at the smallest value, +1 to slop first element
}

// adjacent_difference writes differences between consecutive elements into diffs
// diffs[0] = sorted[0], diffs[1] = sorted[1]-sorted[0], diffs[2] = sorted[2]-sorted[1]...
/*  sorted = [3, 6, 9, 11, 17]
    diffs  = [3, 3, 3,  2,  6]
              ^  ^  ^   ^   ^
              |  |  |   |   17-1
              |  |  |   11-9
              |  |  9-6
              |  6-3
              3
*/
