// NOTE: do not modify the contents of this file
#include "gtest/gtest.h"
#include "PA5.h"

// NOTE: the order is expected/solution, actual/received student value
TEST(Test1_Song, constructors_getStringAttributeValue) {
	Song song1;
	
	EXPECT_EQ("", song1.getStringAttributeValue("title"));
	EXPECT_EQ("", song1.getStringAttributeValue("artist"));
	EXPECT_EQ("", song1.getStringAttributeValue("genre"));
	EXPECT_EQ("1", song1.getStringAttributeValue("rating"));
	EXPECT_EQ("", song1.getStringAttributeValue("invalidAttribute"));
	
	Song song2("The Twist", "Chubby Checker", "Rock", 3);
	
	song2.setTitle("TWIST"); // make sure always storing lowercase
	EXPECT_EQ("twist", song2.getTitle());
	song2.setArtist("Chubby");
	EXPECT_EQ("chubby", song2.getArtist());
	song2.setGenre("Rock-Pop");
	EXPECT_EQ("rock-pop", song2.getGenre());
	song2.setRating(2);
	EXPECT_EQ(2, song2.getRating());
	song2.setRating(0); // make sure it clips to be in [1,5]
	EXPECT_EQ(1, song2.getRating());
	song2.setRating(6); // make sure it clips to be in [1,5]
	EXPECT_EQ(5, song2.getRating());

	EXPECT_EQ("twist", song2.getStringAttributeValue("title"));
	EXPECT_EQ("chubby", song2.getStringAttributeValue("artist"));
	EXPECT_EQ("rock-pop", song2.getStringAttributeValue("genre"));
	EXPECT_EQ("5", song2.getStringAttributeValue("rating"));
	EXPECT_EQ("", song2.getStringAttributeValue("invalidAttribute"));
}

TEST(Test2_SongLibrary, performLoadAndSave) {
	SongLibrary lib;
	
	lib.performLoad("../test/library_test1.txt");
	EXPECT_EQ(2, lib.getNumSongs());
	
	Song song("the twist", "chubby checker", "rock", 3);
	Song * songs = new Song[1];
	songs[0] = song;
	lib.setSongsArray(songs);
	lib.setNumSongs(1);
	lib.performSave("../test/library_test2.txt");
	lib.performLoad("../test/library_test2.txt");
	EXPECT_EQ(1, lib.getNumSongs());
	// SongLibrary destructor should free songs memory
}

TEST(Test3_SongLibrary, performSort) {
	SongLibrary lib;
	
	Song song1("the twist", "chubby checker", "rock", 3);
	Song song2("smooth", "santana", "electronic", 5);
	Song * songs = new Song[2];
	songs[0] = song1;
	songs[1] = song2;
	lib.setSongsArray(songs);
	lib.setNumSongs(2);
	lib.performSort("title");
	EXPECT_EQ("smooth", lib.getSongsArray()[0].getTitle());
	EXPECT_EQ("the twist", lib.getSongsArray()[1].getTitle());
	
	lib.performSort("artist");
	EXPECT_EQ("the twist", lib.getSongsArray()[0].getTitle());
	EXPECT_EQ("smooth", lib.getSongsArray()[1].getTitle());
	
	lib.performSort("genre");
	EXPECT_EQ("smooth", lib.getSongsArray()[0].getTitle());
	EXPECT_EQ("the twist", lib.getSongsArray()[1].getTitle());
	
	lib.performSort("rating");
	EXPECT_EQ("the twist", lib.getSongsArray()[0].getTitle());
	EXPECT_EQ("smooth", lib.getSongsArray()[1].getTitle());
	// SongLibrary destructor should free songs memory
}

TEST(Test4_SongLibrary, performSearch) {
	SongLibrary lib;
	
	Song song1("the twist", "chubby checker", "rock", 3);
	Song song2("smooth", "santana", "electronic", 5);
	Song * songs = new Song[2];
	songs[0] = song1;
	songs[1] = song2;
	lib.setSongsArray(songs);
	lib.setNumSongs(2);
	
	Song foundSong;
	int index = 0;
	bool found = false;
	found = lib.performSearch("title", "smooth", &foundSong, &index);
	EXPECT_EQ(true, found);
	EXPECT_EQ("smooth", foundSong.getTitle());
	EXPECT_EQ(1, index);
	
	found = lib.performSearch("artist", "santana", &foundSong, &index);
	EXPECT_EQ(true, found);
	EXPECT_EQ("santana", foundSong.getArtist());
	EXPECT_EQ(1, index);
	
	found = lib.performSearch("genre", "rock", &foundSong, &index);
	EXPECT_EQ(true, found);
	EXPECT_EQ("rock", foundSong.getGenre());
	EXPECT_EQ(0, index);
	
	// not found test
	index = -1;
	found = lib.performSearch("genre", "pop", &foundSong, &index);
	EXPECT_EQ(false, found);
	EXPECT_EQ(-1, index);
	
	found = lib.performSearch("rating", "5", &foundSong, &index);
	EXPECT_EQ(true, found);
	EXPECT_EQ(5, foundSong.getRating());
	EXPECT_EQ(1, index);
	
	// SongLibrary destructor should free songs memory
}

TEST(Test5_SongLibrary, performAddSong) {
	SongLibrary lib;
	EXPECT_EQ(lib.getNumSongs(), 0);
	
	// add to empty list
	Song song1("the twist", "chubby checker", "rock", 3);
	lib.performAddSong(song1);
	EXPECT_EQ(1, lib.getNumSongs());
	
	// add to non empty list
	Song song2("smooth", "santana", "electronic", 5);
	lib.performAddSong(song2);
	EXPECT_EQ(2, lib.getNumSongs());
	
	if (2 == lib.getNumSongs()) { // to prevent seg faults in starter code
		EXPECT_EQ("the twist", lib.getSongsArray()[0].getTitle());
		EXPECT_EQ("smooth", lib.getSongsArray()[1].getTitle());
		
		EXPECT_EQ("chubby checker", lib.getSongsArray()[0].getArtist());
		EXPECT_EQ("santana", lib.getSongsArray()[1].getArtist());
		
		EXPECT_EQ("rock", lib.getSongsArray()[0].getGenre());
		EXPECT_EQ("electronic", lib.getSongsArray()[1].getGenre());
		
		EXPECT_EQ(3, lib.getSongsArray()[0].getRating());
		EXPECT_EQ(5, lib.getSongsArray()[1].getRating());
	}
}

TEST(Test6_SongLibrary, performRemoveSong) {
	SongLibrary lib;
	
	Song song1("the twist", "chubby checker", "rock", 3);
	Song song2("smooth", "santana", "electronic", 5);
	Song song3("mack the knife", "bobby darin", "rock", 2);
	Song * songs = new Song[3];
	songs[0] = song1;
	songs[1] = song2;
	songs[2] = song3;
	lib.setSongsArray(songs);
	lib.setNumSongs(3);
	EXPECT_EQ(3, lib.getNumSongs());
	
	lib.performRemoveSong(0);
	EXPECT_EQ(2, lib.getNumSongs());
	EXPECT_EQ("smooth", lib.getSongsArray()[0].getTitle());
	EXPECT_EQ("santana", lib.getSongsArray()[0].getArtist());
	EXPECT_EQ("electronic", lib.getSongsArray()[0].getGenre());
	EXPECT_EQ(5, lib.getSongsArray()[0].getRating());	
	EXPECT_EQ("mack the knife", lib.getSongsArray()[1].getTitle());
	EXPECT_EQ("bobby darin", lib.getSongsArray()[1].getArtist());
	EXPECT_EQ("rock", lib.getSongsArray()[1].getGenre());
	EXPECT_EQ(2, lib.getSongsArray()[1].getRating());	
	
	lib.performRemoveSong(1);
	EXPECT_EQ(1, lib.getNumSongs());
	EXPECT_EQ("smooth", lib.getSongsArray()[0].getTitle());
	EXPECT_EQ("santana", lib.getSongsArray()[0].getArtist());
	EXPECT_EQ("electronic", lib.getSongsArray()[0].getGenre());
	EXPECT_EQ(5, lib.getSongsArray()[0].getRating());
	
	lib.performRemoveSong(0);
	EXPECT_EQ(0, lib.getNumSongs());
	EXPECT_TRUE(lib.getSongsArray() == NULL);
}

TEST(Test7_SongLibrary, performEditSong) {
	SongLibrary lib;
	
	Song song1("the twist", "chubby checker", "rock", 3);
	Song song2("smooth", "santana", "electronic", 5);
	Song song3("mack the knife", "bobby darin", "rock", 2);
	Song * songs = new Song[3];
	songs[0] = song1;
	songs[1] = song2;
	songs[2] = song3;
	lib.setSongsArray(songs);
	lib.setNumSongs(3);
	EXPECT_EQ(3, lib.getNumSongs());
	
	lib.performEditSong(0, "title", "twist");
	EXPECT_EQ(3, lib.getNumSongs()); // make sure doesn't add or delete anything
	EXPECT_EQ("twist", lib.getSongsArray()[0].getTitle());
	EXPECT_EQ("chubby checker", lib.getSongsArray()[0].getArtist());
	EXPECT_EQ("rock", lib.getSongsArray()[0].getGenre());
	EXPECT_EQ(3, lib.getSongsArray()[0].getRating());	
	
	lib.performEditSong(1, "artist", "SANTANA");
	EXPECT_EQ(3, lib.getNumSongs()); // make sure doesn't add or delete anything
	EXPECT_EQ("smooth", lib.getSongsArray()[1].getTitle());
	EXPECT_EQ("santana", lib.getSongsArray()[1].getArtist());
	EXPECT_EQ("electronic", lib.getSongsArray()[1].getGenre());
	EXPECT_EQ(5, lib.getSongsArray()[1].getRating());	
	
	lib.performEditSong(1, "genre", "Dance");
	EXPECT_EQ(3, lib.getNumSongs()); // make sure doesn't add or delete anything
	EXPECT_EQ("smooth", lib.getSongsArray()[1].getTitle());
	EXPECT_EQ("santana", lib.getSongsArray()[1].getArtist());
	EXPECT_EQ("dance", lib.getSongsArray()[1].getGenre());
	EXPECT_EQ(5, lib.getSongsArray()[1].getRating());	
	
	lib.performEditSong(2, "rating", "4");
	EXPECT_EQ(3, lib.getNumSongs()); // make sure doesn't add or delete anything
	EXPECT_EQ("mack the knife", lib.getSongsArray()[2].getTitle());
	EXPECT_EQ("bobby darin", lib.getSongsArray()[2].getArtist());
	EXPECT_EQ("rock", lib.getSongsArray()[2].getGenre());
	EXPECT_EQ(4, lib.getSongsArray()[2].getRating());	
	
	lib.performEditSong(2, "rating", "0"); // make sure it clips to be in [1,5]
	EXPECT_EQ(1, lib.getSongsArray()[2].getRating());
	lib.performEditSong(2, "rating", "6"); // make sure it clips to be in [1,5]
	EXPECT_EQ(5, lib.getSongsArray()[2].getRating());
}
