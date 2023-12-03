
#pragma once

#include <iostream>
#include <string>

class Parser {
private:
    std::string* lista = nullptr;
    int nrElemLista = 0;
    char operatori[100];
    int nrElementeOperatori = 0;
    std::string expresie;
    std::string sirExtras;

public:
    Parser();
    explicit Parser(std::string expresie);

    std::string* getLista();
    char* getOperatori();
    int getNrElementeOperatori();
    std::string getExpresie();
    void setExpresie(std::string expresie);
    void afisareLista();
    std::string extragereNumar(int index);
    void prelucrareExpresie();

    bool operator!();
    explicit operator std::string();
    friend std::ostream& operator<<(std::ostream& out, const Parser& p);
};

std::ostream& operator<<(std::ostream& out, const Parser& p);
