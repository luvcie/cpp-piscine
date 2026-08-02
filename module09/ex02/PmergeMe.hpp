#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
  private:
    std::vector<int> vec;
    std::deque<int>  deq;

    void sortVec(std::vector<int>& v);
    void sortDeq(std::deque<int>& d);

  public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void parse(int argc, char** argv);
    void run();
};

#endif
