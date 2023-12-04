
#pragma
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include "Tokenizer.h"
class ExpressionEvaluator {
private:
    void applyOperator(char op);

    char** tokens_;
    size_t numTokens_;
    size_t currentIndex_;
    double result_;

public:
    ExpressionEvaluator(char** tokens, size_t numTokens);
    ExpressionEvaluator();  
   ExpressionEvaluator(ExpressionEvaluator& t);
   void operator=(ExpressionEvaluator t);
    double evaluate();

    ExpressionEvaluator operator++();
    ExpressionEvaluator operator++(int i);

};