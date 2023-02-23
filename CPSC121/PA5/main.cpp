/*
 Name: Nikita Dubinin
 Date: October 19, 2022
 Programming Assignment: PA5
 Description: pet store summarize
 Notes: I'm attempting for the extra credits
*/

#include <iostream> //working with input/output
#include <fstream> //working with files
#include <string> //working with strings
#include <cmath> //round() function
#include <sstream> //parsing for a date

using namespace std;

int avgDaysCount (double totalDays, int numPets); //function that counts average number of days in the store

int main() {
    //initializing variables for work with files
    string inputFilename = "petstore.txt";
    string outputFilename = "summaryreport.txt";
    string line = " ";
    string garbage = " ";

    //initializing variables for parsing last string
    string date = " ";

    //initializing variables for operations with main data
    string petName = " ";
    string animalType = " ";
    int numDaysAtStore = 0;
    double totalDays = 0;
    int minDays = 99999;
    int maxDays = 0;
    int numPets = 0;
    int numCats = 0;
    int numDogs = 0;
    int numPigs = 0;
    int numOthers = 0;

    //initializing files stream
    ifstream infile;
    ofstream outfile;

    //opening files
    infile.open(inputFilename);
    outfile.open(outputFilename);

    //check if files are opened successfully
    if (!infile.is_open()) {
        cout << "Unable to open the input file" << endl;
        return -1;
    } else {
        cout << "Input file successfully opened." << endl;
    }

    if (!outfile.is_open()) {
        cout << "Unable to open the output file" << endl;
        return -1;
    } else {
        cout << "Output file successfully opened." << endl << endl;
    }

    //creating basic information block
    getline(infile , line);
    cout << "Reading in pet list from store: \"" << line << "\"..." << endl << endl;
    outfile << "Store: " << line << endl;

    getline(infile , garbage); // empty line

    while (!infile.eof()) {
        if (infile.good()) {
            getline(infile, line); //check if this is a last line
            if (line.substr(0 , 13) == "Last updated:") {
                break;
            }

            //collecting information about the pet
            petName = line;
            getline(infile , animalType);
            infile >> numDaysAtStore;

            //empty lines
            getline(infile , garbage);
            getline(infile , garbage);

            if (numDaysAtStore > 90) { //check if the pet is still in the store
                cout << "Processing " << animalType << " \"" << petName << "\"... " << "moved to a different store." << endl;
            } else {
                cout << "Processing " << animalType << " \"" << petName << "\"... " << numDaysAtStore << " day(s) on site." << endl;
            }

            if (animalType == "cat") { //check what type of animal is it
                numCats++;
            } else if (animalType == "pig") {
                numPigs++;
            } else if (animalType == "dog") {
                numDogs++;
            } else {
                numOthers++;
            }

            if (maxDays < numDaysAtStore) { //checking for a maximum days in store
                maxDays = numDaysAtStore;
            }
            if (minDays > numDaysAtStore) { //checking for a minimum days in store
                minDays = numDaysAtStore;
            }

            totalDays += numDaysAtStore;

            numPets++;
        }
    }

    //information for user
    cout << endl << "Pet store data processed!" << endl << endl;
    cout << "Generating summary report... " << endl << endl;

    //creating a summary for a file
    outfile << "Number of pets: " << numPets << endl << endl;
    outfile << "Pet Information Summary Statistics:" << endl;
    outfile << "___________________________________" << endl;
    outfile << "Count of each animal:" << endl;
    outfile << "Cat - " << numCats << ", Dog - " << numDogs << ", Pig - " << numPigs << ", Other - " << numOthers << endl;
    outfile << "Most days on site: " << maxDays << endl;
    outfile << "Fewest days on site: " << minDays << endl;
    outfile << "Average days on site: " << avgDaysCount(totalDays , numPets) << endl << endl;

    //parsing last string for a date
    istringstream inSS(line);
    inSS >> garbage; //useless part for this project
    inSS >> garbage; //useless part for this project
    inSS >> date;

    outfile << "Pet store list was last modified on " << date;

    cout << "Done!" << endl; //final information for user

    //closing files
    infile.close();
    outfile.close();
    return 0;
    //ask about 90 days for pet in store
}

int avgDaysCount (double totalDays, int numPets) {
    return round(totalDays / numPets); //taking double and integer, then rounding it and returning an integer
}