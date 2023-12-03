
#include <iostream>
#include <string>
#include <cctype>  
#include <cstdlib>
#include <exception>
#include "Calculator.h"

using namespace std;

string Calculator:: getExpresie() {
    return expresie;
}

void Calculator:: setExpresie(string expresie) {
    this->expresie = expresie;
}

int Calculator:: getId() {
    return id;
}

double* Calculator:: getOperanzi() {
    double* copie = new double[nrOperanzi];
    for (int i = 0; i < nrOperanzi;i++)
        copie[i] = operanzi[i];
    return copie;
}

void Calculator:: setOperanzi(double* vector, int nrElem) {
    if (operanzi != nullptr) {
        delete[] operanzi;
    }
    operanzi = new double[nrElem];
    for (int i = 0; i < nrElem;i++)
        operanzi[i] = vector[i];

    nrOperanzi = nrElem;
}

char* Calculator:: getOperatori() {
    char* copie = new char[nrOperatori];
    for (int i = 0; i < nrOperatori; i++)
    {
        copie[i] = operatori[i];
    }
    return copie;
}

void Calculator:: setOperatori(char* operatori, int nrElem) {
    for (int i = 0; i < nrElem; i++)
        this->operatori[i] = operatori[i];

    this->nrOperatori = nrElem;
}



int Calculator:: getNrOperatori() {
    return nrOperatori;
}

void Calculator:: setNrOperatori(int nrOperatori) {
    this->nrOperatori = nrOperatori;
}

int Calculator:: getGeneratorId() {
    return Calculator::GENERATOR_ID;
}

void Calculator:: setGeneratoriId(int startId) {
    Calculator::GENERATOR_ID = startId;
}

Calculator:: Calculator() :id(GENERATOR_ID) {
    expresie = "";
    operanzi = nullptr;
    nrOperanzi = 0;
    nrOperatori = 0;
    Calculator::GENERATOR_ID++;
}

Calculator:: Calculator(string expresie, int idEcuatie) :id(idEcuatie) {
    this->expresie = expresie;
    Calculator::GENERATOR_ID++;
}


double Calculator:: extragereNumar(int index) {
    sirExtras = "";
    double nrExtras = 0.0;
    if (index >= expresie.size()) {
        throw exception("index invalid");
    }

    while ((expresie[index] >= '0' && expresie[index] <= '9') || expresie[index] == '.') {
        sirExtras += expresie[index];
        index++;
        if (index >= expresie.size()) {
            break;
        }
    }
    if (!sirExtras.empty()) {
        nrExtras = stod(sirExtras);
    }
    return nrExtras;
}

void Calculator:: Token() {
    int i = 0;
    while (i < expresie.size())
    {
        if (expresie[i] == '*' || expresie[i] == '/' || expresie[i] == '+' || expresie[i] == '-') {
            operatori[i] = expresie[i];
            i++;
        }
        else if (expresie[i] == ' ') {
            i++;
        }
        else if ((expresie[i] >= '0' && expresie[i] <= '9') || expresie[i] == '.')
        {
            double* copie = new double[nrOperanzi];
            for (int i = 0; i < nrOperanzi; i++)
                copie[i] = operanzi[i];
            delete[] operanzi;
            operanzi = new double[nrOperanzi + 1];
            for (int i = 0; i < nrOperanzi; i++)
                operanzi[i] = copie[i];
            nrOperanzi++;
            operanzi[nrOperanzi - 1] = extragereNumar(i);
            i = i + sirExtras.size();
        }
    }
}

Calculator:: ~Calculator() {
    if (operanzi != nullptr) {
        delete[] operanzi;
        operanzi = nullptr;
        Calculator::GENERATOR_ID--;
    }
}

Calculator::Calculator(Calculator& c): id(c.id)
{
    this->expresie = c.expresie;
    this->setOperanzi(c.operanzi, c.nrOperanzi);
    this->setOperatori(c.operatori, c.nrOperatori);
}

void Calculator:: operator=(Calculator c) {
    this->expresie = c.expresie;
    this->setOperanzi(c.operanzi, c.nrOperanzi);
    this->setOperatori(c.operatori, c.nrOperatori);
}

double Calculator:: operator[](int index) {
    if (index >= 0 && index < nrOperanzi) {
        return operanzi[index];
    }
}

bool Calculator:: operator==(int x) {
    if (nrOperanzi + nrOperatori == x) return 1;
    else return 0;
}

ostream& operator<<(ostream& out, Calculator c) {
    out << c.nrOperanzi;
    out << endl;
    for (int i = 0; i < c.nrOperanzi;i++)
    {
        out << c.operanzi[i] << " ";
    }
    out << endl;
    out << c.nrOperatori;
    out << endl;
    for (int i = 0; i < c.nrOperatori; i++)
    {
        out << c.operatori[i] << " ";
    }
    return out;
}
istream& operator>>(istream& in, Calculator c)
{
    in >> c.expresie;
    return in;
}
bool operator==(int x, Calculator c)
{
    if (x == c.nrOperanzi + c.nrOperatori)
        return 1;
    else
        return 0;
}

int Calculator::GENERATOR_ID = 1;