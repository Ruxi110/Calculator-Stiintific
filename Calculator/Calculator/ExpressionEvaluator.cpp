#include <iostream>
#include <string>
#include <cctype>  
#include <cstdlib>
#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator() : outputIndex(-1), operatorIndex(-1), stackIndex(-1) {}

bool ExpressionEvaluator::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int ExpressionEvaluator::getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void ExpressionEvaluator::pushToOutput(char element) {
    if (outputIndex < MAX_SIZE - 1) {
        outputQueue[++outputIndex] = element;
    }
    else {
        cerr << "eroare" << endl;
        exit(EXIT_FAILURE);
    }
}

void ExpressionEvaluator::pushToOperatorStack(char element) {
    if (operatorIndex < MAX_SIZE - 1) {
        operatorStack[++operatorIndex] = element;
    }
    else {
        cerr << "Operator invalid" << endl;
        exit(EXIT_FAILURE);
    }
}

char ExpressionEvaluator::popFromOperatorStack() {
    if (operatorIndex >= 0) {
        return operatorStack[operatorIndex--];
    }
    else {
        cerr << "index invalid" << endl;
        exit(EXIT_FAILURE);
    }
}

void ExpressionEvaluator::pushOperand(int operand) {
    if (stackIndex < MAX_SIZE - 1) {
        operandStack[++stackIndex] = operand;
    }
    else {
        cerr << "index invalid" << endl;
        exit(EXIT_FAILURE);
    }
}

int ExpressionEvaluator::popOperand() {
    if (stackIndex >= 0) {
        return operandStack[stackIndex--];
    }
    else {
        cerr << "invalid index" << endl;
        exit(EXIT_FAILURE);
    }
}

string ExpressionEvaluator::infixToPostfix(const std::string& infixExpression) 
{
    for (char token : infixExpression) {
        if (isalnum(token)) {
            pushToOutput(token);
        }
        else if (isOperator(token)) {
            while (operatorIndex >= 0 && isOperator(operatorStack[operatorIndex]) &&
                getPrecedence(operatorStack[operatorIndex]) >= getPrecedence(token)) {
                pushToOutput(popFromOperatorStack());
            }
            pushToOperatorStack(token);
        }
        else if (token == '(') {
            pushToOperatorStack(token);
        }
        else if (token == ')') {
            while (operatorIndex >= 0 && operatorStack[operatorIndex] != '(') {
                pushToOutput(popFromOperatorStack());
            }
            if (operatorIndex >= 0 && operatorStack[operatorIndex] == '(') {
                popFromOperatorStack();
            }
            else {
                std::cerr << "eroare" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    while (operatorIndex >= 0) {
        if (operatorStack[operatorIndex] == '(' || operatorStack[operatorIndex] == ')') {
            std::cerr << "Mismatched parentheses." << std::endl;
            exit(EXIT_FAILURE);
        }
        pushToOutput(popFromOperatorStack());
    }

    return std::string(outputQueue, outputIndex + 1);
}

int ExpressionEvaluator::evaluatePostfix(const std::string& postfixExpression) {
    for (char token : postfixExpression) {
        if (isdigit(token)) {
            pushOperand(token - '0');
        }
        else if (isOperator(token)) {
            int operand2 = popOperand();
            int operand1 = popOperand();
            int result = performOperation(token, operand1, operand2);
            pushOperand(result);
        }
    }

    if (stackIndex == 0) {
        return operandStack[stackIndex];
    }
    else {
        std::cerr << "Error: Invalid postfix expression." << std::endl;
        exit(EXIT_FAILURE);
    }
}

int ExpressionEvaluator::performOperation(char op, int operand1, int operand2) {
    switch (op) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 != 0) {
            return operand1 / operand2;
        }
        else {
            std::cerr << "nu se poate imparti prin 0" << std::endl;
            exit(EXIT_FAILURE);
        }
    default:
        std::cerr << "operator invalid" << std::endl;
        exit(EXIT_FAILURE);
    }
}
