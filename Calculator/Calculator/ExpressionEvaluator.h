#pragma once
#include <iostream>
#include <string>
#include <cctype>  
#include <cstdlib>
#include <exception>

using namespace std;

const int MAX_SIZE = 100;

class ExpressionEvaluator {
private:
    char outputQueue[MAX_SIZE];
    char operatorStack[MAX_SIZE];
    int outputIndex;
    int operatorIndex;
    int operandStack[MAX_SIZE];
    int stackIndex;

public:
    ExpressionEvaluator();
    bool isOperator(char c);

    int getPrecedence(char op);  

    void pushToOutput(char element);

    void pushToOperatorStack(char element);

    char popFromOperatorStack();

    void pushOperand(int operand);

    int popOperand();

    string infixToPostfix(const std::string& infixExpression);

    int evaluatePostfix(const std::string& postfixExpression);

private:
    int performOperation(char op, int operand1, int operand2);
};
