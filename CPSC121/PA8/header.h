#ifndef HEADER_H
#define HEADER_H

#include <iostream> //for IO
#include <iomanip> //for formatting output
#include <ctime> //for seeding random number generator with time
#include <cstdlib> //for rand()
#include <string> //for string data type and member functions like getline()
#include <stdlib.h> //cls()

using namespace std;

const int BOARD_SIZE = 10;
const int MAX_INVENTORY_SIZE = 10; //<=10
const int NUM_TILE_TYPES = 4; //<= 4
const int NUM_LOOT_ITEMS = 10; //<= 10

const int TILE_TYPES[NUM_TILE_TYPES] = {'!' , '=' , '+' , '#'}; // ! - Skull base, = - road, + - swamp, # - forest
const string TILE_NAME[NUM_TILE_TYPES] = {"Outer Heaven Base" , "Road" , "Swamp" , "Forest"};
const int LOOT_LIST_VALUES[NUM_LOOT_ITEMS][2] = {{25 , 0} , {35 , 0} , {45 , 0} ,{35 , 0} , {45 , 0} , {15 , 1} , {20 , 1}, {30 , 1} , {40 , 1} , {50 , 1}}; //strength , is defensive 1 = true, 0 = false
const int CLEAR_VALUE = ' ';
const string LOOT_LIST_DESCRIPTIONS[NUM_LOOT_ITEMS] = {"Ballistic Helmet" , "Composite helmet" , "Bulletproof vest" , "Compose Armour" , "Nano Armour" , "Colt 1911" , "Spas 12" , "MP5" , "AK-74" , "Javelin"};

//void displayBoard(char board[][BOARD_SIZE], int rows, int cols);
char generateTile(int numTileTypes);

void menuPrompt(void);

void initBoard(char board[][BOARD_SIZE], int rows, int cols , int numTileTypes);

void displayBoardPosition(char board[][BOARD_SIZE], int rows, int cols, int currRow, int currCol);

void displayPlayerStats(int playerStats[3]);

void displayInventoryStats(int playerCurrentInventoryStats[][2], const string inventoryDescription[BOARD_SIZE], int numItems);

void displayScore(int score);

void updateStats(int playerStats[3], int playerCurrentInventoryStats[][2], int numItems);

bool fightMonster(int playerStats[3]);

void wipeInventory(int& numItems);

void clearTile(char board[][BOARD_SIZE], int currRow, int currCol , const char clearTile);

char getValidMovement (int row, int column);

void displayCurrTile (char tile , const string tileName[]);

void generateMonsterStats(int& monsterHealth , int& monsterAttack);

void pressToContinue(void);

void attack (bool isPlayer, int monsterAttack , int& monsterHealth , int playerStats[]);

void searchForLoot(int playerCurrentInventoryStats[][2] , string inventoryDescription[] , int& numPlayerItems , const string LOOT_LIST_DESCRIPTIONS[] , const int LOOT_LIST_VALUES[][2]);

void cls(void);

#endif
