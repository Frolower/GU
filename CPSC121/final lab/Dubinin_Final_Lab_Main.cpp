/*
 Name: Nikita Dubinin
 Class: CPCS 121, Fall 2022
 Date: December 15, 2022
 Programming Assignment: Final Lab
 Description:
 Notes: -
*/

#include "Dubinin_Final_Lab_Header.h"

/*LEAVE THIS FUNCTION UNMODIFIED*/

//program main
int main()
{
    //package contains
    /*
        int id; // a unique identifier
        double weight; // in lbs
        string dimensions; // LxWxH in inches
    */

    //Parallel Vectors
    vector<int> packageIds;
    vector<double> packageWeights;
    vector<string> packageDimensions;
    //Input and Output stream variables
    ifstream infile;
    ofstream outfile;
    //string variables
    string inputFilename = "truckload.txt";
    string outputFilename = "truckloadstats.txt";
    string driverName = "";
    string storeName = "";
    //stats variables
    int heaviestId = -1;
    double heaviestWeight = 0, avgWeight = 0;
    //menu choice variable
    int userMenuSelection = -1;
    //keeping track of file open status
    bool inputFileIsOpen = false, outputFileIsOpen = false;
    //keeping track of validating data
    bool packageDataAreValid = false, packageStatsAreValid = false;

    //MENU LOOP
    do {
        do {
            cout << "\nPlease choose from the following menu (1-9) to handle truck load processing.\n";
            cout << "1) Open input file for reading\n";
            cout << "2) Open output file for writing\n";
            cout << "3) Read in truck file and process data\n";
            cout << "4) Display the package information to the console\n";
            cout << "5) Compute package statistics for the current truck load\n";
            cout << "6) Display package statistics for the current truck load to the console\n";
            cout << "7) Display the package information AND package statistics to the console\n";
            cout << "8) Write the package information AND package statistics to the output file\n";
            cout << "9) Generate a programming joke\n";
            cout << "10) Quit\n";
            cout << ">> ";
            cin >> userMenuSelection;
            if (userMenuSelection > 10) {
                cls(); //clears the screen
                cout << "Invalid Option\n";
            }
        } while (userMenuSelection < 1 || userMenuSelection > 10);
        cout << "\n";
        cls(); //clears the screen

        /* START HINT BLOCK
        -:HINT:-

                 ██╗  ██╗██╗███╗   ██╗████████╗
              ██╗██║  ██║██║████╗  ██║╚══██╔══╝██╗
        █████╗╚═╝███████║██║██╔██╗ ██║   ██║   ╚═╝█████╗
        ╚════╝██╗██╔══██║██║██║╚██╗██║   ██║   ██╗╚════╝
              ╚═╝██║  ██║██║██║ ╚████║   ██║   ╚═╝
                 ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝

        For each of the following case statements you  should ONLY need
        to write a combinations of

        1) function calls
        2) if-else statements
        3) cout statements

        END HINT BLOCK*/

        switch (static_cast<MenuOptions>(userMenuSelection))
        {
            case OPEN_INPUT_FILE: //Open input file for reading
                inputFileIsOpen = openInputFile(infile, inputFilename);
                displayFileStatus(inputFileIsOpen , inputFilename);
                break;
            case OPEN_OUTPUT_FILE: //Open output file for writing
                outputFileIsOpen = openOutputFile(outfile, outputFilename);
                displayFileStatus(outputFileIsOpen , outputFilename);
                break;
            case READ_TRUCK_DATA: //Read in truck file for processing
                processPackages(infile, packageIds, packageWeights, packageDimensions, driverName, storeName);
                if ( packagesProcessedAreValid(packageIds, packageWeights, packageDimensions)) {
                    cout << "Packages are read valid" << endl;
                } else {
                    cout << "Problems with reading packages" << endl;
                }
                break;
            case DISPLAY_PACKAGE_INFO: //Display the package information in forward order to the console
                displayPackageInformation(packageIds, packageWeights, packageDimensions, driverName, storeName);
                break;
            case COMPUTE_PACKAGE_STATS: //Compute package statistics for the current truck load
                computePackageStats(packageIds, packageWeights, packageDimensions, heaviestId, heaviestWeight, avgWeight);
                if (statsComputedAreValid(heaviestId, heaviestWeight, avgWeight)) {
                    cout << "Stats computed valid" << endl;
                } else {
                    cout << "Problems with computing stats" << endl;
                }
                break;
            case DISPLAY_PACKAGE_STATS: //Display package statistics for the current truck load to the console
                displayPackageStats( heaviestId, heaviestWeight, avgWeight);
                break;
            case DISPLAY_ALL_DATA: //Display the package information in forward order AND statistics about the packages to the console
                displayPackageInformation(packageIds, packageWeights, packageDimensions, driverName, storeName);
                displayPackageStats( heaviestId, heaviestWeight, avgWeight);
                break;
            case WRITE_ALL_DATA: //Write the package information in forward order AND statistics about the packages to an output file
                savePackageSummaryReport( outfile, packageIds, packageWeights, packageDimensions, driverName, storeName, heaviestId, heaviestWeight, avgWeight);
                break;
            case ORDER66://Generate a programming joke
                cout << "Why does Java programmer wear glasses?" << endl << endl;
                cout << "Because he can't see sharp!" << endl << endl;
                cout << "AHAHAHAHAHAHAHAHAHHAHAHAHAHHAHAH" << endl;
                //Does nothing unless you want it to :-)
                //cout << "This starter code...\n Ba dum tsss!";
                //https://www.youtube.com/watch?v=ObpcGNCU944
                //Bonus link:
                //https://www.youtube.com/watch?v=eBGIQ7ZuuiU
                break;
            case EXIT_PGM:
                //Do nothing, we will exit the loop
                break;
            default:
                cout << "Invalid Option\n";
                break;
        }

    } while (userMenuSelection != 10);

    //CLOSE FILES
    infile.close();
    outfile.close();

    return 0;
}

