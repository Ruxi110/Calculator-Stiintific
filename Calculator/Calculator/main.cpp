#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>  
#include<sstream>
#include <cstdlib>
#include "ExpressionEvaluator.h"
#include "Calculator.h"
#include "Parser.h"
#include "Utils.h"


int main() {
    std::string inputExpression;
    std::cout << "Enter a mathematical expression: ";
    std::getline(std::cin, inputExpression);

    Tokenizer tokenizer(std::move(inputExpression));
    tokenizer.tokenize();

    ExpressionEvaluator expressionEvaluator(tokenizer.getTokens(), tokenizer.getNumTokens());
    double result = expressionEvaluator.evaluate();

    std::cout << "Result: " << result << std::endl;

    return 0;
}