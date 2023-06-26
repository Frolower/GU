/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: February 10, 2023
 Programming Assignment: PA2
 Description: This program researches sorting algorithms
 Notes: -
*/

#include "SortingAnalysisHeader.h"

int main() {
    string filename = "output.csv";

    ofstream outfile;

    outfile.open(filename);

    if (!outfile.is_open()) {
        cout << "Problem with opening file" << endl;
        return -1;
    }

    testSortingAlgorithms(outfile);

	return 0;
}