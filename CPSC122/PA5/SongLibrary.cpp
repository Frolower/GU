/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: March 23, 2023
 Programming Assignment: PA5
 Description: Music Library
 Notes: -
*/

#include "SongLibrary.h"

/*************************************************************
 * Function: SongLibrary class dvc
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: creating SongLibrary class object with default values
 * Input parameters: -
 * Returns: SongLibrary class object
 * Pre:
 * Post: SongLibrary class object created
 **********************************************************/
SongLibrary::SongLibrary() {
	numSongs = 0;
	songs = NULL;
}

/*************************************************************
 * Function: Song class destructor
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: destructing SongLibrary class
 * Input parameters: -
 * Returns: -
 * Pre: -
 * Post: SongLibrary class destroyed
 **********************************************************/
SongLibrary::~SongLibrary() {
    delete [] songs;
    songs = NULL;
    numSongs = 0;
}

/*************************************************************
 * Function: getNumSongs()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: returning numsSongs
 * Input parameters: -
 * Returns: int numSongs
 * Pre: object must exist
 * Post: numSongs returned
 **********************************************************/
int SongLibrary::getNumSongs() {
	return numSongs;
}

/*************************************************************
 * Function: setNumSongs()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: updating numSongs
 * Input parameters: int newNumSongs
 * Returns: -
 * Pre: object must exist
 * Post: numSongs updated
 **********************************************************/
void SongLibrary::setNumSongs(int newNumSongs) {
	numSongs = newNumSongs;
}

/*************************************************************
 * Function: getSongsArray()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: returning songs arr pointer
 * Input parameters: -
 * Returns: Song * songs
 * Pre: object must exist
 * Post: songs returned
 **********************************************************/
Song * SongLibrary::getSongsArray() {
	return songs;
}

/*************************************************************
 * Function: setSongsArr()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: frees songs arr memory and assigning newSongArr to it
 * Input parameters: Song * newSongArr
 * Returns: -
 * Pre: object must exist
 * Post: songs updated
 **********************************************************/
void SongLibrary::setSongsArray(Song * newSongsArr) {
    if (songs != NULL) {
        delete [] songs;
    }
    songs = newSongsArr;
}

/*************************************************************
 * Function: displayLibrary()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: displaying songs from library
 * Input parameters: -
 * Returns: -
 * Pre: object must exist
 * Post: library displayed
 **********************************************************/
void SongLibrary::displayLibrary() {
    if (numSongs > 0) {
        for (int i = 0; i < numSongs; i++) {
            (songs + i)->displaySong();
        }
    } else {
        cout << "You don't have any songs in your library" << endl;
    }
}

/*************************************************************
 * Function: performLoad()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: calling function to load info from file
 * Input parameters: string filename
 * Returns: -
 * Pre: object must exist
 * Post: information from file stored
 **********************************************************/
void SongLibrary::performLoad(string filename) {
    readFromFile(filename);
}

/*************************************************************
 * Function: performSave()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: saving library to file
 * Input parameters: string filename
 * Returns: -
 * Pre: object must exist
 * Post: info stored into file
 **********************************************************/
void SongLibrary::performSave(string filename) {
    clearFile(filename);
    fstream file;
    if (openFile(filename , file)) {
        for (int i = 0; i < numSongs; i++) {
            file << (songs + i)->getTitle() << endl;
            file << (songs + i)->getArtist() << endl;
            file << (songs + i)->getGenre() << endl;
            file << (songs + i)->getRating() << endl;
            file << endl;
        }
    }
}

/*************************************************************
 * Function: sortLibrary()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: calling functions that sorts library
 * Input parameters: -
 * Returns:
 * Pre: object must exist
 * Post: library sorted
 **********************************************************/
void SongLibrary::sortLibrary() {
    if (numSongs > 0) {
        string attribute = "";
        cout << "What attribute you want use to sort?" << endl;
        cout << "You can choose between title, artist, genre, and rating" << endl;
        getline(cin, attribute);
        if (checkAttribute(attribute)) {
            SongLibrary::performSort(attribute);
        }
    } else {
        cout << "You don't have songs to sort" << endl;
    }
}

/*************************************************************
 * Function: performSort()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: sorting list
 * Input parameters: string attribute
 * Returns:
 * Pre: object must exist
 * Post:list sorted
 **********************************************************/
void SongLibrary::performSort(string attribute) {
	if (attribute == "title") {
        sortByAtt(songs , attribute , numSongs);
    } else if (attribute == "artist") {
        sortByAtt(songs , attribute , numSongs);
    } else if (attribute == "genre") {
        sortByAtt(songs , attribute , numSongs);
    } else if (attribute == "rating") {
        sortByAtt(songs , attribute , numSongs);
    } else {
        cout << "Unknown attribute" << endl;
    }
}

/*************************************************************
 * Function: search()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: calling functions to search for an element
 * Input parameters: -
 * Returns: -
 * Pre: object must exist
 * Post: object must be found
 **********************************************************/
void SongLibrary::search() {
    if (numSongs > 0) {
        string searchAttribute = "";
        string searchAttributeValue = "";
        Song foundSong;
        int index = -1;

        cout << "What attribute you want use for search?" << endl;
        getline(cin, searchAttribute);
        if (checkAttribute(searchAttribute)) {
            cout << "What are we looking for?" << endl;
            getline(cin, searchAttributeValue);

            if (SongLibrary::performSearch(searchAttribute, searchAttributeValue, &foundSong, &index)) {
                cout << "Song " << foundSong.getTitle() << " by " << foundSong.getArtist();
                cout << " was found. It's genre is " << foundSong.getGenre() << " and rating is "
                     << foundSong.getRating();
                cout << " out of 5. It's number " << index + 1 << " in your playlist." << endl;
            } else {
                cout << "Сan't find a song according to the specified conditions" << endl;
            }
        }
    } else {
        cout << "You don't have any songs in your playlist" << endl;
    }
}

/*************************************************************
 * Function: performSearch()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: searching for song
 * Input parameters: string searchAttribute, string searchAttributeValue, Song * foundSong, int * index
 * Returns: bool
 * Pre: object must exist
 * Post: song must be found
 **********************************************************/
bool SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, Song * foundSong, int * index) {
	for (int i = 0; i < numSongs; i++) {
        if ((songs + i)->getStringAttributeValue(searchAttribute) == searchAttributeValue) {
            *index = i;
            *foundSong = *(songs + i);
            return true;
        }
    }
    foundSong = nullptr;
    *index = -1;
	return false;
}

/*************************************************************
 * Function: performAddSong()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: adding new song to the library
 * Input parameters: Song new song
 * Returns: -
 * Pre: object must exist
 * Post: new song added
 **********************************************************/
void SongLibrary::performAddSong(Song newSong) {
    Song *newSongs = new Song[numSongs + 1];
    for (int i = 0; i < numSongs; i++) {
        newSongs[i] = songs[i];
    }
    newSongs[numSongs] = newSong;
    numSongs++;
    delete[] songs;
    songs = newSongs;
}

/*************************************************************
 * Function: removeSong()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: calls functions to remove song
 * Input parameters: -
 * Returns: -
 * Pre: object must exist
 * Post: song removed
 **********************************************************/
void SongLibrary::removeSong() {
    if (numSongs > 1) {
        int index = -1;
        cout << "Enter index of song that you want to remove (index starts at 0)" << endl;
        cin >> index;
        if (index < numSongs) {
            SongLibrary::performRemoveSong(index);
        } else {
            cout << "Index is out of range, maximum index for you is " << numSongs - 1 << endl;
        }
    } else {
        cout << "Your playlist is empty" << endl;
    }
}

/*************************************************************
 * Function: performRemoveSong()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: removing song
 * Input parameters: int index
 * Returns: -
 * Pre: object must exist
 * Post: song removed
 **********************************************************/
void SongLibrary::performRemoveSong(int index) {
    if (numSongs == 1) {
        delete[] songs;
        songs = NULL;
        numSongs = 0;
    } else if (numSongs > 1) {
        Song *newArray = new Song[numSongs-1];
        for (int i = 0; i < index; i++) {
            newArray[i] = songs[i];
        }
        for (int i = index+1; i < numSongs; i++) {
            newArray[i-1] = songs[i];
        }
        delete[] songs;
        songs = newArray;
        numSongs--;
    }
}

/*************************************************************
 * Function: edit()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: calling functions to edit song's info
 * Input parameters: -
 * Returns: -
 * Pre: object must exist
 * Post: song info edited
 **********************************************************/
void SongLibrary::edit() {
    if (numSongs > 0) {
        int index = -1;
        string attribute = "";
        string newAttributeValue = "";
        string garbage = "";

        cout << "Enter index of song that you want to remove (index starts at 0 and maximum is " << numSongs - 1 << ")" << endl;
        cin >> index;
        getline (cin , garbage);
        cout << "What attribute you want to change? You can choose between title, artist, genre, and rating" << endl;
        getline (cin , attribute);
        if (checkAttribute(attribute)) {
            cout << "Enter new value for this attribute, rating can accept only integers from 1 to 5." << endl;
            getline(cin, newAttributeValue);
            if (index < numSongs) {
                SongLibrary::performEditSong(index, attribute, newAttributeValue);
            } else {
                cout << "Index is out of range, maximum index for you is " << numSongs - 1 << endl;
            }
        }
    } else {
        cout << "Your playlist is empty, nothing to change" << endl;
    }
}

/*************************************************************
 * Function: performEditSong()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: editing song
 * Input parameters: int indexToEdit, string attribute, string newAttributeValue
 * Returns: -
 * Pre: object must exist
 * Post: song info edited
 **********************************************************/
void SongLibrary::performEditSong(int indexToEdit, string attribute, string newAttributeValue) {
    if (attribute == "title") {
        (songs + indexToEdit)->setTitle(newAttributeValue);
    } else if (attribute == "artist") {
        (songs + indexToEdit)->setArtist(newAttributeValue);
    } else if (attribute == "genre") {
        (songs + indexToEdit)->setGenre(newAttributeValue);
    } else if (attribute == "rating") {
        (songs + indexToEdit)->setRating(stoi(newAttributeValue));
    } else {
        cout << "Unknown attribute" << endl;
    }
}

/*************************************************************
 * Function: createNewArr()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: editing song
 * Input parameters: -
 * Returns: Song * songs
 * Pre: object must exist
 * Post: new arr created
 **********************************************************/
Song * SongLibrary::createNewArr() {
    if (numSongs > 0 && songs != NULL) {
        Song * temp = new Song [numSongs - 1];
        copyArr (songs , temp , getNumSongs()-1);
        setSongsArray(songs);
        songs = new Song[numSongs];
        copyArr (temp , songs , getNumSongs()-1);
        delete [] temp;
        temp = NULL;
    } else if (numSongs > 0) {
        setSongsArray(songs);
        songs = new Song[numSongs];
    }else {
        cout << "Can't create array with 0 elements" << endl;
    }
    return songs;
}

/*************************************************************
 * Function: openFile()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: opening file
 * Input parameters: string filename, fstream& file
 * Returns: bool
 * Pre: -
 * Post: file opened
 **********************************************************/
bool openFile (string filename, fstream& file) {
    file.open(filename);

    if (!file.is_open()) {
        cout << "Can't open the file" << endl;
        return false;
    } else {
        return true;
    }
}

/*************************************************************
 * Function: createNewSong()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: creates new song
 * Input parameters: -
 * Returns: -
 * Pre: object must exist
 * Post: new song created
 **********************************************************/
void SongLibrary::createNewSong() {
    string title = "";
    string author = "";
    string genre = "";
    int rating = 0;
    cout << "Enter song's title" << endl;
    getline(cin , title);
    cout << "Enter song's author" << endl;
    getline(cin , author);
    cout << "Enter song's genre" << endl;
    getline(cin , genre);
    cout << "Enter song's rating, rating should be an integer from 1 to 5" << endl;
    cin >> rating;
    Song * newSong = new Song(title , author , genre , rating);
    SongLibrary::performAddSong(*newSong);
}

/*************************************************************
 * Function: readFromFile()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: reads info from file to memory
 * Input parameters: string filename
 * Returns: -
 * Pre: object must exist
 * Post: info readd
 **********************************************************/
void SongLibrary::readFromFile (string filename) {
    fstream file;

    string newTitle = "";
    string newArtist = "";
    string newGenre = "";
    string newRating = "";
    Song * arr = NULL;
    SongLibrary::setSongsArray(arr);
    int numSongs = 0;

    if (openFile(filename , file)) {
        string line;
        while (!file.eof()) {
            getline(file, line);
            getline(file, line);
            if (line == "") {
                break;
            }
            getline(file, line);
            getline(file , line);
            getline(file , line);
            numSongs++;
        }

        SongLibrary::setNumSongs(numSongs);

        arr = SongLibrary::createNewArr();

        file.clear();
        file.seekg(0, ios::beg);

        for (int i = 0; i < numSongs; i++) {
            getline(file , newTitle);
            arr[i].setTitle(newTitle);
            getline(file , newArtist);
            arr[i].setArtist(newArtist);
            getline(file , newGenre);
            arr[i].setGenre(newGenre);
            getline(file , newRating);
            arr[i].setRating(stoi(newRating));
            getline(file , line);
        }
    }
    closeFile(file);
}

/*************************************************************
 * Function: closeFile()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: closes file
 * Input parameters: fstream& file
 * Returns: -
 * Pre: file must be opened
 * Post: file closed
 **********************************************************/
void closeFile (fstream& file) {
    file.close();
}

/*************************************************************
 * Function: copyArr()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: copy info from one arr into another
 * Input parameters: Song arr1[] , Song arr2[] , int size
 * Returns: -
 * Pre: -
 * Post: info copied
 **********************************************************/
void copyArr (Song arr1[] , Song arr2[] , int size) {
    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
    }
}

/*************************************************************
 * Function: clearFile()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: clears file
 * Input parameters: string filename
 * Returns: -
 * Pre: -
 * Post: file is empty
 **********************************************************/
void clearFile(string filename) {
    ofstream file;
    file.open(filename, std::ofstream::out | std::ofstream::trunc);
    file.close();
}

/*************************************************************
 * Function: sortByAtt()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: sorting array by attribute
 * Input parameters: Song arr[] , string attribute , int size
 * Returns: -
 * Pre: array must have at least one element
 * Post: array sorted
 **********************************************************/
void sortByAtt(Song arr[] , string attribute , int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if ((arr + j)->getStringAttributeValue(attribute) > (arr + j + 1)->getStringAttributeValue(attribute)) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/*************************************************************
 * Function: checkAttribute()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: validating attribute
 * Input parameters: string attribute
 * Returns: bool
 * Pre: -
 * Post: attribute validated
 **********************************************************/
bool checkAttribute (string attribute) {
    if (attribute == "title" || attribute == "artist" || attribute == "genre" || attribute == "rating") {
        return true;
    } else {
        cout << "Unknown attribute" << endl;
        return false;
    }
}