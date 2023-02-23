/*
 Name: Nikita Dubinin
 Class: CPCS 121, Fall 2022
 Date: Octeber 10, 2022
 Programming Assignment: PA4
 Description: crops game
 Notes: -
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main () {
    int bankBalance = 0, wager = 0, dice1 = 0, dice2 = 0, diceSum = 0, point = 0, totalWager = 0;
    char playerAns = '\n';
    bool isEnd = false;

    cout << "Welcome to the \"Craps\"!" << endl;
    cout << "Here's the rules: A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots." << endl;
    cout << "After the dice have come to rest, the sum of the spots on the two upward faces is calculated." << endl;
    cout << "If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw " << endl;
    cout << "(called \"craps\"), the player loses (i.e. the \"house\" wins). If the sum is 4, 5, 6, 8, 9, or 10 on the " << endl;
    cout << "first throw, then the sum becomes the player's \"point.\" To win, you must continue rolling the dice" << endl;
    cout << "until you \"make your point.\" The player loses by rolling a 7 before making the point. " << endl;

    cout << endl << "Do you want to play? (y/n) ";
    cin >> playerAns;

    if (playerAns != 'y' && playerAns != 'n') {
        while (playerAns != 'y' && playerAns != 'n') { //answer validating
            cout << "Incorrect answer, enter y or n" << endl;
            cout << "Do you want to play? (y/n) ";
            cin >> playerAns;
        }
    }



    if (playerAns == 'y') {
        cout << "Enter your bank balance: ";
        cin >> bankBalance;

        while (bankBalance <= 0) { //balance validating
            cout << "Your balance should be positive" << endl;
            cout << "Enter your bank balance: ";
            cin >> bankBalance;
        }
        while (playerAns == 'y') {

            //restore values of variables to 0
            dice1 = 0;
            dice2 = 0;
            diceSum = 0;
            point = 0;
            isEnd = false;

            if (bankBalance > 0) {
                cout << "Enter your wager: ";
                cin >> wager;
                totalWager += wager;
                while (wager <= 0 || wager > bankBalance) { //wager validating
                    cout << "Your wager should be positive and less or equal to your bank balance" << endl;
                    cout << "Enter your wager: ";
                    cin >> wager;
                }
                if (wager <= bankBalance) {
                    srand(time(0));
                    dice1 = rand() % 6 + 1;
                    dice2 = rand() % 6 + 1;
                    diceSum = dice1 + dice2;
                    if (diceSum == 7 || diceSum == 11) {
                        cout << "You won! Your dice sum is " << diceSum << ". Dice 1: " << dice1 << " Dice 2: " << dice2 << endl;
                        cout << "You won $" << wager*2 << endl;
                        bankBalance += wager;
                    } else if (diceSum == 2 || diceSum == 3 || diceSum == 12) {
                        cout << "You lost. Your dice sum is " << diceSum << ". Dice 1: " << dice1 << " Dice 2: " << dice2 << endl;
                        cout << "You lost $" << wager << endl;
                        bankBalance -= wager;
                    } else {
                        point = diceSum;
                        cout << "Your point is " << point << endl;
                        cout << endl << "Press enter to continue" << endl;
                        getchar();
                        getchar();
                        while (!isEnd) {
                            dice1 = rand() % 6 + 1;
                            dice2 = rand() % 6 + 1;
                            diceSum = dice1 + dice2;
                            if (diceSum == 7) {
                                cout << "You lost. Your dice sum is " << diceSum << ". Dice 1: " << dice1 << " Dice 2: " << dice2 << endl;
                                cout << "You lost $" << wager << endl;
                                bankBalance -= wager;
                                isEnd = true;
                            } else if (diceSum == point) {
                                cout << "You won! Your dice sum is " << diceSum << ". Dice 1: " << dice1 << " Dice 2: " << dice2 << ". And your point is " << point << endl;
                                cout << "You won $" << wager*2 << endl;
                                bankBalance += wager;
                                isEnd = true;
                            } else {
                                cout << "Your dice sum is " << diceSum << ". Dice 1: " << dice1 << " Dice 2: " << dice2 << endl;
                                cout << "Reroll" << endl;
                                cout << endl << "Press enter to continue" << endl;
                                getchar();
                            }

                        }

                    }


                } else {
                    while (wager <= 0) { //wager validating
                        cout << "Your wager should be positive" << endl;
                        cout << "Enter your wager: ";
                        cin >> wager;
                    }
                }
            } else {
                while (bankBalance <= 0) { //bank balance validating
                    cout << "Your bank balance should be positive" << endl;
                    cout << "Enter your bank balance: ";
                    cin >> bankBalance;
                }
            }

            cout << endl << "Your balance is $" << bankBalance << endl;
            cout << "Your total wager is $" << totalWager << endl;
            cout << "Do you want to play? (y/n) ";
            cin >> playerAns;

            while (playerAns != 'y' && playerAns != 'n') { //answer validating
                cout << "Incorrect answer, enter y or n" << endl;
                cout << "Do you want to play? (y/n) ";
                cin >> playerAns;
            }
        }
    }

    cout << "Have a good day!" << endl;



    return 0;
}