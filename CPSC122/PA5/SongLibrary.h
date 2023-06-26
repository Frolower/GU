/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: March 23, 2023
 Programming Assignment: PA5
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
		int numSongs;
		Song * songs;
		
		// TODO: add your additional private member functions here
	public:
		SongLibrary();
		~SongLibrary();
		int getNumSongs();
		void setNumSongs(int);
		Song * getSongsArray();
		void setSongsArray(Song *);

		void displayLibrary();
		void performLoad(string);
		void performSave(string);
		void performSort(string);
		bool performSearch(string, string, Song *, int *);
		void performAddSong(Song);
		void performRemoveSong(int);
		void performEditSong(int, string, string);
        Song * createNewArr();

		// TODO: add your additional public member functions here
        void readFromFile (string filename);
        void createNewSong();
        void editSongInLibrary();
        void sortLibrary();
        void removeSong();
        void search();
        void edit();
};

void closeFile (fstream& file);
bool openFile (string filename, fstream& file);
void clearFile(string filename);
void copyArr (Song arr1[] , Song arr2[] , int size);
void sortByAtt(Song arr[] , string attribute , int size);
bool checkAttribute (string attribute);

#endif
