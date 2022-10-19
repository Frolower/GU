/*
 Name: Nikita Dubinin
 Class: CPCS 121, Fall 2022
 Date: Octeber 5, 2022
 Programming Assignment: PA3
 Description: different loops
 Notes: -
*/

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

int main() {
    string userString = " ";
    int i = 0;
    int creditHoursTotal = 0;
    int userInt = 0;
    string letterGrade = " ";
    int creditHours = 0;
    double gpa = 0.0;
    double numGrade = 0.0;
    int lineSum = 0;

    /*****
    Task 1
    *****/

    cout << "------Task 1------" << endl << endl;

    cout << "Enter your string" << endl;
    getline(cin , userString); // string input

    cout << endl << "------While loop------" << endl;

    while (i < userString.size()) { // this loop outputs user string by symbol in column
        cout << userString.at(i) << endl;
        i++;
    }

    /*****
    Same task with for loop
     *****/

    cout << endl << "------For loop------" << endl;

    for (i = 0; i < userString.size(); ++i) { // this loop outputs user string by symbol in column
        cout << userString.at(i) << endl;
    }

    cout << endl << "Press enter to continue" << endl;
    getchar();

    /*****
    Task 2
    *****/

    cout << endl << "------Task 2------" << endl << endl;

    cout << "Please enter the number of courses: ";
    cin >> userInt;

    for (i = 1; i <= userInt; ++i) { // loop that sum gpa
        numGrade = 0.0;

        cout << "Please enter the credit hours for course #" << i << ": ";
        cin >> creditHours;
        cout << "Please enter the letter grade for course #" << i << ": ";
        cin >> letterGrade;

        if (letterGrade == "A") { // if else statement that converts letter grade to number
            numGrade = 4.0;
        } else if (letterGrade == "A-") {
            numGrade = 3.7;
        } else if (letterGrade == "B+") {
            numGrade = 3.33;
        } else if (letterGrade == "B") {
            numGrade = 3.0;
        } else if (letterGrade == "B-") {
            numGrade = 2.7;
        } else if (letterGrade == "C+") {
            numGrade = 2.3;
        } else if (letterGrade == "C") {
            numGrade = 2.0;
        } else if (letterGrade == "C-") {
            numGrade = 1.7;
        } else if (letterGrade == "D+") {
            numGrade = 1.3;
        } else if (letterGrade == "D") {
            numGrade = 1.0;
        } else if (letterGrade == "D-") {
            numGrade = 0.7;
        } else {
                numGrade = 0.0;
        }
        creditHoursTotal += creditHours;
        gpa += numGrade * creditHours;
    }
    gpa = gpa / creditHoursTotal;

    cout << setprecision(3) << "Your GPA is: " << gpa << endl;

    cout << endl << "Press enter to continue" << endl;
    getchar();
    getchar();

    /*****
    Task 3
    *****/

    cout << endl << "------Task 3------" << endl << endl;

    cout << "Enter a lowercase string (it may contain spaces and punctuation): ";
    getline(cin , userString);

    for (i = 0; i < userString.size(); ++i) { // string that converts every char in string to upper case
        userString.at(i) = toupper(userString.at(i));
    }

    cout << "Your string converted to uppercase: " << userString << endl;

    cout << endl << "Press enter to continue" << endl;
    getchar();

    /*****
    Task 4
    *****/

    cout << endl << "------Task 4------" << endl;
    cout << "------Part 1------" << endl << endl;

    cout << "Enter integer number: ";
    cin >> userInt;

    for (i = 1; i <= userInt; ++i) { // this loop outputs num for num times
        for (int j = 1; j <= i; ++j) {
            cout << i;
        }
        cout << endl;
    }

    cout << endl << "------Part 2------" << endl << endl;

    for (i = 1; i <= userInt; ++i) { // this loop outputs num for num times
        for (int j = 1; j <= i; ++j) {
            cout << i;
            lineSum += i; // sum of numbers in line
        }
        cout << " " << lineSum << endl; // sum of numbers in line output
        lineSum = 0;
    }

    cout << endl << "Press enter to continue" << endl;
    getchar();
    getchar();

    /*****
    Task 5
    *****/

    cout << endl << "------Task 5------" << endl << endl;

    do { // this loop outputs menu until num 5 inputs
        cout << "Please choose from the following menu (1-5)" << endl;
        cout << "1) Display Game Rules & Description" << endl;
        cout << "2) Display General Game Commands" << endl;
        cout << "3) See High Scores" << endl;
        cout << "4) Play a New Game" << endl;
        cout << "5) Quit" << endl;

        cin >> userInt;

        switch (userInt) { // switch statement that outputs menu functions
            case 1:
                cout << "Display Game Rules & Description" << endl << endl;
                break;
            case 2:
                cout << "Display General Game Commands" << endl << endl;
                break;
            case 3:
                cout << "See High Scores" << endl << endl;
                break;
            case 4:
                cout << "Play a New Game" << endl << endl;
                break;
            case 5:
                cout << "Quit" << endl;
                break;
            default:
                cout << "Incorrect number" << endl << endl;
                break;
        }
    } while (userInt != 5); // working until cin not equal to 5

// to be continued... maybe

//    cout << endl << "Press enter to continue" << endl;
//    getchar();
//
//    cout << endl << "------Bonus task------" << endl << endl;
//
//    cout << "Enter integer number: ";
//    cin >> userInt;
//
//    for (i = userInt; i > 0; --i) {
//        if (i < userInt) {
//            for (int j = 0; j < 7*i; j++) {
//                cout << " ";
//            }
//            cout << "         o  *******" << endl;
//            for (int j = 0; j < 7*i; j++) {
//                cout << " ";
//            }
//            cout << "        /|\ *     *" << endl;
//            for (int j = 0; j < 7*i; j++) {
//                cout << " ";
//            }
//            cout << "        / \ *     *" << endl;
//            for (int j = 0; j < 7*i; j++) {
//                cout << " ";
//            }
//            cout << "    o  ******";
//            for (int j = 0; j < 7*i) {
//                cout << " ";
//            }
//        }
//        else {
//            cout << "  o  *******" << endl;
//            cout << " /|\ *     *" << endl;
//            cout << " / \ *     *" << endl;
//            cout << "******     *" << endl;
//        }
//    }

    return 0;
}