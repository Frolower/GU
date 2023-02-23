#ifndef HEADER_H
#define HEADER_H

//including useful libraries
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>


//namespace
using namespace std;


//constant variables
const int NUM_PETS = 100;
const int NUM_PET_TYPES = 5;

//my enum
enum PetType { BIRD, CAT, DOG, FISH, OTHER};

string getPetTypeString(PetType petType);

PetType getPetTypeCode(string petTypeString);

void setPetTypeCounts(const PetType petTypes[], int petTypeCounts[], int numPets);

int findMostFrequentPetType(const int petTypeCounts[], int numPetTypes);

void setAboveAverageDaysAtStore(const int daysAtStore[], int numPets, bool aboveAverageDaysAtStore[], int averageDays);

int findPetsWithAboveAverageStay(const string petNames[], const bool aboveAverageDaysAtStore[], int numPets, string aboveAveragePets[]);

void writePetSummaryHeader(ofstream& outfile, string petStoreName, int numPets);

void writeAnimalTypeSummary(ofstream& outfile, const int petTypeCounts[], int numPetTypes);

void writePetFrequencyStats(ofstream& outfile, const string petNames[], const int daysAtStore[], const PetType petTypes[], int mostFrequentAnimalTypeIndex, int numDaysAtStoreMinIndex, int numDaysAtStoreMaxIndex);

void writePetAveragesStats(ofstream& outfile, double averageDays, const string aboveAveragePets[], int numPetsAboveAverageStay);

string toCapitalCase(string inputString);

bool openFile(ifstream& infile, ofstream& outfile, string inFilename , string outFilename);

void fileRead(ifstream& infile , string& storeName , string& garbage, string& line, string petName[], int& numPets, PetType petTypes[], int& numDays, int numDaysAtStore[]);

#endif
