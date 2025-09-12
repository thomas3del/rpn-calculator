#pragma once
#include <string>

/**
 * @brief Evaluates a mathematical expression in Reverse Polish Notation (RPN).
 * 
 * @param expression A string containing the RPN expression (e.g., "2 3 +").
 * Tokens must be separated by spaces.
 * @return double The result of the evaluated expression.
 * @exception std::invalid_argument Thrown if the expression is invalid,
 * contains an unknown operator, or attempts division by zero.
 */
double evaluate_rpn(const std::string& expression);
#pragma once
#include <string>
#include <cmath>

double evaluate_rpn(const std::string& expression);

// دوال رياضية إضافية
double rpn_sin(double angle);
double rpn_cos(double angle); 
double rpn_tan(double angle);
