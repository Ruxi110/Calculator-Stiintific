
#include "Parser.h"
#include "Utils.h"
using namespace std;

Parser::Parser() {
    lista = nullptr;
    nrElemLista = 0;
    nrElementeOperatori = 0;
    expresie = "";
    sirExtras = "";
}

Parser::Parser(std::string expresie) : expresie(expresie) {}

std::string* Parser::getLista() {
    std::string* copie = new std::string[nrElemLista];
    for (int i = 0; i < nrElemLista; i++)
        copie[i] = lista[i];
    return copie;
}

char* Parser::getOperatori() {
    char* copie = new char[nrElementeOperatori];
    for (int i = 0; i < nrElementeOperatori; i++)
        copie[i] = operatori[i];
    return copie;
}

int Parser::getNrElementeOperatori() {
    return nrElementeOperatori;
}

std::string Parser::getExpresie() {
    return expresie;
}

void Parser::setExpresie(std::string expresie) {
    this->expresie = expresie;
}

void Parser::afisareLista() {
    for (int i = 0; i < nrElemLista; i++) {
        std::cout << lista[i] << " ";
    }
}

std::string Parser::extragereNumar(int index) {
    sirExtras = "";
    if (index >= expresie.size()) {
        throw std::exception("index invalid");
    }

    while ((expresie[index] >= '0' && expresie[index] <= '9') || expresie[index] == '.') {
        sirExtras += expresie[index];
        index++;
        if (index >= expresie.size()) {
            break;
        }
    }
    return sirExtras;
}

void Parser::prelucrareExpresie() {
    int i = 0;
    while (i < expresie.size()) {
        if ((expresie[i] >= '0' && expresie[i] <= '9') || expresie[i] == '.') {
            std::string* copie = new std::string[nrElemLista];
            for (int i = 0; i < nrElemLista; i++) {
                copie[i] = lista[i];
            }
            delete[] lista;
            lista = Utils::copiereString(copie, nrElemLista + 1);
            nrElemLista++;
            lista[nrElemLista - 1] = extragereNumar(i);
            i = i + lista[nrElemLista - 1].size();
        }
        else if (expresie[i] == '/' || expresie[i] == '*') {
            operatori[nrElementeOperatori] = expresie[i];
            nrElementeOperatori++;
        }
        else if (expresie[i] == '+' || expresie[i] == '-') {
            if (operatori[nrElementeOperatori - 1] == '*') {
                std::string* copie = new std::string[nrElemLista];
                for (int i = 0; i < nrElemLista; i++) {
                    copie[i] = lista[i];
                }
                delete[] lista;
                lista = Utils::copiereString(copie, nrElemLista + 1);
                nrElemLista++;
                lista[nrElemLista - 1] = "*";
                i++;
                operatori[nrElementeOperatori - 1] = expresie[i];
            }
            else if (operatori[nrElementeOperatori - 1] == '/') {
                std::string* copie = new std::string[nrElemLista];
                for (int i = 0; i < nrElemLista; i++) {
                    copie[i] = lista[i];
                }
                delete[] lista;
                lista = Utils::copiereString(copie, nrElemLista + 1);
                nrElemLista++;
                lista[nrElemLista - 1] = "*";
                i++;
                operatori[nrElementeOperatori - 1] = expresie[i];
            }
        }
        i++;
    }
    for (int i = nrElementeOperatori - 1; i >= 0; i--) {
        if (operatori[i] == '*') {
            std::string* copie = new std::string[nrElemLista];
            for (int i = 0; i < nrElemLista; i++) {
                copie[i] = lista[i];
            }
            delete[] lista;
            lista = Utils::copiereString(copie, nrElemLista + 1);
            nrElemLista++;
            lista[nrElemLista - 1] = "*";
        }
        else if (operatori[i] == '/') {
            std::string* copie = new std::string[nrElemLista];
            for (int i = 0; i < nrElemLista; i++) {
                copie[i] = lista[i];
            }
            delete[] lista;
            lista = Utils::copiereString(copie, nrElemLista + 1);
            nrElemLista++;
            lista[nrElemLista - 1] = "/";
        }
        else if (operatori[i] == '+') {
            std::string* copie = new std::string[nrElemLista];
            for (int i = 0; i < nrElemLista; i++) {
                copie[i] = lista[i];
            }
            delete[] lista;
            lista = Utils::copiereString(copie, nrElemLista + 1);
            nrElemLista++;
            lista[nrElemLista - 1] = "+";
        }
        else if (operatori[i] == '-') {
            std::string* copie = new std::string[nrElemLista];
            for (int i = 0; i < nrElemLista; i++) {
                copie[i] = lista[i];
            }
            delete[] lista;
            lista = Utils::copiereString(copie, nrElemLista + 1);
            nrElemLista++;
            lista[nrElemLista - 1] = "-";
        }
    }
}

Parser::~Parser() {
    if (lista != nullptr) {
        delete[] lista;
        lista = nullptr;
    }
}

Parser::Parser(Parser& p)
{
    delete[] lista;
    lista = new string[p.nrElemLista];
    for (int i = 0; i < p.nrElemLista; i++)
        lista[i] = p.lista[i];

    nrElemLista = p.nrElemLista;

    for (int i = 0; i < p.nrElementeOperatori;i++)
        operatori[i] = p.operatori[i];

    nrElementeOperatori = p.nrElementeOperatori;
    expresie = p.expresie;
}

void Parser :: operator=(Parser p) {
    delete[] lista;
    lista = new string[p.nrElemLista];
    for (int i = 0; i < p.nrElemLista; i++)
        lista[i] = p.lista[i];

    nrElemLista = p.nrElemLista;

    for (int i = 0; i < p.nrElementeOperatori;i++)
        operatori[i] = p.operatori[i];

    nrElementeOperatori = p.nrElementeOperatori;
    expresie = p.expresie;
}

bool Parser::operator!() {
    return nrElemLista == 0;
}

Parser::operator string() {
    return expresie;
}

std::ostream& operator<<(std::ostream& out, const Parser& p) {
    out << p.nrElemLista << std::endl;
    for (int i = 0; i < p.nrElemLista; i++)
        out << p.lista[i] << std::endl;

    out << p.nrElementeOperatori << std::endl;
    for (int i = 0; i < p.nrElementeOperatori; i++) {
        out << p.operatori[i] << " ";
    }

    out << std::endl << p.expresie;
    return out;
}

istream& operator>>(istream& in, Parser& p) {
    in >> p.expresie;
    return in;
}

