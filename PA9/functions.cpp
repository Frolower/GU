#include "Dubinin_PA9_header.h"

bool readStudentRecord(ifstream& infile, string& studentId, double& GPA, int& classStanding, double& age) {
    //reading iteration
    infile >> studentId;
    infile >> GPA;
    infile >> classStanding;
    infile >> age;
    if (age > 0 && classStanding > 0) { //validation input
        return true;
    } else {
        return false;
    }
}

int storeDataSets(ifstream& infile, vector <string>& id , vector <int>& year , vector <double>& gpa , vector <double>& age) {
    string studentId = " ";
    double GPA = 0.0;
    int classStanding = 0;
    double ageD = 0.0;

    if (readStudentRecord(infile, studentId, GPA, classStanding, ageD)) {// read successfully
        id.push_back(studentId);
        year.push_back(classStanding);
        gpa.push_back(GPA);
        age.push_back(ageD);
        if (id.size() == year.size() && id.size() == gpa.size() && id.size() == age.size()) {//if same size
            return id.size();
        } else {
            return -1;
        }
    }

}

int calculateSum(vector <int> intVector) {//sum of integers
    int sum = 0;
    for (int i = 0; i < intVector.size(); i++) {
        sum += intVector.at(i);
    }
    return sum;
}

double calculateSum(vector <double> intVector) {//sum of doubles
    double sum = 0;
    for (int i = 0; i < intVector.size(); i++) {
        sum += intVector.at(i);
    }
    return sum;
}

double calculateMean(double sum, int number) {
    if (number != 0) { //check if no deviding by 0
        return sum / number;
    } else {
        return -1.0;
    }
}

int calculateCountAboveMean(double mean, vector<double> GPAs) {
    int aboveMean = 0;
    for (int i = 0; i < GPAs.size(); i++) {
        if (GPAs.at(i) > mean) {//if above mean
            aboveMean++;
        }
    }
    return aboveMean;
}

int calculateCountBelowMean(double mean, vector<double> GPAs) {
    int belowMean = 0;
    for (int i = 0; i < GPAs.size(); i++) {
        if (GPAs.at(i) < mean) {//if below mean
            belowMean++;
        }
    }
    return belowMean;
}

void calculateDeviations(vector <double> numbers, double mean , vector <double>& deviations) {
    for (int i = 0; i < numbers.size(); ++i) {//storing deviations
        deviations.push_back(numbers.at(i) - mean);
    }
}

double calculateVariance(vector <double> deviations) {
    double sum = 0.0;
    for (int i = 0; i < deviations.size(); ++i) {
        sum += abs (deviations.at(i));//calculating variance
    }
    return calculateMean(sum , deviations.size());
}

double calculateStandardDeviation(double variance) {
    return sqrt(variance);//calculating deviation
}

double findMax(vector <double> numbers) {
    double max = -9999999.9;
    int maxIndex = -1;
    for (int i = 0; i < numbers.size(); ++i) {//if number > max
        if (max < numbers.at(i)) {
            max = numbers.at(i);
            maxIndex = i;
        }
    }
    return maxIndex;
}

double findMin(vector <double> numbers) {
    double min = 9999999.9;
    int minIndex = -1;
    for (int i = 0; i < numbers.size(); ++i) {//if < min
        if (min > numbers.at(i)) {
            min = numbers.at(i);
            minIndex = i;
        }
    }
    return minIndex;
}

void printFormattedDouble(ofstream& outfile, double number, int precision) {
    outfile << setprecision(precision) << number << endl;//printing with precision
}