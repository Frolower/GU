/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: April 5, 2023
 Programming Assignment: PA6
 Description: Music Library
 Notes: -
*/

#ifndef PA6_H
#define PA6_H

#include <iostream>
#include <fstream>
#include "Song.h"
#include "SongLibrary.h"

using namespace std;

const int QUIT_OPTION = 9;
const int FIRST_OPTION = 1;
const int LAST_OPTION = 9;

void displayMenu();
int getValidChoice();
void executeUserChoice(int, SongLibrary&);
void runMusicManager();

#endif
