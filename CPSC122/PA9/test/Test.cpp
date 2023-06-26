#include <algorithm>
#include <unordered_set>

#include "gtest/gtest.h"
#include "PA9.h"

// needed for traverseMaze() test
void initializeCoordinates(Coordinates[], int);

// NOTE: the order is expected/solution, actual/received student value
TEST(Task1, countDigits) {
	EXPECT_EQ(0, countDigits("ABC"));
	EXPECT_EQ(0, countDigits(""));
	EXPECT_EQ(3, countDigits("123"));
	EXPECT_EQ(2, countDigits("R2D2"));
	EXPECT_EQ(4, countDigits("C6H12O6"));
	EXPECT_EQ(3, countDigits("abc123xyz"));
}

TEST(Task2, sumDigits) {
	EXPECT_EQ(5, sumDigits(5));
	EXPECT_EQ(0, sumDigits(0));
	EXPECT_EQ(31, sumDigits(16978));
	EXPECT_EQ(45, sumDigits(1234567890));
	EXPECT_EQ(12, sumDigits(3333));
}

TEST(Task3, isPalindrome) {
	const int SIZE = 12;

    // Create an array of strings to test.
    string testStrings[SIZE] = 
	        { "deed",
              "LEVEL",
              "race car",
              "gonzaga",
              "ABLE WAS I ERE I SAW ELBA",
              "FOUR SCORE AND SEVEN YEARS AGO",
              "NOW IS THE TIME FOR ALL GOOD MEN",
              "DESSERTS I STRESSED",
              "ASK NOT WHAT YOUR COUNTRY CAN DO FOR YOU",
              "KAYAK", 
              "MADAM IM ADAM", 
              "amanaplanacanalpanama"};
   bool testResults[SIZE] = {true, true, true, false, true, false, false, true, false, true, true, true};
   
   for (int i = 0; i < SIZE; i++) {
	  EXPECT_EQ(testResults[i], isPalindrome(testStrings[i]));
   }
}

TEST(Task4, getMaxValue) {
	LinkedList list;

	EXPECT_EQ(-1, list.getMaxValue()); // empty list
	list.appendNode(10);
	EXPECT_EQ(10, list.getMaxValue()); // single item in list
	
	list.appendNode(5);
	EXPECT_EQ(10, list.getMaxValue());
	
	list.appendNode(30);
	EXPECT_EQ(30, list.getMaxValue());
	
	list.appendNode(20);
	EXPECT_EQ(30, list.getMaxValue());
	
	list.appendNode(40);
	EXPECT_EQ(40, list.getMaxValue());
}

TEST(Task5, generateSubstrings) {
	vector<string> substrings;
	vector<string> substringSolutions({"bird", "bir", "bi", "b", "ird", "ir", "i", "rd", "r", "d", ""});
	generateSubstrings("bird", substrings);
	EXPECT_EQ(11, static_cast<int>(substrings.size()));
	for (string s : substringSolutions) {
		EXPECT_EQ(1, count(substrings.begin(), substrings.end(), s));
	}
	
	substrings.clear();
	substringSolutions = vector<string>({"bulldog", "bulldo", "bulld", "bull", "bul", "bu", "b", "ulldog", "ulldo", "ulld", "ull", "ul", "u", "lldog", "lldo", "lld", "ll", "l", "ldog", "ldo", "ld", "l", "dog", "do", "d", "og", "o", "g", ""});
	generateSubstrings("bulldog", substrings);
	EXPECT_EQ(29, static_cast<int>(substrings.size()));
	EXPECT_EQ(2, count(substrings.begin(), substrings.end(), "l")); // 2 "l"
	
	unordered_set<string> substringsSet;
	for (string s: substrings) {
		substringsSet.insert(s);
	}
	for (string s : substringSolutions) {
		EXPECT_EQ(1, count(substringsSet.begin(), substringsSet.end(), s));
	}
	
	// empty string
	substrings.clear();
	substringSolutions = vector<string>({""});
	generateSubstrings("", substrings);
	EXPECT_EQ(1, static_cast<int>(substrings.size()));
	EXPECT_EQ(1, count(substrings.begin(), substrings.end(), ""));
}

// needed for traverseMaze() test
void initializeCoordinates(Coordinates arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = {0, 0};
	}
}

// BONUS: this last test is for the BONUS task
// which is recursive maze traversal
TEST(BONUSTask, BONUStraverseMaze) {
	// starts at 0, 0 trying to get to 7, 7
	char maze[8][8] =  {{' ', ' ', 'X', ' ', ' ', ' ', 'X', 'X'},
						{'X', ' ', ' ', 'X', ' ', ' ', ' ', ' '},
						{'X', 'X', ' ', 'X', ' ', ' ', ' ', ' '},
						{' ', ' ', ' ', 'X', ' ', ' ', ' ', ' '},
						{' ', ' ', ' ', 'X', ' ', ' ', ' ', ' '},
						{' ', ' ', ' ', 'X', 'X', ' ', 'X', ' '},
						{' ', ' ', ' ', 'X', 'X', ' ', 'X', ' '},
						{' ', ' ', ' ', ' ', ' ', ' ', 'X', ' '}};
	Coordinates solution[64];
	int steps = 0;
	bool solutionExists = false;
	
	solutionExists = traverseMaze(maze, solution, &steps, 0, 0); 
	EXPECT_EQ(true, solutionExists);
	
	char maze2[8][8] = {{' ', ' ', 'X', ' ', ' ', ' ', 'X', 'X'},
						{'X', ' ', ' ', 'X', ' ', ' ', ' ', ' '},
						{'X', 'X', ' ', 'X', ' ', ' ', ' ', ' '},
						{' ', ' ', ' ', 'X', ' ', ' ', ' ', ' '},
						{' ', ' ', ' ', 'X', ' ', ' ', ' ', ' '},
						{' ', ' ', ' ', 'X', 'X', ' ', 'X', 'X'},
						{' ', ' ', ' ', 'X', 'X', ' ', 'X', ' '},
						{' ', ' ', ' ', ' ', ' ', ' ', 'X', ' '}};
	Coordinates solution2[64];
	steps = 0;
	
	solutionExists = traverseMaze(maze2, solution2, &steps, 0, 0); 
	EXPECT_EQ(false, solutionExists);
	
	char maze3[8][8] = {{' ', 'X', ' ', ' ', ' ', 'X', 'X', 'X'},
						{' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X'},
						{' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X'},
						{' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X'},
						{' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X'},
						{' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X'},
						{' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X'},
						{' ', ' ', ' ', 'X', ' ', ' ', ' ', ' '}};
	Coordinates solution3[64];
	steps = 0;
	
	solutionExists = traverseMaze(maze3, solution3, &steps, 0, 0); 
	EXPECT_EQ(true, solutionExists);
	EXPECT_EQ(29, steps);
	
	char maze4[8][8] = {{' ', 'X', ' ', ' ', ' ', 'X', ' ', 'X'},
						{' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
						{' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
						{' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
						{' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
						{' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
						{' ', 'X', ' ', 'X', ' ', ' ', ' ', 'X'},
						{' ', ' ', ' ', 'X', 'X', 'X', 'X', ' '}};
	Coordinates solution4[64];
	steps = 0;
	
	solutionExists = traverseMaze(maze4, solution4, &steps, 0, 0); 
	EXPECT_EQ(false, solutionExists);
	
	char maze5[8][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
						{'X', 'X', 'X', 'X', 'X', 'X', 'X', ' '},
						{' ', 'X', ' ', 'X', ' ', 'X', 'X', ' '},
						{' ', 'X', ' ', 'X', ' ', 'X', 'X', ' '},
						{' ', 'X', ' ', 'X', ' ', 'X', 'X', ' '},
						{' ', 'X', ' ', 'X', ' ', 'X', 'X', ' '},
						{' ', 'X', 'X', 'X', 'X', ' ', 'X', ' '},
						{' ', ' ', ' ', ' ', ' ', 'X', 'X', ' '}};
	Coordinates solution5[64];
	Coordinates solution5Solution[] = {{7, 7}, {6, 7}, {5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7}, {0, 6}, {0, 5}, {0, 4}, {0, 3}, {0, 2}, {0, 1}, {0, 0}};
	steps = 0;
	
	solutionExists = traverseMaze(maze5, solution5, &steps, 0, 0); 
	EXPECT_EQ(true, solutionExists);
	EXPECT_EQ(15, steps);
	for (int i = 0; i < steps; i++) {
		EXPECT_EQ(solution5Solution[i].row, solution5[i].row);
		EXPECT_EQ(solution5Solution[i].col, solution5[i].col);
	}
}
