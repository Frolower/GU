#include "PA4.h"

/*************************************************************
 * Function: loadPackages()
 * Date Created: 07/03/2023
 * Date Last Modified: 08/03/2023
 * Description: reading info from a file, sorting it into structs, puting them into array
 * Input parameters: ifstream& inFile, string* driverName, int* numPackages
 * Returns: pointer to array of packages
 * Pre: file must be open for reading
 * Post: input information sorted into the structs that located in the array
 **********************************************************/

Package* loadPackages(ifstream& inFile, string* driverName, int* numPackages) {
    string garbage;
    int id, width, length, height;
    double weight;
    Package* packages = nullptr;
    getline(inFile, *driverName);

    getline(inFile, garbage);

    *numPackages = 0;
    while (inFile >> id >> weight >> width >> length >> height) {
        (*numPackages)++;
    }

    packages = new Package[*numPackages];

    inFile.clear();
    inFile.seekg(0, ios::beg);
    getline(inFile, garbage);
    getline(inFile, garbage);

    for (int i = 0; i < *numPackages; i++) {
        inFile >> packages[i].id >> packages[i].weight >> packages[i].width
               >> packages[i].length >> packages[i].height;
    }

    return packages;
}

/*************************************************************
 * Function: computePackageStats()
 * Date Created: 07/03/2023
 * Date Last Modified: 08/03/2023
 * Description: finding heaviest weight, heaviest weight id, avg weight
 * Input parameters: const Package packages[], const int numPackages, int * heaviestId, double * heaviestWeight, double * avgWeight
 * Returns: void
 * Pre: loadPackages() done
 * Post: avg weight , max weight, max weight id found
 **********************************************************/

void computePackageStats(const Package packages[], const int numPackages, int * heaviestId, double * heaviestWeight, double * avgWeight) {
    *avgWeight = 0;
    if (numPackages > 0) {
        for (int i = 0; i < numPackages; i++) {
            if (packages[i].weight > *heaviestWeight) {
                *heaviestWeight = packages[i].weight;
                *heaviestId = packages[i].id;
                *avgWeight += packages[i].weight;
            } else {
                *avgWeight += packages[i].weight;
            }
        }
        *avgWeight /= numPackages;
    }
}

/*************************************************************
 * Function: displayStats()
 * Date Created: 07/03/2023
 * Date Last Modified: 08/03/2023
 * Description: displaying packages and stats
 * Input parameters: const Package arr[] ,  int * numPackages ,  int * heaviestId ,  double * heaviestWeight ,  double * avgWeight ,  string * driverName
 * Returns: void
 * Pre: computePackageStats() done
 * Post: stats displayed in the console
 **********************************************************/

void displayStats (const Package arr[] ,  int * numPackages ,  int * heaviestId ,  double * heaviestWeight ,  double * avgWeight ,  string * driverName) {
    cout << "Number of packages on " << *driverName << "'s truck: " << *numPackages << endl << endl;

    cout << "Package information" << endl;
    cout << "___________________" << endl << endl;

    for (int i = 0; i < *numPackages; i++) {
        cout << "Package ID: " << arr[i].id << endl;
        cout << "Package Weight: " << arr[i].weight << endl;
        cout << "Package Width: " << arr[i].width << endl;
        cout << "Package Length: " << arr[i].length << endl;
        cout << "Package Height: " << arr[i].height << endl;
        cout << endl;
    }

    cout << "Package Stats" << endl;
    cout << "_____________" << endl << endl;

    cout << "ID of heaviest package: " << *heaviestId << endl;
    cout << "Weight of heaviest package: " << *heaviestWeight << endl;
    cout << "Average weight of packages on truck: " << *avgWeight << endl;

}