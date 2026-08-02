#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <list>

RPN::RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }
RPN::~RPN() {}

int RPN::evaluate(const std::string& expr) const {
    std::stack<int, std::list<int> > stack;
    std::istringstream stream(expr);
    std::string token;

    while (stream >> token) {
        if (token.length() == 1 && std::isdigit(token[0])) {
            stack.push(token[0] - '0'); // '0' is 48 in ASCII, so '3' - '0' = 3
        } else if (token.length() == 1 &&
                   (token[0] == '+' || token[0] == '-' ||
                    token[0] == '*' || token[0] == '/')) {
            if (stack.size() < 2)
                throw std::runtime_error("Error: not enough operands for '" + token + "'");
            int right = stack.top(); stack.pop(); // last number pushed = right side
            int left  = stack.top(); stack.pop(); // the one before it = left side
            if (token[0] == '+')      stack.push(left + right);
            else if (token[0] == '-') stack.push(left - right);
            else if (token[0] == '*') stack.push(left * right);
            else {
                if (right == 0)
                    throw std::runtime_error("Error: division by zero");
                stack.push(left / right);
            }
        } else {
            throw std::runtime_error("Error: unknown token '" + token + "'");
        }
    }
    // a valid expression always leaves exactly one number on the stack
    if (stack.size() != 1)
        throw std::runtime_error("Error: too many operands, missing operators");
    return stack.top();
}
