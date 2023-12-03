#pragma once
#include <iostream>
#include <string>
#include <cctype>  
#include <cstdlib>
#include <exception>
using namespace std;

class Utils {
public:
    double* copiereVector(double* vector, int nrElemente);
    static string* copiereString(string* vector, int nrElemente);

};