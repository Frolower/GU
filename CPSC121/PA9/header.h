#ifndef HEADER_H
#define HEADER_H

//including libraries
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>

//namespace
using namespace std;

bool readStudentRecord(ifstream& infile, string& studentId, double& GPA, int& classStanding, double& age);

int storeDataSets(ifstream& infile, vector <string>& id , vector <int>& year , vector <double>& gpa , vector <double>& age);

int calculateSum(vector <int> intVector);

double calculateSum(vector <double> intVector);

double calculateMean(double sum, int number);

int calculateCountAboveMean(double mean, vector<double> GPAs);

int calculateCountBelowMean(double mean, vector<double> GPAs);

void calculateDeviations(vector <double> numbers, double mean , vector <double>& deviations);

double calculateVariance(vector <double> deviations);

double calculateStandardDeviation(double variance);

double findMax(vector <double> numbers);

double findMin(vector <double> numbers);

void printFormattedDouble(ofstream& outfile, double number, int precision);

#endif
