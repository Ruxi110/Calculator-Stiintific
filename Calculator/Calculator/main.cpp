#include <iostream>
#include <string>
#include <cctype>  
#include <cstdlib>
#include "ExpressionEvaluator.h"
#include "Calculator.h"
#include "Parser.h"
#include "Utils.h"


int main()
{
    ExpressionEvaluator evaluator;

    string infixExpression;
    cout << "infix expression: ";
    getline(cin, infixExpression);

    string postfixExpression = evaluator.infixToPostfix(infixExpression);

    cout << "Postfix expression: " << postfixExpression << std::endl;

    int result = evaluator.evaluatePostfix(postfixExpression);

    cout << "Result: " << result << std::endl;
    

}