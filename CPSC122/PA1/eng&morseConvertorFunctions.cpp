/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: January 30, 2023
 Programming Assignment: PA1
 Description: This program converts text to morse and backwards
 Notes: -
*/

#include "eng&morseConvertorHeader.h"

/*************************************************************
 * Function: fillArr()
 * Date Created: 30/01/2023
 * Date Last Modified: 30/01/2023
 * Description: This function fills array with required morse symbols
 * Input parameters: Array to fill
 * Returns: Nothing
 * Pre: Array must be string type and at least 91 length
 * Post: Array is filled
 *************************************************************/

void fillArr(string morseStrings[]) {
    morseStrings[48] = "-----";
    morseStrings[49] = "..---";
    morseStrings[50] = "...--";
    morseStrings[51] = "....-";
    morseStrings[52] = ".....";
    morseStrings[53] = "-....";
    morseStrings[54] = "--...";
    morseStrings[55] = "---..";
    morseStrings[56] = "----.";
    morseStrings[57] = ".----";
    morseStrings[65] = ".-";
    morseStrings[66] = "-...";
    morseStrings[67] = "-.-.";
    morseStrings[68] = "-..";
    morseStrings[69] = ".";
    morseStrings[70] = "..-.";
    morseStrings[71] = "--.";
    morseStrings[72] = "....";
    morseStrings[73] = "..";
    morseStrings[74] = ".---";
    morseStrings[75] = "-.-";
    morseStrings[76] = ".-..";
    morseStrings[77] = "--";
    morseStrings[78] = "-.";
    morseStrings[79] = "---";
    morseStrings[80] = ".--.";
    morseStrings[81] = "--.-";
    morseStrings[82] = ".-.";
    morseStrings[83] = "...";
    morseStrings[84] = "-";
    morseStrings[85] = "..-";
    morseStrings[86] = "...-";
    morseStrings[87] = ".--";
    morseStrings[88] = "-..-";
    morseStrings[89] = "-.--";
    morseStrings[90] = "--..";
}

/*************************************************************
 * Function: convType()
 * Date Created: 30/01/2023
 * Date Last Modified: 30/01/2023
 * Description: This function defines type of conversion: 0 - morse to english,
 * 1 - english to morse, 2 - error, and accepts names of files that should be open in the next step
 * Input parameters: Input/output file names, passed by reference
 * Returns: Type of conversion
 * Pre: -
 * Post: Gives you type of conversion and names of files to open in the next step
 *************************************************************/

int convType(string& inFilename, string& outFilename) {
    string type = "";

    cout << "Enter conversion type: -m if english to morse, -t if morse to english: ";
    cin >> type;

    cout << "Enter input file name: ";
    cin >> inFilename;

    cout << "Enter output file name: ";
    cin >> outFilename;

    if(type == "-t") {
        return 0;
    } else if(type == "-m") {
        return 1;
    } else {
        cout << "invalid input" << endl;
        return -1;
    }
}

/*************************************************************
 * Function: openFile()
 * Date Created: 30/01/2023
 * Date Last Modified: 30/01/2023
 * Description: This function open input/output files
 * Input parameters: Ifstream/ofstream , input/output file names
 * Returns: True if both files opened successfully, false is failed to open one of the files
 * Pre: Names of the files from convType()
 * Post: Allows you to work with files
 *************************************************************/


bool openFile (ifstream& infile, ofstream& outfile, string infilename , string outfilename) {
    infile.open(infilename);


    if(!infile.is_open()) {
        cout << "Unavailable to open input file" << endl;
        return false;
    }

    outfile.open(outfilename);

    if(!outfile.is_open()) {
        cout << "Unavailable to open output file" << endl;
        return false;
    }

    return true;
}

/*************************************************************
 * Function: readFile()
 * Date Created: 30/01/2023
 * Date Last Modified: 30/01/2023
 * Description: This function read symbols from the input file, and, based on
 * conversion type passes required values to convertAndWrite() functions
 * Input parameters: Ifstream/ofstream , number of chars that were converted, conversion type 0/1, array with morse strings
 * Returns: void
 * Pre: files should be open successful with openFile()
 * Post: After the end of function you receive converted text
 *************************************************************/

void readFile(ifstream& infile, ofstream& outfile , int& numChars, int type , string morseStrings[]) {
    if (type == 0) {
        bool isSpace = false;
        string currentObj = "";
        while(!infile.eof()) {
            char prom = infile.get();
            convertAndWrite(outfile , isSpace , prom , numChars , currentObj , morseStrings);
        }
    } else {
        bool newLine = true;
        while (!infile.eof()) {
            char currentObj = '\n';

            currentObj = toupper(infile.get());
            if (currentObj == '\n') {
                newLine = true;
            }
            convertAndWrite(currentObj , outfile , numChars , morseStrings , newLine);
        }
    }
}

/*************************************************************
 * Function: convertAndWrite()
 * Date Created: 30/01/2023
 * Date Last Modified: 31/01/2023
 * Description: First of two version of this function. Converts text from askII to morse code and writing it to the file
 * Input parameters: currentObj - current latter/space/new line symbol , outfile , numChars - num chars converted
 * morseStrings[] - array with morse codes , newLine - help to define new line not to start it with space symbol
 * Returns: void
 * Pre: working only inside readFile()
 * Post: After the end of function you receive converted text
 *************************************************************/

void convertAndWrite(char currentObj , ofstream& outfile , int& numChars , string morseStrings[] , bool& newLine) {
    int asciiNum = 0;
    asciiNum = static_cast<int>(currentObj);
    if (currentObj == ' ') {
        outfile << " ";
        numChars++;
    } else if (asciiNum == 10) {
        outfile << endl;
        numChars++;
    } else if (asciiNum >= 0) {
        numChars++;
        if (newLine) {
            outfile << morseStrings[asciiNum];
            newLine = false;
        } else {
            outfile << " " << morseStrings[asciiNum];
        }
    }
}

/*************************************************************
 * Function: convertAndWrite()
 * Date Created: 30/01/2023
 * Date Last Modified: 31/01/2023
 * Description: Overloaded version of this function to convert morse code to askII and write it to the file
 * Input parameters: currentObj - current string that combines into morse code of one letter, passed by reference,
 * outfile , numChars - num chars converted
 * morseStrings[] - array with morse codes, prom - char that function is checking before add to currentObj
 * isSpace - helps to define is it a space between symbols or actual space, passed by reference
 * Returns: void
 * Pre: working only inside readFile()
 * Post: After the end of function you receive converted text
 *************************************************************/

void convertAndWrite(ofstream& outfile , bool& isSpace , char prom , int& numChars , string& currentObj , string morseStrings[]) {
    if (isSpace && prom == ' ') {
        outfile << " ";
        isSpace = false;
        numChars++;
    } else if (prom == ' ' || prom == '\n') {
        outfile << findALatter(morseStrings ,  currentObj);
        isSpace = true;
        currentObj = "";
        numChars++;
        if (prom == '\n') {
            outfile << endl;
            isSpace = false;
            numChars++;
        }
    } else if(prom == -1) {
        outfile << findALatter(morseStrings ,  currentObj);
        numChars++;
    } else {
        currentObj += prom;
        isSpace = false;
    }
}

/*************************************************************
 * Function: findALatter()
 * Date Created: 31/01/2023
 * Date Last Modified: 31/01/2023
 * Description: Looks though array with morse strings for needed string
 * morseStrings[] - array with morse codes, currentObj - string that function are looking for in the array
 * Returns: character to be written in the output file
 * Pre: requests currentObj
 * Post: Returns correct askII symbol
 *************************************************************/

char findALatter(string morseStrings[] , string currentObj) {
    for (int i = 48; i < NUM_ITEMS; i++) {
        if (morseStrings[i] == currentObj) {
            char latter = i;
            return latter;
        }
    }
}

/*************************************************************
 * Function: writeStats()
 * Date Created: 30/01/2023
 * Date Last Modified: 30/01/2023
 * Description: Writes statistic at the end of output file, gives the number of converted symbols
 * Returns: void
 * Pre: working after everything else were done
 * Post: After the end of function you receive statistics part of conversion
 *************************************************************/

void writeStats(ofstream& outfile , int numChars) {
    outfile << endl << "Total characters converted successfully (including newline and white spaces): " << numChars << endl;
}

/*************************************************************
 * closeFiles: closeFiles()
 * Date Created: 30/01/2023
 * Date Last Modified: 30/01/2023
 * Description: Closes files
 * Returns: void
 * Pre: Files must be open
 * Post: Closing files for work
 *************************************************************/

void closeFiles (ifstream& infile , ofstream& outfile) {
    infile.close();
    outfile.close();
}