#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : vec(other.vec), deq(other.deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        vec = other.vec;
        deq = other.deq;
    }
   return *this;
}

PmergeMe::~PmergeMe() {}

static double now() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts); // nanoseconds
    return ts.tv_sec * 1000000.0 + ts.tv_nsec / 1000.0;
}

// 1, 3, 5, 11, 21, 43 ... etc, each one is the previous plus twice the one before
static size_t jacobsthal(size_t n) {
    size_t a = 1;
    size_t b = 3;
    for (size_t i = 0; i < n; i++) {
        size_t next = b + 2 * a;
        a = b;
        b = next;
    }
    return a;
}

void PmergeMe::sortVec(std::vector<int>& v) {
    if (v.size() < 2)
        return;

    bool hasLeftover = (v.size() % 2 != 0);
    int  leftover = 0;
    if (hasLeftover) {
        leftover = v.back();
        v.pop_back();
    }

    // pair them up, bigger one first
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < v.size(); i += 2) {
        if (v[i] < v[i + 1])
            pairs.push_back(std::make_pair(v[i + 1], v[i]));
        else
            pairs.push_back(std::make_pair(v[i], v[i + 1]));
    }

    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); i++)
        winners.push_back(pairs[i].first);
    sortVec(winners);

    // pairs go back in their winner's order, placed[] separates equal winners
    std::vector<std::pair<int, int> > sorted(pairs.size());
    std::vector<size_t> placed(pairs.size(), 0);
    for (size_t i = 0; i < pairs.size(); i++) {
        size_t rank = std::lower_bound(winners.begin(), winners.end(), pairs[i].first)
                    - winners.begin();
        sorted[rank + placed[rank]] = pairs[i];
        placed[rank]++;
    }

    std::vector<int> chain;
    chain.push_back(sorted[0].second); // smaller than every winner, so it goes first for free
    for (size_t i = 0; i < sorted.size(); i++)
        chain.push_back(sorted[i].first);

    std::vector<int> losers;
    for (size_t i = 1; i < sorted.size(); i++)
        losers.push_back(sorted[i].second);

    // insert by the jacobsthal numbers, backwards in each group so searches stay even
    size_t limit = losers.size() + 1;
    size_t prev = 1;
    size_t k = 1;
    while (prev < limit) {
        size_t groupEnd = jacobsthal(k);
        if (groupEnd > limit)
            groupEnd = limit;
        for (size_t num = groupEnd; num > prev; num--) {
            size_t index = num - 2; // losers starts at the second one, so the number shifts by 2
            // upper_bound finds the partner, no need to search past it
            std::vector<int>::iterator bound =
                std::upper_bound(chain.begin(), chain.end(), sorted[index + 1].first);
            std::vector<int>::iterator pos =
                std::lower_bound(chain.begin(), bound, losers[index]);
            chain.insert(pos, losers[index]);
        }
        prev = groupEnd;
        k++;
    }

    if (hasLeftover) {
        std::vector<int>::iterator pos =
            std::lower_bound(chain.begin(), chain.end(), leftover);
        chain.insert(pos, leftover);
    }

    v.swap(chain);
}

// same algorithm as sortVec, written out again for the deque
void PmergeMe::sortDeq(std::deque<int>& d) {
    if (d.size() < 2)
        return;

    bool hasLeftover = (d.size() % 2 != 0);
    int  leftover = 0;
    if (hasLeftover) {
        leftover = d.back();
        d.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < d.size(); i += 2) {
        if (d[i] < d[i + 1])
            pairs.push_back(std::make_pair(d[i + 1], d[i]));
        else
            pairs.push_back(std::make_pair(d[i], d[i + 1]));
    }

    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); i++)
        winners.push_back(pairs[i].first);
    sortDeq(winners);

    std::deque<std::pair<int, int> > sorted(pairs.size());
    std::deque<size_t> placed(pairs.size(), 0);
    for (size_t i = 0; i < pairs.size(); i++) {
        size_t rank = std::lower_bound(winners.begin(), winners.end(), pairs[i].first)
                    - winners.begin();
        sorted[rank + placed[rank]] = pairs[i];
        placed[rank]++;
    }

    std::deque<int> chain;
    chain.push_back(sorted[0].second);
    for (size_t i = 0; i < sorted.size(); i++)
        chain.push_back(sorted[i].first);

    std::deque<int> losers;
    for (size_t i = 1; i < sorted.size(); i++)
        losers.push_back(sorted[i].second);

    size_t limit = losers.size() + 1;
    size_t prev = 1;
    size_t k = 1;
    while (prev < limit) {
        size_t groupEnd = jacobsthal(k);
        if (groupEnd > limit)
            groupEnd = limit;
        for (size_t num = groupEnd; num > prev; num--) {
            size_t index = num - 2;
            std::deque<int>::iterator bound =
                std::upper_bound(chain.begin(), chain.end(), sorted[index + 1].first);
            std::deque<int>::iterator pos =
                std::lower_bound(chain.begin(), bound, losers[index]);
            chain.insert(pos, losers[index]);
        }
        prev = groupEnd;
        k++;
    }

    if (hasLeftover) {
        std::deque<int>::iterator pos =
            std::lower_bound(chain.begin(), chain.end(), leftover);
        chain.insert(pos, leftover);
    }

    d.swap(chain);
}

void PmergeMe::validate(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);
        if (arg.empty())
            throw std::runtime_error("Error: empty argument");
        if (arg.find_first_not_of("0123456789") != std::string::npos)
            throw std::runtime_error("Error: '" + arg + "' is not a positive integer");
        long n = std::strtol(arg.c_str(), NULL, 10);
        if (n > INT_MAX)
            throw std::runtime_error("Error: '" + arg + "' is too large");
    }
    if (argc < 2)
        throw std::runtime_error("Error: no numbers given");
}

static void printSeq(const char* label, const std::vector<int>& v) {
    std::cout << label;
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

static void printArgs(const char* label, int argc, char** argv) {
    std::cout << label;
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::run(int argc, char** argv) {
    printArgs("Before: ", argc, argv);

    // the clock covers filling the container too, not just the sorting
    double vecStart = now();
    for (int i = 1; i < argc; i++)
        vec.push_back(static_cast<int>(std::strtol(argv[i], NULL, 10)));
    sortVec(vec);
    double vecEnd = now();

    double deqStart = now();
    for (int i = 1; i < argc; i++)
        deq.push_back(static_cast<int>(std::strtol(argv[i], NULL, 10)));
    sortDeq(deq);
    double deqEnd = now();

    printSeq("After:  ", vec);

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << vecEnd - vecStart << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << deqEnd - deqStart << " us" << std::endl;
}
