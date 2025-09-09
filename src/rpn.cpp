#include "rpn.h"
#include <sstream>
#include <stdexcept>
#include <stack>
#include <string>

double evaluate_rpn(const std::string& expression) {
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (token == "+") {
            if (stack.size() < 2) throw std::invalid_argument("Not enough operands for '+'");
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            stack.push(a + b);
        }
        else if (token == "-") {
            if (stack.size() < 2) throw std::invalid_argument("Not enough operands for '-'");
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            stack.push(a - b);
        }
        else if (token == "*") {
            if (stack.size() < 2) throw std::invalid_argument("Not enough operands for '*'");
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            stack.push(a * b);
        }
        else if (token == "/") {
            if (stack.size() < 2) throw std::invalid_argument("Not enough operands for '/'");
            double b = stack.top(); stack.pop();
            if (b == 0) throw std::invalid_argument("Division by zero");
            double a = stack.top(); stack.pop();
            stack.push(a / b);
        }
        else {
            try {
                double num = std::stod(token);
                stack.push(num);
            }
            catch (...) {
                throw std::invalid_argument("Invalid token: " + token);
            }
        }
    }
    
    if (stack.size() != 1) {
        throw std::invalid_argument("Invalid expression");
    }
    
    return stack.top();
}
