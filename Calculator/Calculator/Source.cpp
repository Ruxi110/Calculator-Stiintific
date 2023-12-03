#include <iostream>
#include <string>
#include <cctype>  
#include <cstdlib>
#include <exception>

using namespace std;

class Utils {
public:
    double* copiereVector(double* vector, int nrElemente) {
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

    static string* copiereString(string* vector, int nrElemente) {

        if (vector == nullptr) {
            return nullptr;
        }

        string* vectorNou = new string[nrElemente];
        for (int i = 0; i < nrElemente; i++) {
            vectorNou[i] = vector[i];
        }
        return vectorNou;
    }
};

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
public:

    string getExpresie() {
        return expresie;
    }

    void setExpresie(string expresie) {
        this->expresie = expresie;
    }

    int getId() {
        return id;
    }

    double* getOperanzi() {
        double* copie = new double[nrOperanzi];
        for (int i = 0; i < nrOperanzi;i++)
            copie[i] = operanzi[i];
        return copie;
    }

    void setOperanzi(double* vector, int nrElem) {
        if (operanzi != nullptr) {
            delete[] operanzi;
        }
        operanzi = new double[nrElem];
        for (int i = 0; i < nrElem;i++)
            operanzi[i] = vector[i];

        nrOperanzi = nrElem;
    }

    char* getOperatori() {
        char* copie = new char[nrOperatori];
        for (int i = 0; i < nrOperatori; i++)
        {
            copie[i] = operatori[i];
        }
        return copie;
    }

    void setOperatori(char* operatori, int nrElem) {
        for (int i = 0; i < nrElem; i++)
            this->operatori[i] = operatori[i];

        this->nrOperatori = nrElem;
    }



    int getNrOperatori() {
        return nrOperatori;
    }

    void setNrOperatori(int nrOperatori) {
        this->nrOperatori = nrOperatori;
    }

    static int getGeneratorId() {
        return Calculator::GENERATOR_ID;
    }

    static void setGeneratoriId(int startId) {
        Calculator::GENERATOR_ID = startId;
    }

    Calculator() :id(GENERATOR_ID) {
        expresie = "";
        operanzi = nullptr;
        nrOperanzi = 0;
        nrOperatori = 0;
        Calculator::GENERATOR_ID++;
    }

    Calculator(string expresie, int idEcuatie) :id(idEcuatie) {
        this->expresie = expresie;
        Calculator::GENERATOR_ID++;
    }


    double extragereNumar(int index) {
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

    void Token() {
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

    ~Calculator() {
        if (operanzi != nullptr) {
            delete[] operanzi;
            operanzi = nullptr;
            Calculator::GENERATOR_ID--;
        }
    }

    void operator=(Calculator c) {
        this->expresie = c.expresie;
        this->setOperanzi(c.operanzi, c.nrOperanzi);
        this->setOperatori(c.operatori, c.nrOperatori);
    }

    double operator[](int index) {
        if (index >= 0 && index < nrOperanzi) {
            return operanzi[index];
        }
    }

    bool operator==(int x) {
        if (nrOperanzi + nrOperatori == x) return 1;
        else return 0;
    }

    friend bool operator==(int x, Calculator c);
    friend ostream& operator<<(ostream& out, Calculator c);
};

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

int Calculator::GENERATOR_ID = 1;
bool operator==(int x, Calculator c)
{
    if (x == c.nrOperanzi + c.nrOperatori)
        return 1;
    else
        return 0;
}

class Parser {
private:
    string* lista = nullptr;
    int nrElemLista = 0;
    char operatori[100];
    int nrElementeOperatori = 0;
    string expresie;
    string sirExtras;
public:

    Parser() {
        string* lista = nullptr;
        int nrElemLista = 0;
        int nrElementeOperatori = 0;
        string expresie;
        string sirExtras;
    }

    Parser(string expresie) {
        this->expresie = expresie;
    }

    string* getLista() {
        string* copie = new string[nrElemLista];
        for (int i = 0; i < nrElemLista; i++)
            copie[i] = lista[i];

        return copie;
    }

    char* getOperatori() {
        char* copie = new char[nrElementeOperatori];
        for (int i = 0; i < nrElementeOperatori;i++)
            copie[i] = operatori[i];
        return copie;
    }

    int getNrElementeOperatori() {
        return nrElementeOperatori;
    }

    string getExpresie() {
        return expresie;
    }

    void setExpresie(string expresie) {
        this->expresie = expresie;
    }

    void afisareLista() {
        for (int i = 0; i < nrElemLista; i++) {
            cout << lista[i] << " ";
        }
    }

    string extragereNumar(int index) {
        sirExtras = "";
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
        return sirExtras;
    }

    void prelucrareExpresie() {
        int i = 0;
        while (i < expresie.size())
        {
            if ((expresie[i] >= '0' && expresie[i] <= '9') || expresie[i] == '.')
            {
                string* copie = new string[nrElemLista];
                for (int i = 0; i < nrElemLista; i++)
                {
                    copie[i] = lista[i];
                }
                delete[] lista;
                lista = Utils::copiereString(copie, nrElemLista + 1);
                nrElemLista++;
                lista[nrElemLista - 1] = extragereNumar(i);
                i = i + lista[nrElemLista - 1].size();
            }
            else if (expresie[i] == '/' || expresie[i] == '*')
            {
                operatori[nrElementeOperatori] = expresie[i];
                nrElementeOperatori++;
            }
            else if (expresie[i] == '+' || expresie[i] == '-') {
                if (operatori[nrElementeOperatori - 1] == '*')
                {
                    string* copie = new string[nrElemLista];
                    for (int i = 0; i < nrElemLista; i++)
                    {
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
                    string* copie = new string[nrElemLista];
                    for (int i = 0; i < nrElemLista; i++)
                    {
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
        }
        for (int i = nrElementeOperatori - 1; i >= 0;i--)
        {
            if (operatori[i] == '*')
            {
                string* copie = new string[nrElemLista];
                for (int i = 0; i < nrElemLista; i++)
                {
                    copie[i] = lista[i];
                }
                delete[] lista;
                lista = Utils::copiereString(copie, nrElemLista + 1);
                nrElemLista++;
                lista[nrElemLista - 1] = "*";

            }
            else  if (operatori[i] == '/')
            {
                string* copie = new string[nrElemLista];
                for (int i = 0; i < nrElemLista; i++)
                {
                    copie[i] = lista[i];
                }
                delete[] lista;
                lista = Utils::copiereString(copie, nrElemLista + 1);
                nrElemLista++;
                lista[nrElemLista - 1] = "/";
            }
            else  if (operatori[i] == '+')
            {
                string* copie = new string[nrElemLista];
                for (int i = 0; i < nrElemLista; i++)
                {
                    copie[i] = lista[i];
                }
                delete[] lista;
                lista = Utils::copiereString(copie, nrElemLista + 1);
                nrElemLista++;
                lista[nrElemLista - 1] = "+";
            }
            else  if (operatori[i] == '-')
            {
                string* copie = new string[nrElemLista];
                for (int i = 0; i < nrElemLista; i++)
                {
                    copie[i] = lista[i];
                }
                delete[] lista;
                lista = Utils::copiereString(copie, nrElemLista + 1);
                nrElemLista++;
                lista[nrElemLista - 1] = "-";
            }
        }
    }

    bool operator!() {
        if (nrElemLista == 0)
            return 0;
        else return 1;
    }

    explicit operator string() {
        return expresie;
    }

    friend ostream& operator<<(ostream& out, Parser p);
};

ostream& operator<<(ostream& out, Parser p)
{
    out << p.nrElemLista;
    out << endl;
    for (int i = 0; i < p.nrElemLista; i++)
        out << p.lista[i] << endl;

    out << p.nrElementeOperatori;
    out << endl;
    for (int i = 0; i < p.nrElementeOperatori; i++) {
        out << p.operatori[i] << " ";
    }

    out << endl << p.expresie;
    return out;
}

const int MAX_SIZE = 100;

class ExpressionEvaluator {
private:
    char outputQueue[MAX_SIZE];
    char operatorStack[MAX_SIZE];
    int outputIndex;
    int operatorIndex;
    int operandStack[MAX_SIZE];
    int stackIndex;

public:
    ExpressionEvaluator() : outputIndex(-1), operatorIndex(-1), stackIndex(-1) {}

    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

    int getPrecedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return 0;
    }

    void pushToOutput(char element) {
        if (outputIndex < MAX_SIZE - 1) {
            outputQueue[++outputIndex] = element;
        }
        else {
            cerr << "eroare" << endl;
            exit(EXIT_FAILURE);
        }
    }

    void pushToOperatorStack(char element) {
        if (operatorIndex < MAX_SIZE - 1) {
            operatorStack[++operatorIndex] = element;
        }
        else {
            cerr << "Operator invalid" << endl;
            exit(EXIT_FAILURE);
        }
    }

    char popFromOperatorStack() {
        if (operatorIndex >= 0) {
            return operatorStack[operatorIndex--];
        }
        else {
            cerr << "index invalid" << endl;
            exit(EXIT_FAILURE);
        }
    }

    void pushOperand(int operand) {
        if (stackIndex < MAX_SIZE - 1) {
            operandStack[++stackIndex] = operand;
        }
        else {
            cerr << "index invalid" << endl;
            exit(EXIT_FAILURE);
        }
    }

    int popOperand() {
        if (stackIndex >= 0) {
            return operandStack[stackIndex--];
        }
        else {
            std::cerr << "invalid index" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    std::string infixToPostfix(const std::string& infixExpression) {
        for (char token : infixExpression) {
            if (isalnum(token)) {
                pushToOutput(token);
            }
            else if (isOperator(token)) {
                while (operatorIndex >= 0 && isOperator(operatorStack[operatorIndex]) &&
                    getPrecedence(operatorStack[operatorIndex]) >= getPrecedence(token)) {
                    pushToOutput(popFromOperatorStack());
                }
                pushToOperatorStack(token);
            }
            else if (token == '(') {
                pushToOperatorStack(token);
            }
            else if (token == ')') {
                while (operatorIndex >= 0 && operatorStack[operatorIndex] != '(') {
                    pushToOutput(popFromOperatorStack());
                }
                if (operatorIndex >= 0 && operatorStack[operatorIndex] == '(') {
                    popFromOperatorStack();
                }
                else {
                    std::cerr << "eroare" << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
        }

        while (operatorIndex >= 0) {
            if (operatorStack[operatorIndex] == '(' || operatorStack[operatorIndex] == ')') {
                std::cerr << "Mismatched parentheses." << std::endl;
                exit(EXIT_FAILURE);
            }
            pushToOutput(popFromOperatorStack());
        }

        return std::string(outputQueue, outputIndex + 1);
    }

    int evaluatePostfix(const std::string& postfixExpression) {
        for (char token : postfixExpression) {
            if (isdigit(token)) {
                pushOperand(token - '0');
            }
            else if (isOperator(token)) {
                int operand2 = popOperand();
                int operand1 = popOperand();
                int result = performOperation(token, operand1, operand2);
                pushOperand(result);
            }
        }

        if (stackIndex == 0) {
            return operandStack[stackIndex];
        }
        else {
            std::cerr << "Error: Invalid postfix expression." << std::endl;
            exit(EXIT_FAILURE);
        }
    }

private:
    int performOperation(char op, int operand1, int operand2) {
        switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            }
            else {
                std::cerr << "nu se poate imparti prin 0" << std::endl;
                exit(EXIT_FAILURE);
            }
        default:
            std::cerr << "operator invalid" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
};

int main()
{
    ExpressionEvaluator evaluator;

    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    string postfixExpression = evaluator.infixToPostfix(infixExpression);

    cout << "Postfix expression: " << postfixExpression << std::endl;

    int result = evaluator.evaluatePostfix(postfixExpression);

    cout << "Result: " << result << std::endl;

    return 0;
}