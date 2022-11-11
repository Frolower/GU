/* 
 Name: Nikita Dubinin 
 Class: CPCS 121, Fall 2022 
 Date: September 14, 2022 
 Programming Assignment: PA1                                                                       
 Description: Calculation cost of the trip
 Notes: -
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

//functions prototypes

double readDouble(ifstream& infile);
 
int readInteger(ifstream& infile);
 
double calculateSum(double number1, double number2, double number3, double number4, double number5);
  
double calculateMean(double sum, int number);
 
double calculateDeviation(double number, double mean);
 
double calculateVariance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
 
double calculateStandardDeviation(double variance);
 
double findMax(double number1, double number2, double number3, double number4, double number5);
 
double findMin(double number1, double number2, double number3, double number4, double number5);

void printDouble(ofstream& outfile, double number);
 
int main() { 
    // filenames
    string inFilename = "input.dat";
    string outFilename = "output.dat";

    //variables for 5 iterations
    string newLine = " ";
    int studentId = 0;
    int year1 = 0;
    int year2 = 0;
    int year3 = 0;
    int year4 = 0;
    int year5 = 0;
    double gpa1 = 0.0;
    double gpa2 = 0.0;
    double gpa3 = 0.0;
    double gpa4 = 0.0;
    double gpa5 = 0.0;
    double age1 = 0.0;
    double age2 = 0.0;
    double age3 = 0.0;
    double age4 = 0.0;
    double age5 = 0.0;
    double gpaMean = 0.0;
    double ageMean = 0.0;
    double gpaSum = 0.0;
    double ageSum = 0.0;
    double standingsSum = 0.0;
    double gpaVariance = 0.0;
    double gpaDeviationSum = 0.0;

    ifstream infile;
    ofstream outfile;

    infile.open(inFilename);
    outfile.open(outFilename);

    if (!infile.is_open()) { //check is file opend correctly
        cout << "Unable to open the input file" << endl;
        return -1;
    } else {
        cout << "Output file successfully opened." << endl << endl;
    }

    if (!outfile.is_open()) { //check is file opend correctly
        cout << "Unable to open the output file" << endl;
        return -1;
    } else {
        cout << "Output file successfully opened." << endl << endl;
    }

    //1st iteration
    studentId = readInteger(infile);
    gpa1 = readDouble(infile);
    year1 = readInteger(infile);
    age1 = readDouble(infile);
    infile >> newLine;

    //2nd iteration
    studentId = readInteger(infile);
    gpa2 = readDouble(infile);
    year2 = readInteger(infile);
    age2 = readDouble(infile);
    infile >> newLine;

    //3rd iteration
    studentId = readInteger(infile);
    gpa3 = readDouble(infile);
    year3 = readInteger(infile);
    age3 = readDouble(infile);
    infile >> newLine;

    //4th iteration
    studentId = readInteger(infile);
    gpa4 = readDouble(infile);
    year4 = readInteger(infile);
    age4 = readDouble(infile);
    infile >> newLine;

    //5th iteration
    studentId = readInteger(infile);
    gpa5 = readDouble(infile);
    year5 = readInteger(infile);
    age5 = readDouble(infile);
    infile >> newLine;

    //calling for functions
    gpaSum = calculateSum(gpa1 , gpa2 , gpa3 , gpa4 , gpa5);
    
    standingsSum = calculateSum((double) year1 , (double) year2 , (double) year3 , (double) year4 , (double) year5); //year is an integer, changing it to double

    ageSum = calculateSum(age1 , age2 , age3 , age4 , age5);

    gpaMean = calculateMean(gpaSum , 5);
    
    printDouble(outfile , gpaMean);

    printDouble(outfile , calculateMean(standingsSum , 5));

    ageMean = calculateMean(ageSum, 5);

    printDouble(outfile , ageMean);

    gpaVariance = calculateVariance( calculateDeviation(gpa1 , gpaMean) , calculateDeviation(gpa2 , gpaMean) , calculateDeviation(gpa3 , gpaMean) , calculateDeviation(gpa4 , gpaMean) , calculateDeviation(gpa5 , gpaMean) , 5);

    printDouble(outfile , calculateStandardDeviation(gpaVariance));


    printDouble(outfile , findMin(gpa1 , gpa2 , gpa3 , gpa4 , gpa5));

    printDouble(outfile , findMax(gpa1 , gpa2 , gpa3 , gpa4 , gpa5));

    //closing files
    infile.close();
    outfile.close();

    return 0;
}

double readDouble(ifstream& infile) {
    double num;
    infile >> num;
    return num;
}
 
int readInteger(ifstream& infile) {
    int num;
    infile >> num;
    return num;
}
 
double calculateSum(double number1, double number2, double number3, double number4, double number5) {
    return  number1 + number2 + number3 + number4 + number5;
}
  
double calculateMean(double sum, int number) {
    if (number != 0) { //check if no deviding by 0
        return sum / number;
    } else {
        return -1.0;
    }
}
 
double calculateDeviation(double number, double mean) {
    return number - mean;
}
 
double calculateVariance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number) {
    double sum = pow(deviation1 , 2.0) + pow(deviation2 , 2.0) + pow(deviation3 , 2.0) + pow(deviation4 , 2.0) + pow(deviation5 , 2.0);
    return calculateMean(sum , number);
}
 
double calculateStandardDeviation(double variance) {
     return sqrt(variance); 
}
 
double findMax(double number1, double number2, double number3, double number4, double number5) {
    double max = -9999999.9;
    if (number1 > max) {
        max = number1;
    }
    if (number2 > max) {
        max = number2;
    }
    if (number3 > max) {
        max = number3;
    }
    if (number4 > max) {
        max = number4;
    }
    if (number5 > max) {
        max = number5;
    }
    return max;
}
 
double findMin(double number1, double number2, double number3, double number4, double number5) {
    double min = 9999999.9;
    if (number1 < min) {
        min = number1;
    }
    if (number2 < min) {
        min = number2;
    }
    if (number3 < min) {
        min = number3;
    }
    if (number4 < min) {
        min = number4;
    }
    if (number5 < min) {
        min = number5;
    }
    return min;
}

void printDouble(ofstream& outfile, double number) {
    outfile << fixed << setprecision(2) << number << endl; //using setprecision to output only 2 last numbers after .
}