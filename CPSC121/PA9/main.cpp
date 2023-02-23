/* 
 Name: Nikita Dubinin 
 Class: CPCS 121, Fall 2022 
 Date: December 5, 2022
 Programming Assignment: PA9
 Description: gpa calculating
 Notes: -
*/

#include "Dubinin_PA9_header.h"
 
int main() { 
    // filenames
    string inFilename = "../input.dat";
    string outFilename = "../output.dat";

    string newLine = " ";
    vector <string> id;
    vector <int> year;
    vector <double> gpa;
    vector <double> age;
    vector <double> deviations;
    double gpaMean = 0.0;
    double ageMean = 0.0;
    double yearMean = 0.0;
    double gpaSum = 0.0;
    double ageSum = 0.0;
    double standingsSum = 0.0;
    double gpaVariance = 0.0;
    int numStudents = 0;
    int prom = 0;

    ifstream infile;
    ofstream outfile;

    //opening files
    infile.open(inFilename);
    outfile.open(outFilename);

    if (!infile.is_open()) { //check is file opend correctly
        cout << "Unable to open the input file" << endl;
        return -1;
    } else {
        cout << "Input file successfully opened." << endl << endl;
    }

    if (!outfile.is_open()) { //check is file opend correctly
        cout << "Unable to open the output file" << endl;
        return -1;
    } else {
        cout << "Output file successfully opened." << endl << endl;
    }

    //reading from file
    while (!infile.eof()) {
        prom = storeDataSets(infile , id , year , gpa , age);
        if (prom != 32759) {
            numStudents = prom;
        }
    }

//    numStudents = id.size();

    //calling for functions
    gpaSum = calculateSum(gpa);
    
    standingsSum = calculateSum(year); //year is an integer, changing it to double

    //calculating useful variables
    ageSum = calculateSum(age);

    gpaMean = calculateMean(gpaSum , id.size());

    yearMean = calculateMean(standingsSum , year.size());

    calculateDeviations(gpa , gpaMean , deviations);

    ageMean = calculateMean(ageSum, age.size());

    gpaVariance = calculateVariance(deviations);

    //writing to file
    outfile << numStudents << endl << endl;

    printFormattedDouble(outfile , gpaMean , 3);
    outfile << calculateCountAboveMean(gpaMean , gpa) << endl;
    outfile << calculateCountBelowMean(gpaMean , gpa) << endl;
    printFormattedDouble(outfile , yearMean , 3);
    printFormattedDouble(outfile , ageMean , 4);

    outfile << endl;

    printFormattedDouble(outfile , calculateStandardDeviation(gpaVariance) , 2);
    printFormattedDouble(outfile , gpa.at(findMin(gpa)) , 3);
    outfile << id.at(findMin(gpa)) << endl;
    printFormattedDouble(outfile , gpa.at(findMax(gpa)) , 3);
    outfile << id.at(findMax(gpa)) << endl;


    //closing files
    infile.close();
    outfile.close();

    return 0;
}