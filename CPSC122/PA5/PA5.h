/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: March 23, 2023
 Programming Assignment: PA5
 Description: Music Library
 Notes: -
*/

#ifndef PA5_H
#define PA5_H

#include <iostream>
#include <fstream>
#include "Song.h"
#include "SongLibrary.h"

using namespace std;

const int QUIT_OPTION = 9;
const int FIRST_OPTION = 1;
const int LAST_OPTION = QUIT_OPTION;

void displayMenu();
int getValidChoice();
void executeUserChoice(int, SongLibrary& , string filename);
void runMusicManager();
bool openFile (string filename, fstream& file);
void closeFile (fstream& file);

#endif
