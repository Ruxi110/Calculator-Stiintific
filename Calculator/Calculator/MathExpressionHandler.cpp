//
//#include <iostream>
//#include <string>
//#include <cctype>  
//#include <cstdlib>
//#include <exception>
//#include <sstream>
//#include "MathExpressionHandler.h"
//using namespace std;
//
//
//
//    MathExpressionHandler:: MathExpressionHandler(const std::string& expression) : expression_(expression) {}
//
//    string MathExpressionHandler::getExpression() {
//        return expression_;
//    }
//
//    void MathExpressionHandler::setExpression(string expression) {
//        expression_ = expression;
//    }
//
//    double MathExpressionHandler:: evaluate() {
//
//
//        std::istringstream input(expression_);
//
//        double number;
//        char op, lastOp = '\0';
//
//        while (input >> number) {
//            values[valIndex++] = number;
//
//            while (input >> op) {
//                if (op == ' ') {
//                    continue;
//                }
//
//                if (op == '+' || op == '-') {
//                    while (opIndex > 0 && (operators[opIndex - 1] == '+' || operators[opIndex - 1] == '-' || operators[opIndex - 1] == '*' || operators[opIndex - 1] == '/')) {
//                        applyOperator(values, operators[--opIndex], valIndex);
//                    }
//                    operators[opIndex++] = op;
//                }
//                else if (op == '*' || op == '/') {
//                    while (opIndex > 0 && (operators[opIndex - 1] == '*' || operators[opIndex - 1] == '/')) {
//                        applyOperator(values, operators[--opIndex], valIndex);
//                    }
//                    operators[opIndex++] = op;
//                }
//                else if (op == '(') {
//                    operators[opIndex++] = op;
//                }
//                else if (op == ')') {
//                    while (opIndex > 0 && operators[opIndex - 1] != '(') {
//                        applyOperator(values, operators[--opIndex], valIndex);
//                    }
//                    opIndex--; 
//                }
//                else {
//                    input.putback(op);
//                    break;
//                }
//            }
//            lastOp = '\0';
//        }
//
//        while (opIndex > 0) {
//            applyOperator(values, operators[--opIndex], valIndex);
//        }
//
//        return values[0];
//    }
//
//
//    void MathExpressionHandler:: applyOperator(double values[], char op, int& valIndex) {
//        double right = values[--valIndex];
//        double left = values[--valIndex];
//
//        switch (op) {
//        case '+':
//            values[valIndex++] = left + right;
//            break;
//        case '-':
//            values[valIndex++] = left - right;
//            break;
//        case '*':
//            values[valIndex++] = left * right;
//            break;
//        case '/':
//            if (right != 0.0) {
//                values[valIndex++] = left / right;
//            }
//            else {
//                std::cerr << "nu se poate imparti prin 0" << std::endl;
//            }
//            break;
//        }
//    }
//
//  
//
