/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: April 19, 2023
 Programming Assignment: PA7
 Description: Postfix Calculator
 Notes: -
*/

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <cmath>
#include "Stack.h"

using namespace std;

bool checkOperatorOnStackPrecedence(string, string);
bool isOpeningParentheses (string currOperator);
bool isClosingParentheses (string currOperator);
string evaluateExpression (string param1 , string param2 , char type);
bool isOperator (string s);

class Calculator {
	private:
		string symbolTable['Z' + 1];
		// example of composition
		// Calculator "has-a" Stack
		Stack stack; // for converting infix to postfix and for evaluating postfix
	public:
		void setSymbolTable(string[]);
		string convertInfixToPostfix(string);
		string evaluatePostfix(string);
        string alphaToNum (string postfix);
};

#endif