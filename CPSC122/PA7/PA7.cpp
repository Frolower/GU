/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: April 19, 2023
 Programming Assignment: PA7
 Description: Postfix Calculator
 Notes: -
*/

#include "PA7.h"

/*************************************************************
 * Function: runPA7()
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: runs program
 * Input parameters: -
 * Returns: -
 * Pre: -
 * Post: -
 **********************************************************/
void runPA7 () {
    string filename = "../input.txt";
    readAndComplete(filename);
}

/*************************************************************
 * Function: openFile()
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: opening file
 * Input parameters: ifstream& f , string filename
 * Returns: bool
 * Pre: -
 * Post: file opened
 **********************************************************/
bool openFile (ifstream& f , string filename) {
    f.open(filename);
    if (!f.is_open()) {
        cout << "Can't open the file" << endl;
        return false;
    } else {
        return true;
    }
}

/*************************************************************
 * Function: readAndComplete()
 * Date Created: 04/18/2023
 * Date Last Modified: 04/19/2023
 * Description: reads info from a file and computes operations
 * Input parameters: string filename
 * Returns: -
 * Pre: -
 * Post: -
 **********************************************************/
void readAndComplete (string filename) {
    ifstream f;
    Calculator calc;
    string arr['Z' + 1];
    string prom = "";
    string prom2 = "";
    string postfix = "";
    string answer = "";

    if (openFile(f, filename)) {
        getline (f , prom);
        while (prom != "#") {
            prom2 = prom.substr(2 , prom.length()-1);
            arr[prom.at(0)] = prom2;
            getline (f , prom);
        }

        calc.setSymbolTable(arr);

        getline (f , prom);

        while (prom != "#") {
            cout << "Infix Expression: " << prom << endl;
            postfix = calc.convertInfixToPostfix(prom);
            cout << "Postfix Equivalent: " << postfix << endl;
            answer = calc.evaluatePostfix(postfix);
            cout << "Expression value after postfix evaluation: " << answer << endl;
            getline (f , prom);
        }
    }
    f.close();
}