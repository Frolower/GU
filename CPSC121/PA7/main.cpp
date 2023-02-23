/*
 Name: Nikita Dubinin
 Class: CPCS 121, Fall 2022
 Date: November 10, 2022
 Programming Assignment: PA7
 Description: Pet Store 2
 Notes: -
*/

#include "header.h"

int main() {
    //initiating arrays
    string petName[NUM_PETS];
    PetType petTypes[NUM_PETS];
    int petTypeCounts[NUM_PET_TYPES] = {0 , 0 , 0 , 0 , 0};
    int numDaysAtStore[NUM_PETS];
    bool aboveAverageDaysAtStore[NUM_PETS];
    string aboveAveragePets[NUM_PETS];

    //strings to use later
    string storeName = " ";
    string line = " ";
    string garbage = " ";
    string date = " ";

    //integer variables to use in project
    int numDays = 0;
    int numPets = 0;
    int mostFrequentAnimalTypeIndex = -1;
    double avgDaysAtStore = 0;
    int aboveAvgDaysNum = 0;
    int maxDaysAtStoreIndex = -1;
    int minDaysAtStoreIndex = -1;
    int maxDays = 0;
    int minDays = 99999;

    //filenames
    string inFilename = "petstore.txt";
    string outFilename = "petstats.txt";

    ifstream infile;
    ofstream outfile;

    if (openFile(infile , outfile , inFilename, outFilename)) { //opening files
        cout << "Files opened successfully" << endl << endl;
    }

    fileRead(infile , storeName , garbage, line, petName, numPets, petTypes, numDays, numDaysAtStore); //reading from files
//    getline(infile, storeName);
//    getline(infile, garbage);
//
//    cout << "Reading in pet list from store: " << storeName << "..." << endl << endl;
//
//    while (!infile.eof()) {
//        if (infile.good()) {
//            getline(infile, line); //check if this is a last line
//            if (line.substr(0 , 13) == "Last updated:") {
//                break;
//            }
//
//            petName[numPets] = line;
//
//            getline(infile, line);
//            petTypes[numPets] = getPetTypeCode(line);
//
//            infile >> numDays;
//
//            numDaysAtStore[numPets] = numDays;
//
//            getline(infile , garbage);
//            getline(infile , garbage);
//
//            cout << "Processing " << getPetTypeString(petTypes[numPets]) << " " << petName[numPets] << " ... " << numDaysAtStore[numPets] << " on site." << endl;
//
//            numPets++;
//        }
//    }

//creating summary report
    cout << endl << "Pet store data processed!" << endl << endl;

    cout << "Generating summary report..." << endl << endl;

    setPetTypeCounts(petTypes, petTypeCounts, numPets); //counting each type of pet

    mostFrequentAnimalTypeIndex = findMostFrequentPetType(petTypeCounts, NUM_PET_TYPES); //looking for the most frequent type of animal

    for (int i = 0; i < numPets; i++) {
        avgDaysAtStore += numDaysAtStore[i];
    }
    avgDaysAtStore /= numPets; //counting averege days at store

    setAboveAverageDaysAtStore(numDaysAtStore, numPets, aboveAverageDaysAtStore, avgDaysAtStore); //is animals in array above avg days at store

    aboveAvgDaysNum = findPetsWithAboveAverageStay(petName, aboveAverageDaysAtStore, numPets, aboveAveragePets);//creating a list with names of animal above avg

    writePetSummaryHeader(outfile, storeName, numPets);

    writeAnimalTypeSummary(outfile, petTypeCounts, NUM_PET_TYPES);

    for (int i = 0; i < numPets; i++) {
        if (numDaysAtStore[i] > maxDays) {
            maxDays = numDaysAtStore[i];
            maxDaysAtStoreIndex = i;
        }
        if (numDaysAtStore[i] < minDays) {
            minDays = numDaysAtStore[i];
            minDaysAtStoreIndex = i;
        }
    } // looking for index of animal with max/min days at store

    writePetFrequencyStats(outfile, petName, numDaysAtStore, petTypes, mostFrequentAnimalTypeIndex, minDaysAtStoreIndex, maxDaysAtStoreIndex);

    writePetAveragesStats(outfile, avgDaysAtStore, aboveAveragePets,aboveAvgDaysNum);

    istringstream inSS(line); //parcing for a date
    inSS >> garbage; //useless part for this project
    inSS >> garbage; //useless part for this project
    inSS >> date;

    outfile << "Pet store list was last modified on " << date;

    cout << "Done!" << endl;

    infile.close(); //closing files
    outfile.close();

    return 0;
}
