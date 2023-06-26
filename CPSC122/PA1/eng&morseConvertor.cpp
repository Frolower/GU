/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: January 30, 2023
 Programming Assignment: PA1
 Description: This program converts text to morse and backwards
 Notes: -
*/

#include "eng&morseConvertorHeader.h"

int main() {
    string inFilename = "";
    string outFilename = "";

    string morseStrings[NUM_ITEMS];

    int numConverted = 0;
    int type = 2;

    fillArr(morseStrings);

    ifstream infile;
    ofstream outfile;

    type = convType(inFilename , outFilename);

    if(!openFile (infile, outfile, inFilename , outFilename)) {
        return -1;
    }

    readFile( infile, outfile , numConverted, type , morseStrings);

    writeStats(outfile , numConverted);

    closeFiles ( infile , outfile);

    return 0;
}