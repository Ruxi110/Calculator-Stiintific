#pragma once
#include <iostream>
#include <string>
#include <cctype>  
#include <cstdlib>
#include <exception>
using namespace std;

class Calculator {
private:
    int const id;
    string expresie;
    double* operanzi = nullptr;
    int nrOperanzi = 0;
    char operatori[100];
    int nrOperatori = 0;
    static int GENERATOR_ID;
    string sirExtras;
    void Token();
    double extragereNumar(int index);
public:

    string getExpresie();

    void setExpresie(string expresie);
        int getId();

        double* getOperanzi();

        void setOperanzi(double* vector, int nrElem);

        char* getOperatori();

        void setOperatori(char* operatori, int nrElem);


        int getNrOperatori();

        void setNrOperatori(int nrOperatori);
            static int getGeneratorId();

            static void setGeneratoriId(int startId);
                Calculator();

                Calculator(string expresie, int idEcuatie);


    
                ~Calculator();

                void operator=(Calculator c);

                double operator[](int index);

                bool operator==(int x);

    friend bool operator==(int x, Calculator c);
    friend ostream& operator<<(ostream& out, Calculator c);
};



