//
//#pragma once
//
//#include <iostream>
//#include <string>
//using namespace std;
//class Parser {
//private:
//    std::string* lista = nullptr;
//    int nrElemLista = 0;
//    char operatori[100];
//    int nrElementeOperatori = 0;
//    std::string expresie;
//    std::string sirExtras;
//
//public:
//    Parser();
//    explicit Parser(string expresie);
//
//    string* getLista();
//    char* getOperatori();
//    int getNrElementeOperatori();
//    string getExpresie();
//    void setExpresie(std::string expresie);
//    void afisareLista();
//    void operator=(Parser p);
//    string extragereNumar(int index);
//    void prelucrareExpresie();
//    ~Parser();
//
//    Parser(Parser& p);
//    bool operator!();
//    explicit operator string();
//    friend istream& operator>>(istream& in, Parser& p);
//    friend ostream& operator<<(ostream& out, const Parser& p);
//};
//
//ostream& operator<<(ostream& out, const Parser& p);
//istream& operator>>(istream& in, Parser& p);
