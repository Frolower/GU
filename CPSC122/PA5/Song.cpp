/*
 Name: Nikita Dubinin
 Class: CPSC 122, Spring 2023
 Date: March 23, 2023
 Programming Assignment: PA5
 Description: Music Library
 Notes: -
*/

#include "Song.h"

/*************************************************************
 * Function: convertToLowercase()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: converts string to lowercase
 * Input parameters: string s
 * Returns: string s
 * Pre: string must exist
 * Post: sing convertad to lowercase
 **********************************************************/
string convertToLowercase(string s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
	return s;
}

/*************************************************************
 * Function: Song class dvc
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: creating song class object with default values
 * Input parameters: -
 * Returns: song class object
 * Pre:
 * Post: song class object created
 **********************************************************/
Song::Song() {
    title = "";
    artist = "";
    genre = "";
    rating = 1;
}

/*************************************************************
 * Function: Song class EVC
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: creating song class object with concrete values
 * Input parameters: string titleParam, string artistParam, string genreParam, int ratingParam
 * Returns: -
 * Pre: -
 * Post: song class object created
 **********************************************************/
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
    setTitle(titleParam);
    setArtist(artistParam);
    setGenre(genreParam);
    setRating(ratingParam);
}

/*************************************************************
 * Function: getTitle()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: returning title
 * Input parameters: -
 * Returns: string title
 * Pre: object must exist
 * Post: title returned
 **********************************************************/
string Song::getTitle() {
	return title;
}

/*************************************************************
 * Function: setTitle()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: changing title value
 * Input parameters: string newTitle
 * Returns: -
 * Pre: object must exist
 * Post: new title
 **********************************************************/
void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}

/*************************************************************
 * Function: getArtist()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: returning artist
 * Input parameters: -
 * Returns: string artist
 * Pre: object must exist
 * Post: artist returned
 **********************************************************/
string Song::getArtist() {
	return artist;
}

/*************************************************************
 * Function: setArtist()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: changing artist
 * Input parameters: string newArtist
 * Returns: -
 * Pre: object must exist
 * Post: artist changed
 **********************************************************/
void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}

/*************************************************************
 * Function: getGenre()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: returning genre
 * Input parameters: -
 * Returns: string genre
 * Pre: object must exist
 * Post: genre returned
 **********************************************************/
string Song::getGenre() {
	return genre;
}

/*************************************************************
 * Function: setArtist()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: changing genre
 * Input parameters: string newGenre
 * Returns: -
 * Pre: object must exist
 * Post: new genre
 **********************************************************/
void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}

/*************************************************************
 * Function: getRating()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: returning rating
 * Input parameters: -
 * Returns: string rating
 * Pre: object must exist
 * Post: rating returned
 **********************************************************/
int Song::getRating() {
	return rating;
}

void Song::setRating(int newRating) {
	if (newRating < MIN_RATING || newRating > MAX_RATING) {
		cout << "Rating must be in [" << MIN_RATING << ", " << MAX_RATING << "]" << endl;
	}
	if (newRating < MIN_RATING) {
		rating = MIN_RATING;
	}
	else if (newRating > MAX_RATING) {
		rating = MAX_RATING;
	}
	else {
		rating = newRating;
	}
}

/*************************************************************
 * Function: displaySong()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: displaying information about song
 * Input parameters: -
 * Returns: -
 * Pre: object must exist
 * Post: information about song displayed
 **********************************************************/
void Song::displaySong() {
    cout << "Name: " << title << endl;
    cout << "Artist: " << artist << endl;
    cout << "Genre: " << genre << endl;
    cout << "Rating: " << rating << endl;
    cout << endl;
}

/*************************************************************
 * Function: getStringAttributeValue()
 * Date Created: 22/03/2023
 * Date Last Modified: 22/03/2023
 * Description: returning right attribute value
 * Input parameters: string attribute
 * Returns: string attribute
 * Pre: object must exist
 * Post: attribute value returned
 **********************************************************/
string Song::getStringAttributeValue(string attribute) {
    if (attribute == "title") {
        return Song::getTitle();
    } else if (attribute == "artist") {
        return Song::getArtist();
    } else if (attribute == "genre") {
        return Song::getGenre();
    } else if (attribute == "rating") {
        return to_string(Song::getRating());
    } else {
        return "";
    }
}