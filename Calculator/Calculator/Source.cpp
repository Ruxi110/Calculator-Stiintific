//#include <iostream>
//#include <string>
//#include <cctype>  
//#include <cstdlib>
//#include <exception>
//
//using namespace std;
//
//class Utils {
//public:
//    double* copiereVector(double* vector, int nrElemente) {
//        if (vector == nullptr) {
//            return nullptr;
//        }
//
//        double* vectorNou = new double[nrElemente];
//        for (int i = 0; i < nrElemente; i++)
//        {
//            vectorNou[i] = vector[i];
//        }
//        return vectorNou;
//    }
//
//    static string* copiereString(string* vector, int nrElemente) {
//
//        if (vector == nullptr) {
//            return nullptr;
//        }
//
//        string* vectorNou = new string[nrElemente];
//        for (int i = 0; i < nrElemente; i++) {
//            vectorNou[i] = vector[i];
//        }
//        return vectorNou;
//    }
//};
//
//class Calculator {
//private:
//    int const id;
//    string expresie;
//    double* operanzi = nullptr;
//    int nrOperanzi = 0;
//    char operatori[100];
//    int nrOperatori = 0;
//    static int GENERATOR_ID;
//    string sirExtras;
//public:
//
//    string getExpresie() {
//        return expresie;
//    }
//
//    void setExpresie(string expresie) {
//        this->expresie = expresie;
//    }
//
//    int getId() {
//        return id;
//    }
//
//    double* getOperanzi() {
//        double* copie = new double[nrOperanzi];
//        for (int i = 0; i < nrOperanzi;i++)
//            copie[i] = operanzi[i];
//        return copie;
//    }
//
//    void setOperanzi(double* vector, int nrElem) {
//        if (operanzi != nullptr) {
//            delete[] operanzi;
//        }
//        operanzi = new double[nrElem];
//        for (int i = 0; i < nrElem;i++)
//            operanzi[i] = vector[i];
//
//        nrOperanzi = nrElem;
//    }
//
//    char* getOperatori() {
//        char* copie = new char[nrOperatori];
//        for (int i = 0; i < nrOperatori; i++)
//        {
//            copie[i] = operatori[i];
//        }
//        return copie;
//    }
//
//    void setOperatori(char* operatori, int nrElem) {
//        for (int i = 0; i < nrElem; i++)
//            this->operatori[i] = operatori[i];
//
//        this->nrOperatori = nrElem;
//    }
//
//
//
//    int getNrOperatori() {
//        return nrOperatori;
//    }
//
//    void setNrOperatori(int nrOperatori) {
//        this->nrOperatori = nrOperatori;
//    }
//
//    static int getGeneratorId() {
//        return Calculator::GENERATOR_ID;
//    }
//
//    static void setGeneratoriId(int startId) {
//        Calculator::GENERATOR_ID = startId;
//    }
//
//    Calculator() :id(GENERATOR_ID) {
//        expresie = "";
//        operanzi = nullptr;
//        nrOperanzi = 0;
//        nrOperatori = 0;
//        Calculator::GENERATOR_ID++;
//    }
//
//    Calculator(string expresie, int idEcuatie) :id(idEcuatie) {
//        this->expresie = expresie;
//        Calculator::GENERATOR_ID++;
//    }
//
//
//    double extragereNumar(int index) {
//        sirExtras = "";
//        double nrExtras = 0.0;
//        if (index >= expresie.size()) {
//            throw exception("index invalid");
//        }
//
//        while ((expresie[index] >= '0' && expresie[index] <= '9') || expresie[index] == '.') {
//            sirExtras += expresie[index];
//            index++;
//            if (index >= expresie.size()) {
//                break;
//            }
//        }
//        if (!sirExtras.empty()) {
//            nrExtras = stod(sirExtras);
//        }
//        return nrExtras;
//    }
//
//    void Token() {
//        int i = 0;
//        while (i < expresie.size())
//        {
//            if (expresie[i] == '*' || expresie[i] == '/' || expresie[i] == '+' || expresie[i] == '-') {
//                operatori[i] = expresie[i];
//                i++;
//            }
//            else if (expresie[i] == ' ') {
//                i++;
//            }
//            else if ((expresie[i] >= '0' && expresie[i] <= '9') || expresie[i] == '.')
//            {
//                double* copie = new double[nrOperanzi];
//                for (int i = 0; i < nrOperanzi; i++)
//                    copie[i] = operanzi[i];
//                delete[] operanzi;
//                operanzi = new double[nrOperanzi + 1];
//                for (int i = 0; i < nrOperanzi; i++)
//                    operanzi[i] = copie[i];
//                nrOperanzi++;
//                operanzi[nrOperanzi - 1] = extragereNumar(i);
//                i = i + sirExtras.size();
//            }
//        }
//    }
//
//    ~Calculator() {
//        if (operanzi != nullptr) {
//            delete[] operanzi;
//            operanzi = nullptr;
//            Calculator::GENERATOR_ID--;
//        }
//    }
//
//    void operator=(Calculator c) {
//        this->expresie = c.expresie;
//        this->setOperanzi(c.operanzi, c.nrOperanzi);
//        this->setOperatori(c.operatori, c.nrOperatori);
//    }
//
//    double operator[](int index) {
//        if (index >= 0 && index < nrOperanzi) {
//            return operanzi[index];
//        }
//    }
//
//    bool operator==(int x) {
//        if (nrOperanzi + nrOperatori == x) return 1;
//        else return 0;
//    }
//
//    friend bool operator==(int x, Calculator c);
//    friend ostream& operator<<(ostream& out, Calculator c);
//};
//
//ostream& operator<<(ostream& out, Calculator c) {
//    out << c.nrOperanzi;
//    out << endl;
//    for (int i = 0; i < c.nrOperanzi;i++)
//    {
//        out << c.operanzi[i] << " ";
//    }
//    out << endl;
//    out << c.nrOperatori;
//    out << endl;
//    for (int i = 0; i < c.nrOperatori; i++)
//    {
//        out << c.operatori[i] << " ";
//    }
//    return out;
//}
//
//int Calculator::GENERATOR_ID = 1;
//bool operator==(int x, Calculator c)
//{
//    if (x == c.nrOperanzi + c.nrOperatori)
//        return 1;
//    else
//        return 0;
//}
//
//class Parser {
//private:
//    string* lista = nullptr;
//    int nrElemLista = 0;
//    char operatori[100];
//    int nrElementeOperatori = 0;
//    string expresie;
//    string sirExtras;
//public:
//
//    Parser() {
//        string* lista = nullptr;
//        int nrElemLista = 0;
//        int nrElementeOperatori = 0;
//        string expresie;
//        string sirExtras;
//    }
//
//    Parser(string expresie) {
//        this->expresie = expresie;
//    }
//
//    string* getLista() {
//        string* copie = new string[nrElemLista];
//        for (int i = 0; i < nrElemLista; i++)
//            copie[i] = lista[i];
//
//        return copie;
//    }
//
//    char* getOperatori() {
//        char* copie = new char[nrElementeOperatori];
//        for (int i = 0; i < nrElementeOperatori;i++)
//            copie[i] = operatori[i];
//        return copie;
//    }
//
//    int getNrElementeOperatori() {
//        return nrElementeOperatori;
//    }
//
//    string getExpresie() {
//        return expresie;
//    }
//
//    void setExpresie(string expresie) {
//        this->expresie = expresie;
//    }
//
//    void afisareLista() {
//        for (int i = 0; i < nrElemLista; i++) {
//            cout << lista[i] << " ";
//        }
//    }
//
//    string extragereNumar(int index) {
//        sirExtras = "";
//        if (index >= expresie.size()) {
//            throw exception("index invalid");
//        }
//
//        while ((expresie[index] >= '0' && expresie[index] <= '9') || expresie[index] == '.') {
//            sirExtras += expresie[index];
//            index++;
//            if (index >= expresie.size()) {
//                break;
//            }
//        }
//        return sirExtras;
//    }
//
//    void prelucrareExpresie() {
//        int i = 0;
//        while (i < expresie.size())
//        {
//            if ((expresie[i] >= '0' && expresie[i] <= '9') || expresie[i] == '.')
//            {
//                string* copie = new string[nrElemLista];
//                for (int i = 0; i < nrElemLista; i++)
//                {
//                    copie[i] = lista[i];
//                }
//                delete[] lista;
//                lista = Utils::copiereString(copie, nrElemLista + 1);
//                nrElemLista++;
//                lista[nrElemLista - 1] = extragereNumar(i);
//                i = i + lista[nrElemLista - 1].size();
//            }
//            else if (expresie[i] == '/' || expresie[i] == '*')
//            {
//                operatori[nrElementeOperatori] = expresie[i];
//                nrElementeOperatori++;
//            }
//            else if (expresie[i] == '+' || expresie[i] == '-') {
//                if (operatori[nrElementeOperatori - 1] == '*')
//                {
//                    string* copie = new string[nrElemLista];
//                    for (int i = 0; i < nrElemLista; i++)
//                    {
//                        copie[i] = lista[i];
//                    }
//                    delete[] lista;
//                    lista = Utils::copiereString(copie, nrElemLista + 1);
//                    nrElemLista++;
//                    lista[nrElemLista - 1] = "*";
//                    i++;
//                    operatori[nrElementeOperatori - 1] = expresie[i];
//                }
//                else if (operatori[nrElementeOperatori - 1] == '/') {
//                    string* copie = new string[nrElemLista];
//                    for (int i = 0; i < nrElemLista; i++)
//                    {
//                        copie[i] = lista[i];
//                    }
//                    delete[] lista;
//                    lista = Utils::copiereString(copie, nrElemLista + 1);
//                    nrElemLista++;
//                    lista[nrElemLista - 1] = "*";
//                    i++;
//                    operatori[nrElementeOperatori - 1] = expresie[i];
//                }
//            }
//        }
//        for (int i = nrElementeOperatori - 1; i >= 0;i--)
//        {
//            if (operatori[i] == '*')
//            {
//                string* copie = new string[nrElemLista];
//                for (int i = 0; i < nrElemLista; i++)
//                {
//                    copie[i] = lista[i];
//                }
//                delete[] lista;
//                lista = Utils::copiereString(copie, nrElemLista + 1);
//                nrElemLista++;
//                lista[nrElemLista - 1] = "*";
//
//            }
//            else  if (operatori[i] == '/')
//            {
//                string* copie = new string[nrElemLista];
//                for (int i = 0; i < nrElemLista; i++)
//                {
//                    copie[i] = lista[i];
//                }
//                delete[] lista;
//                lista = Utils::copiereString(copie, nrElemLista + 1);
//                nrElemLista++;
//                lista[nrElemLista - 1] = "/";
//            }
//            else  if (operatori[i] == '+')
//            {
//                string* copie = new string[nrElemLista];
//                for (int i = 0; i < nrElemLista; i++)
//                {
//                    copie[i] = lista[i];
//                }
//                delete[] lista;
//                lista = Utils::copiereString(copie, nrElemLista + 1);
//                nrElemLista++;
//                lista[nrElemLista - 1] = "+";
//            }
//            else  if (operatori[i] == '-')
//            {
//                string* copie = new string[nrElemLista];
//                for (int i = 0; i < nrElemLista; i++)
//                {
//                    copie[i] = lista[i];
//                }
//                delete[] lista;
//                lista = Utils::copiereString(copie, nrElemLista + 1);
//                nrElemLista++;
//                lista[nrElemLista - 1] = "-";
//            }
//        }
//    }
//
//    bool operator!() {
//        if (nrElemLista == 0)
//            return 0;
//        else return 1;
//    }
//
//    explicit operator string() {
//        return expresie;
//    }
//
//    friend ostream& operator<<(ostream& out, Parser p);
//};
//
//ostream& operator<<(ostream& out, Parser p)
//{
//    out << p.nrElemLista;
//    out << endl;
//    for (int i = 0; i < p.nrElemLista; i++)
//        out << p.lista[i] << endl;
//
//    out << p.nrElementeOperatori;
//    out << endl;
//    for (int i = 0; i < p.nrElementeOperatori; i++) {
//        out << p.operatori[i] << " ";
//    }
//
//    out << endl << p.expresie;
//    return out;
//}
//
//#include <iostream>
//#include <sstream>
//
//class MathExpressionHandler {
//private:
//    double values[100];
//    char operators[100];
//    int valIndex;
//    int opIndex = 0;
//public:
//    MathExpressionHandler(const std::string& expression) : expression_(expression) {}
//
//    double evaluate() {
//        
//
//        std::istringstream input(expression_);
//
//        double number;
//        char op, lastOp = '\0';
//
//        while (input >> number) {
//            values[valIndex++] = number;
//
//            while (input >> op) {
//                if (op == ' ') {
//                    continue;
//                }
//
//                if (op == '+' || op == '-') {
//                    while (opIndex > 0 && (operators[opIndex - 1] == '+' || operators[opIndex - 1] == '-' || operators[opIndex - 1] == '*' || operators[opIndex - 1] == '/')) {
//                        applyOperator(values, operators[--opIndex]);
//                    }
//                    operators[opIndex++] = op;
//                }
//                else if (op == '*' || op == '/') {
//                    while (opIndex > 0 && (operators[opIndex - 1] == '*' || operators[opIndex - 1] == '/')) {
//                        applyOperator(values, operators[--opIndex]);
//                    }
//                    operators[opIndex++] = op;
//                }
//                else if (op == '(') {
//                    operators[opIndex++] = op;
//                }
//                else if (op == ')') {
//                    while (opIndex > 0 && operators[opIndex - 1] != '(') {
//                        applyOperator(values, operators[--opIndex]);
//                    }
//                    opIndex--; // Pop '('
//                }
//                else {
//                    input.putback(op);
//                    break;
//                }
//            }
//            lastOp = '\0';
//        }
//
//        while (opIndex > 0) {
//            applyOperator(values, operators[--opIndex]);
//        }
//
//        return values[--valIndex];
//    }
//
//private:
//    void applyOperator(double values[], char op) {
//        double right = values[--valIndex];
//        double left = values[--valIndex];
//
//        switch (op) {
//        case '+':
//            values[valIndex++] = left + right;
//            break;
//        case '-':
//            values[valIndex++] = left - right;
//            break;
//        case '*':
//            values[valIndex++] = left * right;
//            break;
//        case '/':
//            if (right != 0.0) {
//                values[valIndex++] = left / right;
//            }
//            else {
//                std::cerr << "Error: Division by zero." << std::endl;
//            }
//            break;
//        }
//    }
//
//    std::string expression_;
//};
//
//int main() {
//    std::string inputExpression;
//    std::cout << "Enter a mathematical expression: ";
//    std::getline(std::cin, inputExpression);
//
//    MathExpressionHandler expressionHandler(inputExpression);
//    double result = expressionHandler.evaluate();
//
//    std::cout << "Result: " << result << std::endl;
//
//    return 0;
//}
//
