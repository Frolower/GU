/*
 Name: Nikita Dubinin
 Class: CPCS 121, Fall 2022
 Date: September 21, 2022
 Programming Assignment: PA2
 Description:
 Notes: -
*/

#include <iostream>

using namespace std;

int main () {
    int integerAns = 0;
    int attemptCount = 0;
    double score = 0;
    char charAns = '\n';
    bool boolAns = false;

    while (charAns != 'b') {
        charAns = '\n';

        cout << "1) When was C++ released?" << endl;
        cout << "   a) 1972" << endl;
        cout << "   b) 1985" << endl;
        cout << "   c) 2000" << endl;
        cout << "   d) 2020" << endl;
        cout << "   e) 1995" << endl;
        cout << "Please enter a character a-e:" << endl;

        attemptCount++;

        cin >> charAns;

        if (charAns == 'b') {
            if (attemptCount == 1) {
                cout << "Your answer is right!" << endl;
                score++;
                attemptCount = 0;
            }
            else if (attemptCount == 2) {
                cout << "Your answer is right!" << endl;
                score += 0.75;
                attemptCount = 0;
            }
            else if (attemptCount == 3) {
                cout << "Your answer is right!" << endl;
                score += 0.5;
                attemptCount = 0;
            }
            else if (attemptCount == 4) {
                cout << "Your answer is right!" << endl;
                score += 0.25;
                attemptCount = 0;
            }
            else{
                cout << "Your answer is right!" << endl;
            }
        }
        else {
            cout << "That's wrong answer, try again." << endl;
        }
    }

    while (integerAns != 9) {
        integerAns = 0;

        cout << "2) How many lives does the cat have?" << endl;
        cout << "Enter your answer as integer:" << endl;

        attemptCount++;

        cin >> integerAns;

        if (integerAns == 9) {
            if (attemptCount == 1) {
                cout << "Your answer is right!" << endl;
                score++;
                attemptCount = 0;
            }
            else if (attemptCount == 2) {
                cout << "Your answer is right!" << endl;
                score += 0.75;
                attemptCount = 0;
            }
            else if (attemptCount == 3) {
                cout << "Your answer is right!" << endl;
                score += 0.5;
                attemptCount = 0;
            }
            else if (attemptCount == 4) {
                cout << "Your answer is right!" << endl;
                score += 0.25;
                attemptCount = 0;
            }
            else{
                cout << "Your answer is right!" << endl;
            }
        }
        else {
            cout << "That's wrong answer, try again." << endl;
        }
    }

    while (charAns != 'e') {
        charAns = '\n';

        cout << "3) Which company released first home computer?" << endl;
        cout << "   a) Apple" << endl;
        cout << "   b) IBM" << endl;
        cout << "   c) Oracle" << endl;
        cout << "   d) Ubuntu" << endl;
        cout << "   e) No right answer" << endl;
        cout << "Please enter a character a-e" << endl;

        attemptCount++;

        cin >> charAns;

        if (charAns == 'e') {
            if (attemptCount == 1) {
                cout << "You're right, first home pc was the Kenbak-1, released in early 1971!" << endl;
                score++;
                attemptCount = 0;
            }
            else if (attemptCount == 2) {
                cout << "You're right, first home pc was the Kenbak-1, released in early 1971!" << endl;
                score += 0.75;
                attemptCount = 0;
            }
            else if (attemptCount == 3) {
                cout << "You're right, first home pc was the Kenbak-1, released in early 1971!" << endl;
                score += 0.5;
                attemptCount = 0;
            }
            else if (attemptCount == 4) {
                cout << "You're right, first home pc was the Kenbak-1, released in early 1971!" << endl;
                score += 0.25;
                attemptCount = 0;
            }
            else{
                cout << "You're right, first home pc was the Kenbak-1, released in early 1971!" << endl;
            }
        }
        else {
            cout << "That's wrong answer, try again." << endl;
        }
    }

    while (integerAns != 42) {
        integerAns = 0;

        cout << "4) Whats the answer for the Ultimate Question from the hitchhiker's guide to the galaxy" << endl;
        cout << "Enter your answer as integer:" << endl;

        attemptCount++;

        cin >> integerAns;

        if (integerAns == 42) {
            if (attemptCount == 1) {
                cout << "Exactly! It's the right answer for the Ultimate Question to Life, The Universe, and Everything!" << endl;
                score++;
                attemptCount = 0;
            }
            else if (attemptCount == 2) {
                cout << "Exactly! It's the right answer for the Ultimate Question to Life, The Universe, and Everything!" << endl;
                score += 0.75;
                attemptCount = 0;
            }
            else if (attemptCount == 3) {
                cout << "Exactly! It's the right answer for the Ultimate Question to Life, The Universe, and Everything!" << endl;
                score += 0.5;
                attemptCount = 0;
            }
            else if (attemptCount == 4) {
                cout << "Exactly! It's the right answer for the Ultimate Question to Life, The Universe, and Everything!" << endl;
                score += 0.25;
                attemptCount = 0;
            }
            else{
                cout << "Exactly! It's the right answer for the Ultimate Question to Life, The Universe, and Everything!" << endl;
            }
        }
        else {
            cout << "That's wrong answer, try again." << endl;
        }
    }

    while (!boolAns) {
        boolAns = false;

        cout << "5) Is it true, that after his flight to the moon Neil Armstrong had to go through customs and declare moon rock as cargo?" << endl;
        cout << "Enter 1 if true and 0 if false" << endl;
        cout << "You only have one attempt to score a point for this question" << endl;

        attemptCount++;

        cin >> integerAns;

        boolAns = static_cast<bool>(integerAns);

        if (boolAns) {
            if (attemptCount == 1) {
                cout << "Yes, it's true!" << endl;
                score++;
                attemptCount = 0;
            }
            else {
                cout << "Yes, it's true!" << endl;
            }
        }
        else {
            cout << "That's wrong answer, try again." << endl;
        }
    }

    while (charAns != 'd') {
        charAns = '\n';

        cout << "6) What is the real name of the actor who played Sherlock Holmes?" << endl;
        cout << "   a) Banister Crumblebench" << endl;
        cout << "   b) Butterclap Cumbersnatch" << endl;
        cout << "   c) Bonkyhort Cutiebrunch" << endl;
        cout << "   d) Benedict Cumberbatch" << endl;
        cout << "   e) Bodysnatch Cumberbund" << endl;
        cout << "Please enter a character a-e" << endl;

        attemptCount++;

        cin >> charAns;

        if (charAns == 'd') {
            if (attemptCount == 1) {
                cout << "Are you sure..? Well, seems like you're right!" << endl;
                score++;
                attemptCount = 0;
            }
            else if (attemptCount == 2) {
                cout << "Are you sure..? Well, seems like you're right!" << endl;
                score += 0.75;
                attemptCount = 0;
            }
            else if (attemptCount == 3) {
                cout << "Are you sure..? Well, seems like you're right!" << endl;
                score += 0.5;
                attemptCount = 0;
            }
            else if (attemptCount == 4) {
                cout << "Are you sure..? Well, seems like you're right!" << endl;
                score += 0.25;
                attemptCount = 0;
            }
            else{
                cout << "Are you sure..? Well, seems like you're right!" << endl;
            }
        }
        else {
            cout << "That's wrong answer, try again." << endl;
        }
    }

    boolAns = true;

    while (boolAns) {
        boolAns = true;

        cout << "7) Is it true, that Warner Bros Company was founded just after the collapse of the Ottoman Empire?" << endl;
        cout << "Enter 1 if true and 0 if false" << endl;
        cout << "You only have one attempt to score a point for this question" << endl;

        attemptCount++;

        cin >> integerAns;

        boolAns = static_cast<bool>(integerAns);

        if (!boolAns) {
            if (attemptCount == 1) {
                cout << "Yes! It was founded during the time when the Ottoman Empire exists!" << endl;
                score++;
                attemptCount = 0;
            }
            else{
                cout << "Yes! It was founded during the time when the Ottoman Empire exists!" << endl;
            }
        }
        else {
            cout << "That's wrong answer, try again." << endl;
        }
    }

    boolAns = false;

    while (integerAns != 7) {
        integerAns = 0;

        cout << "8) How many schools and colleges do Gonzaga University include?" << endl;
        cout << "Enter your answer as integer:" << endl;

        attemptCount++;

        cin >> integerAns;

        if (integerAns == 7) {
            if (attemptCount == 1) {
                cout << "Your answer is right!" << endl;
                score++;
                attemptCount = 0;
            }
            else if (attemptCount == 2) {
                cout << "Your answer is right!" << endl;
                score += 0.75;
                attemptCount = 0;
            }
            else if (attemptCount == 3) {
                cout << "Your answer is right!" << endl;
                score += 0.5;
                attemptCount = 0;
            }
            else if (attemptCount == 4) {
                cout << "Your answer is right!" << endl;
                score += 0.25;
                attemptCount = 0;
            }
            else{
                cout << "Your answer is right!" << endl;
            }
        }
        else {
            cout << "That's wrong answer, try again." << endl;
        }
    }

    while (integerAns != 50) {
        integerAns = 0;

        cout << "9) How many states does the United States include?" << endl;
        cout << "Enter your answer as integer:" << endl;

        attemptCount++;

        cin >> integerAns;

        if (integerAns == 50) {
            if (attemptCount == 1) {
                cout << "Your answer is right!" << endl;
                score++;
                attemptCount = 0;
            }
            else if (attemptCount == 2) {
                cout << "Your answer is right!" << endl;
                score += 0.75;
                attemptCount = 0;
            }
            else if (attemptCount == 3) {
                cout << "Your answer is right!" << endl;
                score += 0.5;
                attemptCount = 0;
            }
            else if (attemptCount == 4) {
                cout << "Your answer is right!" << endl;
                score += 0.25;
                attemptCount = 0;
            }
            else{
                cout << "Your answer is right!" << endl;
            }
        }
        else {
            cout << "That's wrong answer, try again." << endl;
        }
    }

    while (charAns != 'b') {
        charAns = '\n';

        cout << "10) Which city is the capital of the EU" << endl;
        cout << "   a) Vienna" << endl;
        cout << "   b) Brussels" << endl;
        cout << "   c) Berlin" << endl;
        cout << "   d) Hamburg" << endl;
        cout << "   e) Rome" << endl;
        cout << "Please enter a character a-e" << endl;

        attemptCount++;

        cin >> charAns;

        if (charAns == 'b') {
            if (attemptCount == 1) {
                cout << "Your answer is right!" << endl;
                score++;
                attemptCount = 0;
            }
            else if (attemptCount == 2) {
                cout << "Your answer is right!" << endl;
                score += 0.75;
                attemptCount = 0;
            }
            else if (attemptCount == 3) {
                cout << "Your answer is right!" << endl;
                score += 0.5;
                attemptCount = 0;
            }
            else if (attemptCount == 4) {
                cout << "Your answer is right!" << endl;
                score += 0.25;
                attemptCount = 0;
            }
            else{
                cout << "Your answer is right!" << endl;
            }
        }
        else {
            cout << "That's wrong answer, try again." << endl;
        }
    }

    cout << "You scored " << score << "/10." << endl;

    return 0;
}