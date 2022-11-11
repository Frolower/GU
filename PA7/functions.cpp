#include "header.h"

string getPetTypeString(PetType petType) { //receives pet type as an enum and gives it back as a string
    switch(petType) {
        case BIRD:
            return "bird";
            break;
        case CAT:
            return "cat";
            break;
        case DOG:
            return "dog";
            break;
        case FISH:
            return "fish";
            break;
        default:
            return "other";
            break;
    }
}

PetType getPetTypeCode(string petTypeString) { //receives pet type as a string and gives it back as an enum
    if (petTypeString == "bird") {
        return BIRD;
    } else if (petTypeString == "cat") {
        return CAT;
    } else if (petTypeString == "dog") {
        return DOG;
    } else if (petTypeString == "fish") {
        return FISH;
    } else {
        return OTHER;
    }
}


void setPetTypeCounts(const PetType petTypes[], int petTypeCounts[], int numPets) { //counting each type of animal
    for (int i = 0; i < numPets; i++) {
        switch (petTypes[i]) {
            case BIRD:
                petTypeCounts[0]++;
                break;
            case CAT:
                petTypeCounts[1]++;
                break;
            case DOG:
                petTypeCounts[2]++;
                break;
            case FISH:
                petTypeCounts[3]++;
                break;
            default:
                petTypeCounts[4]++;
                break;
        }
    }
}

int findMostFrequentPetType(const int petTypeCounts[], int numPetTypes) { //looking for the most frequent type of animal
    int maxPetsIndex = -1;
    int numPetsMax = 0;
    int i = 0;
    for (i = 0; i < numPetTypes; i++) {
        if (petTypeCounts[i] > numPetsMax) {
            numPetsMax = petTypeCounts[i];
            maxPetsIndex = i;
        }
    }
    return maxPetsIndex;
}

void setAboveAverageDaysAtStore(const int daysAtStore[], int numPets, bool aboveAverageDaysAtStore[], int averageDays) { //look in main
    int i = 0;

    for (i = 0; i < numPets; i++) {
        if (daysAtStore[i] > averageDays) {
            aboveAverageDaysAtStore[i] = true;
        } else {
            aboveAverageDaysAtStore[i] = false;
        }
    }
}


int findPetsWithAboveAverageStay(const string petNames[], const bool aboveAverageDaysAtStore[], int numPets, string aboveAveragePets[]) { //look in main
    int j = 0;
    for (int i = 0; i < numPets; i++) {
        if (aboveAverageDaysAtStore[i]) {
            aboveAveragePets[j] = petNames[i];
            j++;
        }
    }
    return j;
}

void writePetSummaryHeader(ofstream& outfile, string petStoreName, int numPets) { //writes header
    outfile << "Store: " << petStoreName << endl;
    outfile << "Number of pets: " << numPets << endl << endl;
    outfile << "Pet Information Summary Statistics:" << endl;
    outfile << setfill('_') << setw(35) << "" << endl;
}

void writeAnimalTypeSummary(ofstream& outfile, const int petTypeCounts[], int numPetTypes) { // writes summary
    int i = 0;

    outfile   << setfill(' ');

    outfile << "Count of each animal: " << endl;

    for(i = 0; i < numPetTypes; i++) {
        if (i == numPetTypes - 1) { //if last element it shouldn't have , after it, also endes with a new line
            outfile << "        " << left << setw(5) << toCapitalCase(getPetTypeString(static_cast<PetType>(i))) << " - " << petTypeCounts[i] << endl;
        } else {
            if (i % 2 != 0) { //2 element in line, should end with a new line
                outfile << left << setw(5) << toCapitalCase(getPetTypeString(static_cast<PetType>(i))) << " - " << petTypeCounts[i] << "," << endl;
            } else {
                outfile << "        " << left << setw(5) << toCapitalCase(getPetTypeString(static_cast<PetType>(i)))
                        << " - " << petTypeCounts[i] << ", ";
            }
        }
    }
    outfile << endl;
}

void writePetFrequencyStats(ofstream& outfile, const string petNames[], const int daysAtStore[], const PetType petTypes[], int mostFrequentAnimalTypeIndex, int numDaysAtStoreMinIndex, int numDaysAtStoreMaxIndex) {// writing a pet frequency stat
    outfile << "Most frequent animal type: " << toCapitalCase(getPetTypeString(static_cast<PetType>(mostFrequentAnimalTypeIndex))) << endl << endl;
    outfile << "Most days on site: " << endl;
    outfile << "    Name: " << petNames[numDaysAtStoreMaxIndex] << endl;
    outfile << "    Days: " << daysAtStore[numDaysAtStoreMaxIndex] << endl;
    outfile << "    Type: " << toCapitalCase(getPetTypeString(petTypes[numDaysAtStoreMaxIndex])) << endl << endl;

    outfile << "Fewest days on site: " << endl;
    outfile << "    Name: " << petNames[numDaysAtStoreMinIndex] << endl;
    outfile << "    Days: " << daysAtStore[numDaysAtStoreMinIndex] << endl;
    outfile << "    Type: " << toCapitalCase(getPetTypeString(petTypes[numDaysAtStoreMinIndex])) << endl << endl;
}

void writePetAveragesStats(ofstream& outfile, double averageDays, const string aboveAveragePets[], int numPetsAboveAverageStay) {//writing pets stas

    outfile << "Average days on site: " << round(averageDays) << endl << endl;
    outfile << "Pets on site longer than average days on site:" << endl;

    for (int i = 0; i < numPetsAboveAverageStay; i++) {
        outfile << "    " << aboveAveragePets[i] << endl;
    }

    outfile << endl;
}

string toCapitalCase(string inputString) {//making 1st letter be capital
    inputString[0] = toupper(inputString[0]);

    return inputString;
}

bool openFile(ifstream& infile, ofstream& outfile, string inFilename , string outFilename) {//opening files and return a bool value

    infile.open(inFilename);
    outfile.open(outFilename);

    if (!infile.is_open()) {
        cout << "Problem with opening input file." << endl;
        return false;
    }
    if (!outfile.is_open()) {
        cout << "Problem with opening output file." << endl;
        return false;
    }

    return true;
}

void fileRead(ifstream& infile , string& storeName , string& garbage, string& line, string petName[], int& numPets, PetType petTypes[], int& numDays, int numDaysAtStore[]) {//reading info from a file
    getline(infile, storeName);
    getline(infile, garbage);

    cout << "Reading in pet list from store: " << storeName << "..." << endl << endl;

    while (!infile.eof()) {
        if (infile.good()) {
            getline(infile, line); //check if this is a last line
            if (line.substr(0 , 13) == "Last updated:") {
                break;
            }

            petName[numPets] = line;

            getline(infile, line);
            petTypes[numPets] = getPetTypeCode(line);

            infile >> numDays;

            numDaysAtStore[numPets] = numDays;

            getline(infile , garbage);
            getline(infile , garbage);

            cout << "Processing " << getPetTypeString(petTypes[numPets]) << " " << petName[numPets] << " ... " << numDaysAtStore[numPets] << " on site." << endl;

            numPets++;
        }
    }
}