#include "gtest/gtest.h"
#include "PA6.h"

// NOTE: the order is expected/solution, actual/received student value
TEST(Test1_Song_SongLibrary, copyConstructors) {
Song * song1 = new Song("the twist", "chubby checker", "rock", 3);
Song * song2 = new Song("smooth", "santana", "electronic", 5);

// Song next getter and setter
song1->setNext(song2);
EXPECT_EQ(song2, song1->getNext());
EXPECT_EQ(NULL, song2->getNext());

// Song copy constructor
Song * song3 = new Song(*song1); // copy constructor
EXPECT_EQ("the twist", song3->getTitle());
EXPECT_EQ("chubby checker", song3->getArtist());
EXPECT_EQ("rock", song3->getGenre());
EXPECT_EQ(3, song3->getRating());
EXPECT_EQ(NULL, song3->getNext()); // no shared memory
delete song3;

Song * song4 = new Song(*song2);

// SongLibrary copy constructor
SongLibrary lib;
lib.setHead(song1);
lib.setSortAttribute("rating");
song2->setNext(song4);
song4->setNext(NULL);
EXPECT_EQ(song1, lib.getHead());
if (lib.getHead() != NULL && lib.getHead()->getNext() != NULL) {
EXPECT_EQ(song2, lib.getHead()->getNext());
EXPECT_EQ(song4, lib.getHead()->getNext()->getNext());
}

SongLibrary lib2(lib);
EXPECT_TRUE(lib.getHead() != lib2.getHead()); // should have diff mem addresses
EXPECT_TRUE(lib.getHead() != NULL);
EXPECT_TRUE(lib2.getHead() != NULL);
if (lib.getHead() != NULL && lib2.getHead() != NULL) {
EXPECT_EQ(lib.getHead()->getTitle(), lib2.getHead()->getTitle()); // should have same values though
EXPECT_TRUE(lib.getHead()->getNext() != lib2.getHead()->getNext()); // should have diff mem addresses
EXPECT_EQ(lib.getHead()->getNext()->getTitle(), lib2.getHead()->getNext()->getTitle()); // should have same values though
EXPECT_TRUE(lib.getHead()->getNext()->getNext() != lib2.getHead()->getNext()->getNext()); // should have diff mem addresses
EXPECT_EQ(lib.getHead()->getNext()->getNext()->getTitle(), lib2.getHead()->getNext()->getNext()->getTitle()); // should have same values though
EXPECT_EQ(NULL, lib2.getHead()->getNext()->getNext()->getNext());
}
}

TEST(Test2_SongLibrary, performLoadAndSave) {
SongLibrary lib;

lib.performLoad("../test/library_test1.txt");
EXPECT_TRUE(lib.getHead() != NULL);
if (lib.getHead() != NULL) {
EXPECT_TRUE(lib.getHead()->getNext() != NULL);
if (lib.getHead()->getNext() != NULL) {
EXPECT_EQ(NULL, lib.getHead()->getNext()->getNext());
}
}

Song * song = new Song("the twist", "chubby checker", "rock", 3);
lib.setHead(song);
lib.performSave("../test/library_test2.txt");
lib.performLoad("../test/library_test2.txt");
EXPECT_EQ("the twist", lib.getHead()->getTitle());
EXPECT_EQ(NULL, lib.getHead()->getNext());
// SongLibrary destructor should free songs memory
}


TEST(Test3_SongLibrary, performSort) {
SongLibrary lib;

Song * song1 = new Song("the twist", "chubby checker", "rock", 3);
Song * song2 = new Song("smooth", "santana", "electronic", 5);
song1->setNext(song2);
lib.setHead(song1);
EXPECT_EQ(song1, lib.getHead());
EXPECT_EQ(song2, lib.getHead()->getNext());

lib.setSortAttribute("title");
lib.performSort();
EXPECT_EQ("smooth", lib.getHead()->getTitle());
EXPECT_EQ("the twist", lib.getHead()->getNext()->getTitle());

lib.setSortAttribute("artist");
lib.performSort();
EXPECT_EQ("the twist", lib.getHead()->getTitle());
EXPECT_EQ("smooth", lib.getHead()->getNext()->getTitle());

lib.setSortAttribute("genre");
lib.performSort();
EXPECT_EQ("smooth", lib.getHead()->getTitle());
EXPECT_EQ("the twist", lib.getHead()->getNext()->getTitle());

lib.setSortAttribute("rating");
lib.performSort();
EXPECT_EQ("the twist", lib.getHead()->getTitle());
EXPECT_EQ("smooth", lib.getHead()->getNext()->getTitle());
// SongLibrary destructor should free songs memory
}

TEST(Test4_SongLibrary, performSearch) {
SongLibrary lib;

Song * song1 = new Song("the twist", "chubby checker", "rock", 3);
Song * song2 = new Song("smooth", "santana", "electronic", 5);
song1->setNext(song2);
lib.setHead(song1);
EXPECT_EQ(song1, lib.getHead());
EXPECT_EQ(song2, lib.getHead()->getNext());

Song * foundSong;
int index = 0;
bool found = false;
foundSong = lib.performSearch("title", "smooth", &found, &index);
EXPECT_EQ(true, found);
EXPECT_TRUE(foundSong != NULL);
if (foundSong != NULL) {
EXPECT_EQ("smooth", foundSong->getTitle());
}
EXPECT_EQ(1, index);

foundSong = lib.performSearch("artist", "santana", &found, &index);
EXPECT_EQ(true, found);
EXPECT_TRUE(foundSong != NULL);
if (foundSong != NULL) {
EXPECT_EQ("santana", foundSong->getArtist());
}
EXPECT_EQ(1, index);

foundSong = lib.performSearch("genre", "rock", &found, &index);
EXPECT_EQ(true, found);
EXPECT_TRUE(foundSong != NULL);
if (foundSong != NULL) {
EXPECT_EQ("rock", foundSong->getGenre());
EXPECT_EQ("electronic", foundSong->getNext()->getGenre());
}
EXPECT_EQ(0, index);

// not found test
index = -1;
foundSong = lib.performSearch("genre", "pop", &found, &index);
EXPECT_EQ(false, found);
EXPECT_EQ(-1, index);
EXPECT_EQ(NULL, foundSong);

foundSong = lib.performSearch("rating", "5", &found, &index);
EXPECT_EQ(true, found);
EXPECT_TRUE(foundSong != NULL);
if (foundSong != NULL) {
EXPECT_EQ(5, foundSong->getRating());
}
EXPECT_EQ(1, index);

// SongLibrary destructor should free songs memory
}

TEST(Test5_SongLibrary, performInsertSongInOrder) {
// test title
SongLibrary lib;
EXPECT_EQ(NULL, lib.getHead());
lib.setSortAttribute("title");

// add to empty list
Song * song1 = new Song("the twist", "chubby checker", "rock", 3);
lib.performInsertSongInOrder(song1);
EXPECT_EQ(song1, lib.getHead());

// add to non empty list
Song * song2 = new Song("smooth", "santana", "electronic", 5);
lib.performInsertSongInOrder(song2);
EXPECT_EQ(song2, lib.getHead());
EXPECT_TRUE(lib.getHead() != NULL);
if (lib.getHead() != NULL) {
EXPECT_EQ(song1, lib.getHead()->getNext());
if (lib.getHead()->getNext() != NULL) { // to prevent seg faults in starter code
EXPECT_EQ("smooth", lib.getHead()->getTitle());
EXPECT_EQ("the twist", lib.getHead()->getNext()->getTitle());

EXPECT_EQ("santana", lib.getHead()->getArtist());
EXPECT_EQ("chubby checker", lib.getHead()->getNext()->getArtist());
}
}

// test rating
SongLibrary lib2;
EXPECT_EQ(NULL, lib2.getHead());
lib2.setSortAttribute("rating");

// add to empty list
song1 = new Song("the twist", "chubby checker", "rock", 3);
lib2.performInsertSongInOrder(song1);
EXPECT_EQ(song1, lib2.getHead());

// add to non empty list
song2 = new Song("smooth", "santana", "electronic", 5);
lib2.performInsertSongInOrder(song2);
EXPECT_EQ(song1, lib2.getHead());
EXPECT_TRUE(lib2.getHead() != NULL);
if (lib2.getHead() != NULL) {
EXPECT_EQ(song2, lib2.getHead()->getNext());
if (lib2.getHead()->getNext() != NULL) { // to prevent seg faults in starter code
EXPECT_EQ("the twist", lib2.getHead()->getTitle());
EXPECT_EQ("smooth", lib2.getHead()->getNext()->getTitle());

EXPECT_EQ("chubby checker", lib2.getHead()->getArtist());
EXPECT_EQ("santana", lib2.getHead()->getNext()->getArtist());
}
}
}

TEST(Test6_SongLibrary, performRemoveSong) {
SongLibrary lib;

Song * song1 = new Song("the twist", "chubby checker", "rock", 3);
Song * song2 = new Song("smooth", "santana", "electronic", 5);
Song * song3 = new Song("mack the knife", "bobby darin", "rock", 2);
song1->setNext(song2);
song2->setNext(song3);

lib.setHead(song1);
EXPECT_EQ(song1, lib.getHead());
EXPECT_EQ(song2, lib.getHead()->getNext());
EXPECT_EQ(song3, lib.getHead()->getNext()->getNext());

lib.performRemoveSong(song1);
EXPECT_EQ(NULL, lib.getHead()->getNext()->getNext());
EXPECT_EQ("smooth", lib.getHead()->getTitle());
EXPECT_EQ("santana", lib.getHead()->getArtist());
EXPECT_EQ("electronic", lib.getHead()->getGenre());
EXPECT_EQ(5, lib.getHead()->getRating());
EXPECT_EQ("mack the knife", lib.getHead()->getNext()->getTitle());
EXPECT_EQ("bobby darin", lib.getHead()->getNext()->getArtist());
EXPECT_EQ("rock", lib.getHead()->getNext()->getGenre());
EXPECT_EQ(2, lib.getHead()->getNext()->getRating());

lib.performRemoveSong(song3);
EXPECT_EQ("smooth", lib.getHead()->getTitle());
EXPECT_EQ("santana", lib.getHead()->getArtist());
EXPECT_EQ("electronic", lib.getHead()->getGenre());
EXPECT_EQ(5, lib.getHead()->getRating());

lib.performRemoveSong(song2);
EXPECT_EQ(NULL, lib.getHead());
}


TEST(Test7_SongLibrary, performEditSong) {
SongLibrary lib;

Song * song1 = new Song("the twist", "chubby checker", "rock", 3);
Song * song2 = new Song("smooth", "santana", "electronic", 5);
Song * song3 = new Song("mack the knife", "bobby darin", "rock", 2);
song1->setNext(song2);
song2->setNext(song3);

lib.setHead(song1);
EXPECT_EQ(song1, lib.getHead());
EXPECT_EQ(song2, lib.getHead()->getNext());
EXPECT_EQ(song3, lib.getHead()->getNext()->getNext());

lib.performEditSong(song1, "title", "twist");
EXPECT_EQ("twist", lib.getHead()->getTitle());
EXPECT_EQ("chubby checker", lib.getHead()->getArtist());
EXPECT_EQ("rock", lib.getHead()->getGenre());
EXPECT_EQ(3, lib.getHead()->getRating());

lib.performEditSong(song2, "artist", "SANTANA");
EXPECT_EQ(song3, lib.getHead()->getNext()->getNext()); // make sure doesn't add or delete anything
EXPECT_EQ("smooth", lib.getHead()->getNext()->getTitle());
EXPECT_EQ("santana", lib.getHead()->getNext()->getArtist());
EXPECT_EQ("electronic", lib.getHead()->getNext()->getGenre());
EXPECT_EQ(5, lib.getHead()->getNext()->getRating());

lib.performEditSong(song2, "genre", "Dance");
EXPECT_EQ(song3, lib.getHead()->getNext()->getNext()); // make sure doesn't add or delete anything
EXPECT_EQ("smooth", lib.getHead()->getNext()->getTitle());
EXPECT_EQ("santana", lib.getHead()->getNext()->getArtist());
EXPECT_EQ("dance", lib.getHead()->getNext()->getGenre());
EXPECT_EQ(5, lib.getHead()->getNext()->getRating());

lib.performEditSong(song3, "rating", "4");
EXPECT_EQ(song3, lib.getHead()->getNext()->getNext()); // make sure doesn't add or delete anything
EXPECT_EQ("mack the knife", lib.getHead()->getNext()->getNext()->getTitle());
EXPECT_EQ("bobby darin", lib.getHead()->getNext()->getNext()->getArtist());
EXPECT_EQ("rock", lib.getHead()->getNext()->getNext()->getGenre());
EXPECT_EQ(4, lib.getHead()->getNext()->getNext()->getRating());

lib.performEditSong(song3, "rating", "0"); // make sure it clips to be in [1,5]
EXPECT_EQ(1, lib.getHead()->getNext()->getNext()->getRating());
lib.performEditSong(song3, "rating", "6"); // make sure it clips to be in [1,5]
EXPECT_EQ(5, lib.getHead()->getNext()->getNext()->getRating());
}