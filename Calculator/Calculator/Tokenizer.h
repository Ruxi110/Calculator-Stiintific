#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Tokenizer {
private:
    void addToken(const std::string& token);

    void resizeTokensArray();

    void clearTokens();

    std::string expression_;
    char** tokens_;
    size_t numTokens_;
    size_t capacity_;

    bool isOperator(const char* token);
public:
    Tokenizer(std::string expression);
    Tokenizer();
    ~Tokenizer();
    void setExpresie(string expresie);
    string getExpresie();
    Tokenizer(Tokenizer& t);
    void operator=(Tokenizer t);
    void tokenize();
    char** getTokens();
    size_t getNumTokens();
    explicit operator string();
    bool operator!();
};