
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>  
#include <cstdlib>
#include <cstring>
#include <exception>
#include <sstream>
#include "ExpressionEvaluator.h"

    ExpressionEvaluator:: ExpressionEvaluator(char** tokens, size_t numTokens) : tokens_(tokens), numTokens_(numTokens), currentIndex_(0), result_(0.0) {}
    ExpressionEvaluator:: ExpressionEvaluator() {
        tokens_ = nullptr;
        numTokens_ = 0;
        currentIndex_ = 0;
        result_ = 0.0;
    }


    ExpressionEvaluator::ExpressionEvaluator(ExpressionEvaluator& t) {
        numTokens_ = t.numTokens_;
        currentIndex_ = t.currentIndex_;
        result_ = t.result_;

        tokens_ = new char* [t.numTokens_];
        for (int i = 0; i < t.numTokens_; i++)
            tokens_[i] = new char[strlen(t.tokens_[i]) + 1];

        for (int i = 0; i < t.numTokens_; i++)
            strcpy_s(tokens_[i], strlen(t.tokens_[i]) + 1, t.tokens_[i]);
    }

    void ExpressionEvaluator:: operator=(ExpressionEvaluator t) {
        if (&t == this) {
            return;
        };

        numTokens_ = t.numTokens_;
        currentIndex_ = t.currentIndex_;
        result_ = t.result_;
        /*if (tokens_ != nullptr) {
            for (size_t i = 0; i < numTokens_; ++i) {
                delete[] tokens_[i];
            }

            delete[] tokens_;
        }*/

        tokens_ = new char* [t.numTokens_];
        for (int i = 0; i < t.numTokens_; i++)
            tokens_[i] = new char[strlen(t.tokens_[i]) + 1];

        for (int i = 0; i < t.numTokens_; i++)
            strcpy_s(tokens_[i], strlen(t.tokens_[i]) + 1, t.tokens_[i]);
    }

    ExpressionEvaluator ExpressionEvaluator:: operator++() {
        result_++;
        return*this;
    }

    ExpressionEvaluator ExpressionEvaluator:: operator++(int i) {
        ExpressionEvaluator copie = *this;
        result_++;
        return copie;
    }
  

    double ExpressionEvaluator:: evaluate() {
        while (currentIndex_ < numTokens_) {
            if (tokens_[currentIndex_][0] == '+' || tokens_[currentIndex_][0] == '-' ||
                tokens_[currentIndex_][0] == '*' || tokens_[currentIndex_][0] == '/') {
                applyOperator(tokens_[currentIndex_][0]);
                currentIndex_++;
            }
            else {
                result_ = strtod(tokens_[currentIndex_], nullptr);
                currentIndex_++;
            }
        }

        return result_;
    }

    void ExpressionEvaluator:: applyOperator(char op) {
        double right = strtod(tokens_[++currentIndex_], nullptr);
        double left = result_;

        switch (op) {
        case '+':
            result_ = left + right;
            break;
        case '-':
            result_ = left - right;
            break;
        case '*':
            result_ = left * right;
            break;
        case '/':
            if (right != 0.0) {
                result_ = left / right;
            }
            else {
                std::cerr << "Error: Division by zero." << std::endl;
            }
            break;
        }
    }
