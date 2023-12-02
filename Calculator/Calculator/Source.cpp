#include<iostream>
#include<string>

using namespace std;




/*string tokenParanteza(int index) {
		double rezultat = 0.0;
		double st = 0.0;
		double dr = this->extragereNumar(index + 1);
		int indexFinal = index + pointerIndex + 1;
		if (expression[indexFinal] == '+')
		{
			st = this->extragereNumar(index + 1);
			rezultat= dr + st;
		}
		else if (expression[indexFinal] == '-')
		{
			 st = this->extragereNumar(index + 1);
			rezultat = dr - st;
		}
		else if(expression[indexFinal]=='*')
		{
			 st = this->extragereNumar(index + 1);
			rezultat = dr * st;
		}
		else if (expression[indexFinal] == '/')
		{
			 st = this->extragereNumar(index + 1);
			if (st == 0)
			{
				throw exception("nu se poate imparti la 0");
			}
			else
				rezultat = dr * st;
		}
		indexFinal = indexFinal + to_string(st).size();
		string prefix = expression.substr(0, index);
		string sufix = expression.substr(indexFinal + 1, expression.size());
		string expresieModificata = prefix + to_string(rezultat) + sufix;
		expression = expresieModificata;
		return expression;
	}*/

	//void ordineaOperatiilor()
	//{
	//	for (int i = 0; i <= expression.size(); i++)
	//	{
	//		this->extragereNumar(0);
	//		if (expression[i] == '*') {
	//			this->inmultire();
	//		}
	//		else if (expression[i] == '/') {
	//			this->impartire();
	//		}
	//	}
	//}



class Parser {

private:

	double* vector = nullptr;
	char* operatori = nullptr;
	string sirExtras;
	double nrExtras = 0;
	char token;
	int pointerIndex = 0;
	double operatorDreapta = 0.0;
	string expression;

public:


	void setExpression(string expression) {
		this->expression = expression;
	}

	string getExpression() {
		return expression;
	}

	Parser(string expresie) {
		if (expresie.empty()) {
			throw exception("sirul primit este gol");
		}
		expression = expresie;
	}

	double extragereNumar(int index) {
		if (this->expression.empty()) {
			throw exception("nu se poate extrage numar, deoarece sirul este null");
		}

		int indexNr = index;
		while ((expression[indexNr] >= '0' && expression[indexNr] <= '9') || expression[indexNr] == '.')
		{
			sirExtras += expression[indexNr];
			indexNr++;
		}
		pointerIndex = index + sirExtras.size();
		if (!sirExtras.empty()) {
			nrExtras = stod(sirExtras);
		}

		sirExtras = "";
		return nrExtras;
	}

	void operatoriGrad2()
	{
		while (expression.find('*') != std::string::npos || expression.find('/') != std::string::npos)
		{
			for (int i = 0; i < expression.size(); i++) {
				if (expression[i] >= '0' && expression[i] <= '9')
				{
					operatorDreapta = this->extragereNumar(i);
					i = i + to_string(operatorDreapta).size();
				}
				else if (expression[i] == '*') {
					this->inmultire(i);
				}
				else if (expression[i] == '/') {
					this->impartire(i);
				}
				else i++;
			}
		}

	}

	void inmultire(int index) {
		double operatorStanga = this->extragereNumar(index);
		double rezultat = operatorDreapta * operatorStanga;
		string prefix = expression.substr(0, index - to_string(operatorDreapta).size());
		string sufix = expression.substr(index + to_string(operatorStanga).size() + 1, expression.size());
		string expresieModificata = prefix + to_string(rezultat) + sufix;
		expression = expresieModificata;
		operatoriGrad2();
	}

	string impartire(int index) {
		double operatorStanga = this->extragereNumar(index);
		if (operatorStanga == 0) {
			throw exception("nu se poate impartii la 0");
		}
		double rezultat = operatorDreapta / operatorStanga;
		string prefix = expression.substr(0, index - to_string(operatorDreapta).size());
		string sufix = expression.substr(index + to_string(operatorStanga).size() + 1, expression.size());
		string expresieModificata = prefix + to_string(rezultat) + sufix;
		expression = expresieModificata;
		operatoriGrad2();
	}

	void operatoriGrad1() {
		while (expression.find('+') != std::string::npos || expression.find('-') != std::string::npos)
		{
			for (int i = 0; i < expression.size(); i++) {
				if (expression[i] >= '0' && expression[i] <= '9')
				{
					operatorDreapta = this->extragereNumar(i);
					i = i + to_string(operatorDreapta).size();
				}
				else if (expression[i] == '+') {
					this->adunare(i);
				}
				else if (expression[i] == '-') {
					this->scadere(i);
				}
				else i++;
			}
		}

	}

	void adunare(int index) {
		double operatorStanga = this->extragereNumar(index);
		double rezultat = operatorDreapta + operatorStanga;
		string prefix = expression.substr(0, index - to_string(operatorDreapta).size());
		string sufix = expression.substr(index + to_string(operatorStanga).size() + 1, expression.size());
		string expresieModificata = prefix + to_string(rezultat) + sufix;
		expression = expresieModificata;
		operatoriGrad1();
	}

	void scadere(int index) {
		double operatorStanga = this->extragereNumar(index);
		double rezultat = operatorDreapta - operatorStanga;
		string prefix = expression.substr(0, index - to_string(operatorDreapta).size());
		string sufix = expression.substr(index + to_string(operatorStanga).size() + 1, expression.size());
		string expresieModificata = prefix + to_string(rezultat) + sufix;
		expression = expresieModificata;
		operatoriGrad1();
	}
};

int main()
{
	string s = "1+2*3+4";
	Parser parser(s);
	parser.operatoriGrad2();
	parser.operatoriGrad1();
	cout << parser.getExpression();
}