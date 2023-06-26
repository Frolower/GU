/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: April 5, 2023
 Programming Assignment: PA6
 Description: Music Library
 Notes: -
*/

#include "SongLibrary.h"

/*************************************************************
 * Function: SongLibrary class dvc
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: creating SongLibrary class object with default values
 * Input parameters: -
 * Returns: SongLibrary class object
 * Pre:
 * Post: SongLibrary class object created
 **********************************************************/
SongLibrary::SongLibrary() {
	// initialize to empty list
	head = NULL; 
	// default sort attribute is title
	sortAttribute = "title";
}

/*************************************************************
 * Function: SongLibrary class copy constructor
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: creating songLibrary class object with copy values
 * Input parameters: const SongLibrary& other
 * Returns: -
 * Pre: other object must exist
 * Post: SongLibrary class object created with copy values
 **********************************************************/
SongLibrary::SongLibrary(const SongLibrary& other) {
    head = NULL;
    Song * curr;
    curr = other.head;
    sortAttribute = other.sortAttribute;
    while (curr != NULL) {
        Song * newSong = new Song (*curr);
        performInsertSongInOrder(newSong);
        curr = curr->getNext();
    }
}


/*************************************************************
 * Function: Song class destructor
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: destructing SongLibrary class
 * Input parameters: -
 * Returns: -
 * Pre: -
 * Post: SongLibrary class destroyed
 **********************************************************/
SongLibrary::~SongLibrary() {
    Song * current = head;
    while( current != NULL ) {
        Song * next = current->getNext();
        delete current;
        current = next;
    }
    head = NULL;
    delete head;
}

/*************************************************************
 * Function: getHead()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: head getter
 * Input parameters: -
 * Returns: head
 * Pre: SongLibrary object must exist
 * Post: head returned
 **********************************************************/
Song * SongLibrary::getHead() const {
	return head;
}

/*************************************************************
 * Function: setHead()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: head setter
 * Input parameters: Song * newHead
 * Returns: -
 * Pre: SongLibrary object must exist
 * Post: new value set
 **********************************************************/
void SongLibrary::setHead(Song * newHead) {
	if (head != NULL) {
        Song * current = head;
        while( current != NULL ) {
            Song * next = current->getNext();
            delete current;
            current = next;
        }
        head = NULL;
	}
	head = newHead;
}

/*************************************************************
 * Function: getSortAttribute()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: sort attribute getter
 * Input parameters: -
 * Returns: sortAttribute
 * Pre: SongLibrary object must exist
 * Post: sort attribute returned
 **********************************************************/
string SongLibrary::getSortAttribute() const {
	return sortAttribute;
}

/*************************************************************
 * Function: setSortAttribute()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: head setter
 * Input parameters: string newSortAttribute
 * Returns: -
 * Pre: SongLibrary object must exist
 * Post: new value set
 **********************************************************/
void SongLibrary::setSortAttribute(string newSortAttribute) {
	sortAttribute = newSortAttribute;
}

/*************************************************************
 * Function: performLoad()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: calling function to load info from file
 * Input parameters: string filename
 * Returns: -
 * Pre: object must exist
 * Post: information from file stored
 **********************************************************/
void SongLibrary::performLoad(string filename) {
    fstream file;
    string newTitle = "";
    string newArtist = "";
    string newGenre = "";
    string newRating = "";
    string garbage = "";
    Song * newSong = NULL;

    if (openFile(filename , file)) {
        SongLibrary::clearLibrary();

        while (!file.eof()) {
            getline(file, newTitle);
            getline(file, newArtist);
            if (newArtist == "") {
                break;
            }
            getline(file, newGenre);
            getline(file , newRating);
            getline(file , garbage);

            newSong = new Song (newTitle , newArtist , newGenre , stoi(newRating));
            SongLibrary::performInsertSongInOrder(newSong);
        }
    }
    file.close();
}

/*************************************************************
 * Function: performSave()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: saving library to file
 * Input parameters: string filename
 * Returns: -
 * Pre: object must exist
 * Post: info stored into file
 **********************************************************/
void SongLibrary::performSave(string filename) {
    fstream file;
    Song * curr = head;

	if(openFile(filename , file)) {
        clearFile(filename);
        while (curr != NULL) {
            file << curr->getTitle() << endl;
            file << curr->getArtist() << endl;
            file << curr->getGenre() << endl;
            file << curr->getRating() << endl;
            file << endl;
            curr = curr->getNext();
        }
    }
    file.close();
}

/*************************************************************
 * Function: sort()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: calling functions to sort library
 * Input parameters: -
 * Returns: -
 * Pre: object must exist
 * Post: list sorted
 **********************************************************/
void SongLibrary::sort() {
    string attribute = "";

    cout << "What attribute do you want to use for sort?" << endl;
    getline(cin , attribute);
    if (checkAttribute(attribute)) {
        sortAttribute = attribute;
        SongLibrary::performSort();
    }
}

/*************************************************************
 * Function: performSort()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: sorting library
 * Input parameters: -
 * Returns: -
 * Pre: object must exist
 * Post: list sorted
 **********************************************************/
void SongLibrary::performSort() {
    if (head == NULL || head->getNext() == NULL) {
        return; // Already sorted or empty list
    }

    Song *prev = NULL; // Sorted part of the list
    Song *curr = head; // Unsorted part of the list
    while (curr != NULL) {
        Song *next = curr->getNext();
        if (prev == NULL || curr->getStringAttributeValue(sortAttribute) < prev->getStringAttributeValue(sortAttribute)) {
            curr->setNext(prev);
            prev = curr;
        } else {
            Song *temp = prev;
            while (temp->getNext() != NULL && curr->getStringAttributeValue(sortAttribute) > temp->getNext()->getStringAttributeValue(sortAttribute)) {
                temp = temp->getNext();
            }
            curr->setNext(temp->getNext());
            temp->setNext(curr);
        }
        curr = next;
    }
    head = prev;
}

/*************************************************************
 * Function: performSearch()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: searching for song
 * Input parameters: string searchAttribute, string searchAttributeValue, Song * foundSong, int * index
 * Returns: Song *
 * Pre: object must exist
 * Post: song must be found
 **********************************************************/
Song * SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, bool * found, int * index) {
    Song * curr = head;
    int songNum = -1;

    if (head != NULL) {
        while (curr != NULL) {
            songNum++;
            if (curr->getStringAttributeValue(searchAttribute) == searchAttributeValue) {
                *found = true;
                *index = songNum;
                return curr;
            }
            curr = curr->getNext();
        }
    }
    cout << "Can't find valid song" << endl;
    *found = false;
    *index = -1;
    return NULL;
}

/*************************************************************
 * Function: addNewSong()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: calling functions to add new song
 * Input parameters: -
 * Returns: -
 * Pre: object must exist
 * Post: new song added
 **********************************************************/
void SongLibrary::addNewSong() {
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
    SongLibrary::performInsertSongInOrder(newSong);
}

/*************************************************************
 * Function: performInsertSongInOrder()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: adding new song to the library
 * Input parameters: Song * songToInsert
 * Returns: -
 * Pre: object must exist
 * Post: new song added
 **********************************************************/
void SongLibrary::performInsertSongInOrder(Song * songToInsert) {
    Song* curr = head;
    Song* prev = NULL;

    if (head != NULL) {
        while (curr != NULL) {
            if (songToInsert->getStringAttributeValue(sortAttribute) < curr->getStringAttributeValue(sortAttribute)) {
                break;
            }
            prev = curr;
            curr = curr->getNext();
        }
        if (prev == NULL) {
            head = songToInsert;
            songToInsert->setNext(curr);
        } else {
            prev->setNext(songToInsert);
            songToInsert->setNext(curr);
        }
    } else {
        head = songToInsert;
    }
}

/*************************************************************
 * Function: search()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: calling functions to search for an element
 * Input parameters: -
 * Returns: -
 * Pre: object must exist
 * Post: object must be found
 **********************************************************/
void SongLibrary::search() {
    string attribute = "";
    string value = "";
    bool found = false;
    int index = 0;
    Song * answer = NULL;

    cout << "What attribute do you want to use to find a song?" << endl;
    getline(cin , attribute);
    if (checkAttribute(attribute)) {
        cout << "What's attribute value?" << endl;
        getline(cin, value);
        answer = performSearch(attribute , value , &found , &index);
        cout << "That's what I found" << endl;
        answer->displaySong();
    }

}

/*************************************************************
 * Function: removeSong()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: calls functions to remove song
 * Input parameters: -
 * Returns: -
 * Pre: object must exist
 * Post: song removed
 **********************************************************/
void SongLibrary::removeSong() {
    string attribute = "";
    string value = "";
    bool found = false;
    int index = 0;
    Song * songToRemove = NULL;

    cout << "What attribute do you want to find a song to delete?" << endl;
    getline(cin , attribute);
    if (checkAttribute(attribute)) {
        cout << "What's attribute value?" << endl;
        getline(cin , value);
        songToRemove = SongLibrary::performSearch(attribute , value , &found , &index);
        if (found) {
            SongLibrary::performRemoveSong(songToRemove);
        }
    }

}

/*************************************************************
 * Function: performRemoveSong()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: removing song
 * Input parameters: Song * songToRemove
 * Returns: -
 * Pre: object must exist
 * Post: song removed
 **********************************************************/
void SongLibrary::performRemoveSong(Song * songToRemove) {
    Song * curr = head;
    Song * prev = NULL;

    while (curr != songToRemove) {
        prev = curr;
        curr = curr->getNext();
    }
    if (prev == NULL) {
        head = curr->getNext();
        delete curr;
    } else {
        prev->setNext(curr->getNext());
        delete curr;
    }
}

/*************************************************************
 * Function: edit()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: calling functions to edit song's info
 * Input parameters: -
 * Returns: -
 * Pre: object must exist
 * Post: song info edited
 **********************************************************/
void SongLibrary::edit() {
    string attribute = "";
    string value = "";
    bool found = false;
    int index = 0;
    Song * songToEdit = NULL;

    cout << "What attribute do you want to use to find a song?" << endl;
    getline(cin , attribute);
    if (checkAttribute(attribute)) {
        cout << "What's attribute value?" << endl;
        getline(cin, value);
        songToEdit = performSearch(attribute , value , &found , &index);
        cout << "What attribute do you want to change?" << endl;
        getline(cin , attribute);
        if (checkAttribute(attribute)) {
            cout << "Enter new value" << endl;
            getline(cin, value);
            SongLibrary::performEditSong(songToEdit , attribute , value);
        }
    }
}

/*************************************************************
 * Function: performEditSong()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: editing song
 * Input parameters: Song * songToEdit, string attribute, string newAttributeValue
 * Returns: -
 * Pre: object must exist
 * Post: song info edited
 **********************************************************/
void SongLibrary::performEditSong(Song * songToEdit, string attribute, string newAttributeValue) {	
    if (attribute == "title") {
        songToEdit->setTitle(newAttributeValue);
    } else if (attribute == "artist") {
        songToEdit->setArtist(newAttributeValue);
    } else if (attribute == "genre") {
        songToEdit->setGenre(newAttributeValue);
    } else if (attribute == "rating") {
        songToEdit->setRating(stoi(newAttributeValue));
    }
}

/*************************************************************
 * Function: clearLibrary()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: editing song
 * Input parameters: -
 * Returns: -
 * Pre: object must exist
 * Post: library is empty
 **********************************************************/
void SongLibrary::clearLibrary () {
    Song * current = head;
    while( current != NULL ) {
        Song * next = current->getNext();
        delete current;
        current = next;
    }
    head = NULL;
}

/*************************************************************
 * Function: displayLibrary()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
 * Description: displaying songs from library
 * Input parameters: -
 * Returns: -
 * Pre: object must exist
 * Post: library displayed
 **********************************************************/
void SongLibrary::displayLibrary () {
    Song * current = head;
    while( current != NULL ) {
        current->displaySong();
        current = current->getNext();
    }
}

/*************************************************************
 * Function: clearFile()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
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
 * Function: checkAttribute()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
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

/*************************************************************
 * Function: openFile()
 * Date Created: 04/04/2023
 * Date Last Modified: 05/04/2023
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
