/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: January 30, 2023
 Programming Assignment: PA1
 Description: This program converts text to morse and backwards
 Notes: -
*/

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int NUM_ITEMS = 91;

void fillArr(string morseStrings[]);

int convType(string& inFilename, string& outFilename);

bool openFile (ifstream& infile, ofstream& outfile, string infilename , string outfilename);

void readFile(ifstream& infile, ofstream& outfile , int& numChars, int type , string morseStrings[]);

void convertAndWrite(char currentObj , ofstream& outfile , int& numChars , string morseStrings[] , bool& newLine);

void convertAndWrite(ofstream& outfile , bool& isSpace , char prom , int& numChars , string& currentObj , string morseStrings[]);

char findALatter(string morseStrings[] , string currentObj);

void writeStats(ofstream& outfile , int numChars);

void closeFiles (ifstream& infile , ofstream& outfile);

#endif //HEADER_H