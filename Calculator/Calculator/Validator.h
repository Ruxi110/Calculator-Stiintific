#pragma once
#include <string>
using namespace std;
class Validator {
private: 
    bool rezultat=false;
public:
    static bool expresieValida(const string& expression);
    static bool parantezeRotunde(const string& expression);
    static bool parantezePatrate(const string& expression);
};


