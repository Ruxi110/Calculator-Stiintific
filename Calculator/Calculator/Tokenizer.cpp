#define _CRT_SECURE_NO_WARNINGA
#include <iostream>

#include <sstream>
#include <cstring>
#include <cstdlib>
#include<string>
#include "Tokenizer.h"
using namespace std;

    Tokenizer:: Tokenizer(std::string expression) : expression_(std::move(expression)), tokens_(nullptr), numTokens_(0), capacity_(0) {}

    Tokenizer::Tokenizer() {
        tokens_ = nullptr;
        numTokens_ = 0;
        expression_ = "";
        capacity_ = 0;
    }

    void Tokenizer:: operator=(Tokenizer t) {
    if (this == &t)
        throw exception("deja egalitate");

    expression_ = t.expression_;
    if (tokens_ != nullptr) {
        for (int i = 0; i < numTokens_;i++)
            delete[] tokens_[i];

        delete[] tokens_;
    }


    tokens_ = new char* [t.capacity_];

    for (int i = 0; i < t.numTokens_; i++)
        tokens_[i] = new char[strlen(t.tokens_[i]) + 1];

    for (int i = 0; i < t.numTokens_;i++)
        strcpy_s(tokens_[i], strlen(t.tokens_[i]) + 1, t.tokens_[i]);

    numTokens_ = t.numTokens_;
    capacity_ = t.capacity_;

}

    Tokenizer::Tokenizer(Tokenizer& t) {
       expression_ = t.expression_;
       
       tokens_ = new char* [t.capacity_];

       for (int i = 0; i < t.numTokens_; i++)
           tokens_[i] = new char[strlen(t.tokens_[i]) + 1];

       for (int i = 0; i < t.numTokens_;i++)
           strcpy_s(tokens_[i], strlen(t.tokens_[i]) + 1, t.tokens_[i]);

       numTokens_ = t.numTokens_;
       capacity_ = t.capacity_;

   }

    string Tokenizer::getExpresie() {
        return expression_;
    }

    void Tokenizer::setExpresie(string expresie) {
        expression_ = expresie;
    }

    Tokenizer:: ~Tokenizer() {
        clearTokens();
    }


    void Tokenizer:: tokenize() {
        std::istringstream input(expression_);

        char ch;

        while (input >> ch) {
            if (std::isdigit(ch) || ch == '.' || (ch == '-' && (numTokens_ == 0 || (numTokens_ > 0 && isOperator(tokens_[numTokens_ - 1]))))) {
                input.putback(ch);
                double number;
                input >> number;
                addToken(std::to_string(number));
            }
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')') {
                addToken(std::string(1, ch));
            }
        }
    }

    char** Tokenizer:: getTokens() {
        return tokens_;
    }

    size_t Tokenizer:: getNumTokens() {
        return numTokens_;
    }

    void Tokenizer:: addToken(const std::string& token) {
        if (numTokens_ == capacity_) {
            resizeTokensArray();
        }

        tokens_[numTokens_] = new char[token.length() + 1];
        strcpy_s(tokens_[numTokens_], token.length() + 1, token.c_str());
        numTokens_++;
    }

    void Tokenizer::resizeTokensArray() {
        capacity_ = (capacity_ == 0) ? 1 : capacity_ * 2;
        char** newTokens = new char* [capacity_];

        for (size_t i = 0; i < numTokens_; ++i) {
            newTokens[i] = tokens_[i];
        }

        delete[] tokens_;
        tokens_ = newTokens;
    }

    void Tokenizer:: clearTokens() {
        for (size_t i = 0; i < numTokens_; ++i) {
            delete[] tokens_[i];
        }

        delete[] tokens_;
    }

    
    bool Tokenizer:: isOperator(const char* token) {
        return (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
    }


   Tokenizer:: operator string() {
        return expression_;
    }

   bool Tokenizer:: operator!() {
       if (capacity_ == 0) return 0;
       else return 1;
   }
