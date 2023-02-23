/*
 Name: Nikita Dubinin
 Class: CPCS 121, Fall 2022
 Date: November 21, 2022
 Programming Assignment: PA8
 Description: Adventure Game
 Notes: -
*/

#include "header.h"

int main() {
    char choice = '\n';
    char board[BOARD_SIZE][BOARD_SIZE];
    char currTile = '\n';
    int playerCurrentInventoryStats[MAX_INVENTORY_SIZE][2];
    int numPlayerItems = 0;
    int playerStats[3] = {100 , 50 , 0}; //Health / attack / defense
    int numCells = BOARD_SIZE * BOARD_SIZE; // for finish after clearing all field
    string inventoryDescription[MAX_INVENTORY_SIZE];
    int gameScore = 0;
    int currRow = 0;
    int currCol = 0;
//    bool isMetalGear = false;
//    bool isBigBoss = false;
    bool displayInventory = false;
//    int diffLevel = 0;

//seed random number generator
    srand(time(0));

//initialize our game board with randomly generated tiles
    initBoard(board, BOARD_SIZE, BOARD_SIZE , NUM_TILE_TYPES);

    do {
        currTile = board[currRow][currCol]; //variable that shows current tile
        displayScore(gameScore); //your score
        displayPlayerStats(playerStats); // your stats
        if (displayInventory) { //if true => show display
            displayInventoryStats(playerCurrentInventoryStats, inventoryDescription, numPlayerItems);
        }
        displayBoardPosition(board, BOARD_SIZE, BOARD_SIZE, currRow, currCol);// => board with your position
        displayCurrTile(currTile , TILE_NAME); // display tile and its name
        menuPrompt(); // menu
        choice = getValidMovement(currRow , currCol); //if movement valid
        switch (choice) {
            case 'w':
                currRow--;
                break;
            case 's':
                currRow++;
                break;
            case 'a':
                currCol--;
                break;
            case 'd':
                currCol++;
                break;
            case 'i':
                if (!displayInventory) { // if true - show
                    displayInventory = true;
                } else {
                    displayInventory = false;
                }
                break;
            case 'f':
                if (board[currRow][currCol] != ' ') { //searching
                    gameScore += 5;
                    if (rand() % 2 + 1 == 1) {
                        if (fightMonster(playerStats)) { // if win
                            gameScore++;
                            wipeInventory(numPlayerItems); //wipe inwentory
                        } else { // game over!
                            cout << "You died!" << endl;
                            choice = 'q';
                            break;
                        }
                    }
                    searchForLoot(playerCurrentInventoryStats , inventoryDescription , numPlayerItems , LOOT_LIST_DESCRIPTIONS , LOOT_LIST_VALUES);
                    updateStats(playerStats, playerCurrentInventoryStats, numPlayerItems);
                    clearTile(board, currRow, currCol, CLEAR_VALUE);
                    currTile = CLEAR_VALUE;
                    numCells--;
                } else { //if already cleared
                    cout << "You already cleared this place, choose another action" << endl;
                }
                break;
            case 'c': //just clearing
                if (board[currRow][currCol] != ' ') {
                    gameScore++;
                    if (rand() % 10 + 1 == 1) {
                        if (fightMonster(playerStats)) {// if win
                            gameScore++;
                            wipeInventory(numPlayerItems);
                        } else {// game over
                            cout << "You died!" << endl;
                            choice = 'q';
                        }
                    }
                    clearTile(board, currRow, currCol, CLEAR_VALUE);
                    currTile = CLEAR_VALUE;
                    numCells--;
                } else { //if already cleared
                    cout << "You already cleared this place, choose another action" << endl;
                }
                break;
            default:
                break;
        }
        pressToContinue(); //maybe working incorrect
        cls(); //should work but not on mac os
        if (numCells < 1) {// if all cleared
            cout << "You won!" << endl;
            choice = 'q';
        }
    } while (choice != 'q');
//DISPLAY GAME RESULTS
    cout << "Game Over!" << endl;
    cout << "Score: " << gameScore << endl;
    return 0;
}