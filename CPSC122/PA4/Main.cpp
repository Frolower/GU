#include "PA4.h"


int main(int argc , char *argv[]) {
    if (argc == 2) {
        string driverName;
        string filename = " ";
        Package * arr;
        int numPackages = 0;
        double avgWeight = 0.0;
        int heaviestId = 0;
        double heaviestWeight = 0.0;

        ifstream  infile;

        filename = argv[1];

        infile.open(filename);

        if (!infile.is_open()) {
            cout << "Can't open the file" << endl;
            return -1;
        }

        arr = loadPackages(infile , &driverName, &numPackages);

        computePackageStats(arr, numPackages, &heaviestId, &heaviestWeight, &avgWeight);

        displayStats (arr , &numPackages , &heaviestId , &heaviestWeight , &avgWeight , &driverName);

        delete [] arr;
        arr = NULL;
    } else {
        cout << "incorrect number of arguments" << endl;
    }

	return 0;
}
