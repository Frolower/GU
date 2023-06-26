/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: April 5, 2023
 Programming Assignment: PA6
 Description: Music Library
 Notes: -
*/

#include "PA6.h"

/*************************************************************
 * Function: displayMenu()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: displaying menu
 * Input parameters: -
 * Returns: -
 * Pre: -
 * Post: menu displayed
 **********************************************************/
void displayMenu() {
	cout << endl << "Welcome to the CPSC 122 Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1) Load library" << endl;
	cout << "2) Store library" << endl;
	cout << "3) Display library" << endl;
	cout << "4) Sort library" << endl;
	cout << "5) Search library" << endl;
	cout << "6) Insert song in order" << endl;
	cout << "7) Remove song" << endl;
	cout << "8) Edit song" << endl;
	cout << "9) Exit" << endl;
}

/*************************************************************
 * Function: displayMenu()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: getting and validating choice
 * Input parameters: -
 * Returns: int choice
 * Pre: -
 * Post: choice validated
 **********************************************************/
int getValidChoice() {
	int choice = -1;
	string temp;
	do {
		cout << "Choice: ";
		cin >> choice;
		if (choice < FIRST_OPTION || choice > LAST_OPTION) {
			cout << "That is not a valid option. Please try again." << endl;
		}
	} while (choice < FIRST_OPTION || choice > LAST_OPTION);
	getline(cin, temp); // flush the newline outta the buffer
	return choice;
}

/*************************************************************
 * Function: executeUserChoice()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: calling other functions that match choice
 * Input parameters: int choice, SongLibrary& lib , string filename
 * Returns: -
 * Pre: choice must be valid
 * Post: next actions performed
 **********************************************************/
void executeUserChoice(int choice, SongLibrary& lib) {
    string filename = "../library.txt";

	switch (choice) {
		case 1:
            lib.performLoad(filename);
			break;
		case 2:
			lib.performSave(filename);
			break;
		case 3:
            lib.displayLibrary();
			break;
		case 4:
            lib.sort();
			break;
		case 5:
            lib.search();
			break;
		case 6:
            lib.addNewSong();
			break;
		case 7:
            lib.removeSong();
			break;
		case 8:
            lib.edit();
			break;
		default:
			cout << "Unrecognized menu choice" << endl;
			break;
	}
}

/*************************************************************
 * Function: runMusicManager()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: runs manager
 * Input parameters: -
 * Returns: -
 * Pre: -
 * Post: -
 **********************************************************/
void runMusicManager() {
	SongLibrary lib;
	
	int choice = -1;
	do {
		displayMenu();
		choice = getValidChoice();
		if (choice != QUIT_OPTION) {
			executeUserChoice(choice, lib);
		}
	} while (choice != QUIT_OPTION);
	cout << "Thanks for you using the CPSC 122 Music Manager!!" << endl;
}
