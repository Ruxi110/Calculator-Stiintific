#include <iostream>
#include <string>
#include <cctype>  
#include <cstdlib>
#include "Validator.h"


bool Validator::expresieValida(const std::string& expression) {
    
    for (char ch : expression) {
        if (!isdigit(ch) && !isspace(ch) && ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '(' && ch != ')' && ch != '[' && ch != ']') {
            return false;
        }
    }
    return true;
}

bool Validator::parantezeRotunde(const std::string& expression) {
    int nrDeschise = 0;
    int nrInchise = 0;

    for (char ch : expression) {
        if (ch == '(') {
            nrDeschise++;
        }
        else if (ch == ')') {
            nrInchise++;
        }
    }

    if (nrDeschise == nrInchise) return true;
    else return false;
}

bool Validator:: parantezePatrate(const std::string& expression) {
    int nrDeschise = 0;
    int nrInchise = 0;

    for (char ch : expression) {
        if (ch == '[') {
            nrDeschise++;
        }
        else if (ch == ']') {
            nrInchise++;
        }
    }

    if (nrDeschise == nrInchise) return true;
    else return false;
}
