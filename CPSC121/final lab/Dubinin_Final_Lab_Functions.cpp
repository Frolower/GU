#include "Dubinin_Final_Lab_Header.h"

/*************************************************************
 * Function: openInputFile(ifstream& infile, const string filename)
 * Description: Topening input file
 *************************************************************/

bool openInputFile(ifstream& infile, const string filename) {
    infile.open(filename);

    if (!infile.is_open()) {
        return false;
    }

    return true;
}

/*************************************************************
 * Function: openOutputFile(ofstream& outfile, const string filename)
 * Description: opening output file
 *************************************************************/

bool openOutputFile(ofstream& outfile, const string filename) {
    outfile.open(filename);

    if (!outfile.is_open()) {
        return false;
    }

    return true;
}

/*************************************************************
 * Function: displayFileStatus(bool fileStatus, const string filename)
 * Description: displaying file status
 *************************************************************/

void displayFileStatus(bool fileStatus, const string filename) {
    if (fileStatus) {
        cout << filename << " was opened successfully" << endl;
    } else {
        cout << "Problems with opening " << filename << endl;
    }
}

/*************************************************************
 * Function: processPackages(ifstream& infile, vector<int>& packageIds, vector<double>& packageWeights, vector<string>& packageDimensions, string& driverName, string& storeName)
 * Description: reading and storeing information
 *************************************************************/

void processPackages(ifstream& infile, vector<int>& packageIds, vector<double>& packageWeights, vector<string>& packageDimensions, string& driverName, string& storeName) {
    string line = " ";
    string garbage = " ";
    double inputDouble = 0.0;
    int inputInt = 0;

    getline(infile , driverName);
    getline(infile , storeName);


    while (!infile.eof()) {
        if (infile.good()) {
//            infile >> garbage;
            infile >> line; //check if this is a last line
            if (line.substr(0 , 7) == "Packing") {
                break;
            } else {

                packageIds.push_back(atoi( line.c_str() ));

                infile >> inputDouble;
                packageWeights.push_back(inputDouble);

                infile >> line;
                packageDimensions.push_back(line);
            }
        }
    }

}

/*************************************************************
 * Function: packagesProcessedAreValid(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions)
 * Description: check if everything is okay
 *************************************************************/

bool packagesProcessedAreValid(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions) {
    if (packageIds.size() == packageWeights.size() && packageIds.size() == packageDimensions.size() && packageIds.size() > 0) {
        return true;
    } else {
        return false;
    }
}

/*************************************************************
 * Function: displayPackageInformation(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName, const string storeName)
 * Description: displaying basic information
 *************************************************************/

void displayPackageInformation(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName, const string storeName) {
    cout << "Driver: " << driverName << endl;
    cout << "Store: " << storeName << endl;
    cout << "Number of packages: " << packageIds.size() << endl;
    cout << "Package Information" << endl;
    cout << "___________________" << endl;
    cout << fixed << showpoint << setprecision(2);

    for (int i = 0; i < packageIds.size(); i++) {
        cout << "Package Id: " << packageIds.at(i) << endl;
        cout << "Package Weight: " << packageWeights.at(i) << endl;
        cout << "Package Dimensions: " << packageDimensions.at(i) << endl;
        cout << endl;
    }


}

/*************************************************************
 * Function: computePackageStats(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, int& heaviestId, double& heaviestWeight, double& avgWeight)
 * Description: computing stats
 *************************************************************/

void computePackageStats(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, int& heaviestId, double& heaviestWeight, double& avgWeight) {
    for (int i = 0; i < packageIds.size(); i++) {
        avgWeight += packageWeights.at(i);
    }
    avgWeight /= packageWeights.size();
    for (int i = 0; i < packageIds.size(); i++) {
        if (packageWeights.at(i) > heaviestWeight) {
            heaviestWeight = packageWeights.at(i);
            heaviestId = packageIds.at(i);
        }
    }
}

/*************************************************************
 * Function: statsComputedAreValid(int heaviestId, double heaviestWeight, double avgWeight)
 * Description: check if everything is okay
 *************************************************************/

bool statsComputedAreValid(int heaviestId, double heaviestWeight, double avgWeight) {
    if (heaviestId >= 0 && heaviestWeight > 0.0 && avgWeight > 0.0) {
        return true;
    } else {
        return false;
    }
}

/*************************************************************
 * Function: displayPackageStats(int heaviestId, double heaviestWeight, double avgWeight)
 * Description: displaying stats
 *************************************************************/

void displayPackageStats(int heaviestId, double heaviestWeight, double avgWeight) {
    cout << "Package Stats" << endl;
    cout << "_____________" << endl;
    cout << "ID of heaviest package: " << heaviestId << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "Weight of heaviest package: " << heaviestWeight << endl;
    cout << "Average weight of packages on truck: " << avgWeight << endl;
}

/*************************************************************
 * Function: cls()savePackageSummaryReport(ofstream& outfile, vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName, const string storeName, int heaviestId, double heaviestWeight, double avgWeight)
 * Description: writing to the file
 *************************************************************/

void savePackageSummaryReport(ofstream& outfile, vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName, const string storeName, int heaviestId, double heaviestWeight, double avgWeight) {
    outfile << "Driver: " << driverName << endl;
    outfile << "Store: " << storeName << endl;
    outfile << "Number of packages: " << packageIds.size();
    outfile << "Package Information" << endl;
    outfile << "___________________" << endl;
    outfile << fixed << showpoint << setprecision(2);

    for (int i = 0; i < packageIds.size(); i++) {
        outfile << "Package Id: " << packageIds.at(i) << endl;
        outfile << "Package Weight: " << packageWeights.at(i) << endl;
        outfile << "Package Dimensions: " << packageDimensions.at(i) << endl;
        outfile << endl;
    }

    outfile << "Package Stats" << endl;
    outfile << "_____________" << endl;
    outfile << "ID of heaviest package: " << heaviestId << endl;
    outfile << "Weight of heaviest package: " << heaviestWeight << endl;
    outfile << "Average weight of packages on truck: " << avgWeight << endl;
}

/*************************************************************
 * Function: cls()
 * Description: This function should clear the console screen
 * for both Windows and Linux command prompt / terminal windows
 *************************************************************/

void cls(void) {
    system("cls||clear");
    return;
}