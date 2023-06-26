#include "PA9.h"

int countDigits(string s) {
    if (s.length() == 0) {
        return 0;
    }
    if (isdigit(s.at(0))) {
        return 1 + countDigits(s.substr(1));
    } else {
        return countDigits(s.substr(1));
    }
}

void runTask1() {
    string s;
    countDigits(s);
}

int sumDigits(int num) {
    if (num == 0) {
        return 0;
    }
    return num % 10 + sumDigits(num / 10);
}

void runTask2() {
    int num = 0;
    sumDigits(num);
}


bool isPalindrome(string s) {
    if (s.length() <= 1) {
        return true;
    }

    if (s.at(0) == ' ') {
        s = s.substr(1 , s.length() - 1);
    }

    if (s.at(s.length() - 1) == ' ') {
        s = s.substr(0 , s.length() - 1);
    }

    if (s.at(0) == s.at(s.length() - 1)) {
        return isPalindrome(s.substr(1, s.length() - 2));
    } else {
        return false;
    }
}
	

void runTask3() {
    string s;
    isPalindrome(s);
}

void runTask4() {
    LinkedList ll;
    ll.getMaxValue();
}


void generateSubstringsHelper(string s, vector<string>& substrings, int start) {
    if (start == s.length()) {
        return;
    }
    for (int end = start; end < s.length(); end++) {
        substrings.push_back(s.substr(start, end - start + 1));
    }
    generateSubstringsHelper(s, substrings, start + 1);
}

void generateSubstrings(string s, vector<string>& substrings) {
    generateSubstringsHelper(s, substrings, 0);
    substrings.push_back("");
}


void runTask5() {
    vector <string> vec;
    string s = "";
    generateSubstrings(s , vec);
}

// BONUS ONLY: utility function for BONUS task
// no need for any changes here
void displayMaze(char maze[8][8]) {
	int i, j;
	cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
	for(i = 0; i < 8; i++) {
		cout << i;
		for(j = 0; j < 8; j++) {
			cout << " " << maze[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

// TODO: BONUS ONLY finish this function
bool traverseMaze(char maze[8][8], Coordinates solution[], int * steps, int currRow, int currCol) {
	return false; // TODO: fix this
}

// TODO: BONUS ONLY finish this function by testing traverseMaze()
void runBONUSTask() {
	
}
