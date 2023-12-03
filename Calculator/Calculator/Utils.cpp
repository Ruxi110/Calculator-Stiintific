#include <iostream>
#include <string>
#include <cctype>  
#include <cstdlib>
#include <exception>
#include "Utils.h"
using namespace std;

    double* Utils:: copiereVector(double* vector, int nrElemente) {
        if (vector == nullptr) {
            return nullptr;
        }

        double* vectorNou = new double[nrElemente];
        for (int i = 0; i < nrElemente; i++)
        {
            vectorNou[i] = vector[i];
        }
        return vectorNou;
    }

    string* Utils:: copiereString(string* vector, int nrElemente) {

        if (vector == nullptr) {
            return nullptr;
        }

        string* vectorNou = new string[nrElemente];
        for (int i = 0; i < nrElemente; i++) {
            vectorNou[i] = vector[i];
        }
        return vectorNou;
    }
