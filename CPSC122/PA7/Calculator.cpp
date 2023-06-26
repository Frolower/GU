/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: April 19, 2023
 Programming Assignment: PA7
 Description: Postfix Calculator
 Notes: -
*/

#include "Calculator.h"

/*************************************************************
 * Function: setSymbolTable
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: copied content from one array to another
 * Input parameters: string newSymbolTable[]
 * Returns: -
 * Pre: input array must have info in it
 * Post: data copied to another array
 **********************************************************/
void Calculator::setSymbolTable(string newSymbolTable[]) {
	// copy over since can't assign one array to the other
	for (int i = 'A'; i <= 'Z'; i++) {
		symbolTable[i] = newSymbolTable[i];
	}
}

/*************************************************************
 * Function: checkOperatorOnStackPrecedence
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: check precedence of the operator
 * Input parameters: string operatorOnStack, string currentOperator
 * Returns: bool
 * Pre:
 * Post: operator precedence returned
 **********************************************************/
bool checkOperatorOnStackPrecedence(string operatorOnStack, string currentOperator) {
    string arr [8] = {"(" , ")" , "^" , "*" , "/" , "%" , "-" , "+"};
    int arr2 [8] = {0 , -1 , 5 , 4 , 4 , 4 , 2 , 2};
    int arr3 [8] = {100 , 0 , 6 , 3 , 3 , 3 , 1 , 1};
    int scoreOn = -2;
    int scoreOff = -1;

    for (int i = 0; i < 8; i++) {
        if (operatorOnStack == arr[i]) {
            scoreOn = arr2 [i];
            break;
        }
    }
    for (int i = 0; i < 8; i++) {
        if (currentOperator == arr[i]) {
            scoreOff = arr3 [i];
            break;
        }
    }

    if (scoreOn > scoreOff) {
        return true;
    } else {
        return false;
    }
}

/*************************************************************
 * Function: convertInfixToPostfix
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: converts infix to postfix
 * Input parameters: string infix
 * Returns: string
 * Pre: infix passed
 * Post: infix converted to postfix
 **********************************************************/
string Calculator::convertInfixToPostfix(string infix) {
    Stack * s = new Stack;
    int i = 0;
    string postfix = "";
    string prom = "";

    while(infix[i]!='\0') {
        prom = infix[i];
        if(isalpha(infix[i])) {
            postfix += infix[i];
            i++;
        }
        else if(isOpeningParentheses(prom)) {
            s->push(prom);
            i++;
        }
        else if(isClosingParentheses(prom)) {
            while(!isOpeningParentheses(s->peek())) {
                postfix += s->peek();
                s->pop();
            }
            s->pop();
            i++;
        }
        else {
            while (!s->isEmpty() && checkOperatorOnStackPrecedence(s->peek() , prom)) {
                postfix += s->peek();
                s->pop();
            }
            s->push(prom);
            i++;
        }
    }
    while(!s->isEmpty()) {
        postfix += s->peek();
        s->pop();
    }

    delete s;
    return postfix;
}

/*************************************************************
 * Function: evaluatePostfix
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: evaluate postfix expression
 * Input parameters: string postfix
 * Returns: string
 * Pre: infix expression converted to postfix
 * Post: answer returned
 **********************************************************/
string Calculator::evaluatePostfix(string postfix) {
    string promNum = "";
    string num1 = "";
    string num2 = "";
    string ans = "";
    string prom = "";
    int i = 0;
    Stack * s = new Stack;

    if (postfix.length() == 1) {
        postfix = Calculator::alphaToNum(postfix);
        postfix = postfix.substr(0 , postfix.length()-1);
        return postfix;
    }

    postfix = Calculator::alphaToNum(postfix);

    while (i < postfix.length()) {
        prom = postfix[i];
        if (prom == "-" && postfix[i + 1] != ' ') {
            promNum += prom;
        } else if (isdigit(postfix[i])) {
            promNum += prom;
        } else if (isOperator(prom)) {
            num2 = s->peek();
            s->pop();
            num1 = s->peek();
            s->pop();
            ans = evaluateExpression(num1 , num2 , postfix[i]);
            s->push(ans);
        } else if (prom == " " && isdigit(postfix[i - 1])) {
            s->push(promNum);
            promNum = "";
        }
        i++;
        if (i + 1 >= postfix.length()) {
            break;
        }
    }

    ans = s->peek();
    s->pop();
    delete s;
    return ans;
}

/*************************************************************
 * Function: isOpeningParentheses
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: check if character is (
 * Input parameters: string currOperator
 * Returns: bool
 * Pre:
 * Post: check happened
 **********************************************************/
bool isOpeningParentheses (string currOperator) {
    if (currOperator == "(") {
        return true;
    }
    return false;
}

/*************************************************************
 * Function: isClosingParentheses
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: check if character is )
 * Input parameters: string currOperator
 * Returns: bool
 * Pre:
 * Post: check happened
 **********************************************************/
bool isClosingParentheses (string currOperator) {
    if (currOperator == ")") {
        return true;
    }
    return false;
}

/*************************************************************
 * Function: evaluateExpression
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: evaluates expression
 * Input parameters: string num1 , string num2 , char type
 * Returns: string
 * Pre: string num1 , string num2 , char type must contain (num , num , operator)
 * Post: expression evaluated
 **********************************************************/
string evaluateExpression (string num1 , string num2 , char type) {
    num1 = num1.substr(0, num1.find('.'));
    num2 = num2.substr(0, num2.find('.'));
    if (num1.length() > 19 || num2.length() > 19) {
        return "0";
    }
    long long int param1 = stoll(num1);
    long long int param2 = stoll(num2);
    switch (type) {
        case '+':
            return to_string (param1 + param2);
            break;
        case '-':
            return to_string(param1 - param2);
            break;
        case '*':
            return to_string(param1 * param2);
            break;
        case '/':
            if (param2 != 0) {
                return to_string(param1 / param2);
            } else {
                cout << "Division by 0" << endl;
            }
            break;
        case '^':
            return to_string(pow(param1 , param2));
            break;
        default:
            cout << "Unknown operation" << endl;
            return "";
            break;
    }
}

/*************************************************************
 * Function: isOperator
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: checks if s is operator
 * Input parameters: string s
 * Returns: bool
 * Pre:
 * Post: check happened
 **********************************************************/
bool isOperator (string s) {
    if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^") {
        return true;
    } else {
        return false;
    }
}

/*************************************************************
 * Function: alphaToNum
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: changes all letters to corresponding numbers
 * Input parameters: string postfix
 * Returns: string
 * Pre:
 * Post: new expression is ready
 **********************************************************/
string Calculator::alphaToNum (string postfix) {
    string prom = "";
    int count = 0;

    for (int i = 0; i < postfix.size(); i++) {
        if (isalpha(postfix.at(i))) {
            prom += symbolTable[postfix.at(i)];
            prom += " ";
            count++;
        } else {
            prom += postfix[i];
            prom += " ";
        }
    }

    return prom;
}