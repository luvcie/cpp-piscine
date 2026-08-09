#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <climits>
#include <list>

RPN::RPN() {}
RPN::RPN(const RPN&) {}
RPN& RPN::operator=(const RPN&) { return *this; }
RPN::~RPN() {}

int RPN::evaluate(const std::string& expr) const {
    std::list<int> stack; // a list used as a stack, push and pop from the back
    std::istringstream stream(expr);
    std::string token;

    while (stream >> token) {
        if (token.length() == 1 && std::isdigit(token[0])) {
            stack.push_back(token[0] - '0'); // '0' is 48 in ASCII, so '3' - '0' = 3
        } else if (token.length() == 1 &&
                   (token[0] == '+' || token[0] == '-' ||
                    token[0] == '*' || token[0] == '/')) {
            if (stack.size() < 2)
                throw std::runtime_error("Error: not enough numbers for '" + token + "'");
            int right = stack.back(); stack.pop_back(); // last number pushed = right side
            int left  = stack.back(); stack.pop_back(); // the one before it = left side
            // done in long because overflowing an int is undefined behaviour, and two
            // ints can never overflow a 64 bit long, so the check below is always valid
            long res;
            if (token[0] == '+')      res = static_cast<long>(left) + right;
            else if (token[0] == '-') res = static_cast<long>(left) - right;
            else if (token[0] == '*') res = static_cast<long>(left) * right;
            else {
                if (right == 0)
                    throw std::runtime_error("Error: division by zero");
                res = left / right;
            }
            if (res > INT_MAX || res < INT_MIN)
                throw std::runtime_error("Error: the result does not fit in an int");
            stack.push_back(static_cast<int>(res));
        } else {
            throw std::runtime_error("Error: unknown token '" + token + "'");
        }
    }
    // a valid expression always leaves exactly one number on the stack
    if (stack.empty())
        throw std::runtime_error("Error: no numbers in the expression");
    if (stack.size() != 1)
        throw std::runtime_error("Error: too many numbers left, missing an operator");
    return stack.back();
}
