/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: April 5, 2023
 Programming Assignment: PA6
 Description: Music Library
 Notes: -
*/

#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H

#include <iostream>
#include <fstream>
#include "Song.h"

using namespace std;

class SongLibrary {
	private:
		Song * head;
		string sortAttribute; // NEW: keep track of what attribute the library is currently ordered by
	public:
		SongLibrary();
		SongLibrary(const SongLibrary&); // NEW: copy constructor
		~SongLibrary();
		Song * getHead() const; // UPDATED: name
		void setHead(Song *); // UPDATED: name
		string getSortAttribute() const; // NEW: getter for sortAttribute
		void setSortAttribute(string); // NEW: setter for sortAttribute
		
		void performLoad(string);
		void performSave(string);
		void performSort(); // UPDATED: no parameter for sort attribute, using Song's sortAttribute member variable
		Song * performSearch(string, string, bool *, int *); // UPDATED: parameter list and return type
		void performInsertSongInOrder(Song *); // NEW: replaces addSong()
		void performRemoveSong(Song *); // UPDATED: parameter list
		void performEditSong(Song *, string, string); // UPDATED: parameter list

        void clearLibrary();
        void addNewSong();
        void sort();
        void removeSong();
        void search();
        void edit();
        void displayLibrary();
};

bool openFile (string filename, fstream& file);
void clearFile(string filename);
void copyArr (Song arr1[] , Song arr2[] , int size);
void sortByAtt(Song arr[] , string attribute , int size);
bool checkAttribute (string attribute);

#endif
