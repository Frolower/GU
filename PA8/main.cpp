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
    int numCells = BOARD_SIZE * BOARD_SIZE;
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
        currTile = board[currRow][currCol];
        displayScore(gameScore);
        displayPlayerStats(playerStats);
        if (displayInventory) {
            displayInventoryStats(playerCurrentInventoryStats, inventoryDescription, numPlayerItems);
        }
        displayBoardPosition(board, BOARD_SIZE, BOARD_SIZE, currRow, currCol);
        displayCurrTile(currTile , TILE_NAME);
        menuPrompt();
        choice = getValidMovement(currRow , currCol);
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
                if (!displayInventory) {
                    displayInventory = true;
                } else {
                    displayInventory = false;
                }
                break;
            case 'f':
                if (board[currRow][currCol] != ' ') {
                    gameScore += 5;
                    if (rand() % 2 + 1 == 1) {
                        if (fightMonster(playerStats)) {
                            gameScore++;
                            wipeInventory(numPlayerItems);
                        } else {
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
                    pressToContinue();
                } else {
                    cout << "You already cleared this place, choose another action" << endl;
                    pressToContinue();
                }
                break;
            case 'c':
                if (board[currRow][currCol] != ' ') {
                    gameScore++;
                    if (rand() % 10 + 1 == 1) {
                        if (fightMonster(playerStats)) {
                            gameScore++;
                            wipeInventory(numPlayerItems);
                        } else {
                            cout << "You died!" << endl;
                            choice = 'q';
                        }
                    }
                    clearTile(board, currRow, currCol, CLEAR_VALUE);
                    currTile = CLEAR_VALUE;
                    numCells--;
                } else {
                    cout << "You already cleared this place, choose another action" << endl;
                    pressToContinue();
                }
                break;
            default:
                break;
        }
        cls();
        if (numCells < 1) {
            cout << "You won!" << endl;
            choice = 'q';
        }
    } while (choice != 'q');
//DISPLAY GAME RESULTS
    cout << "Game Over!" << endl;
    cout << "Score: " << gameScore << endl;
    return 0;
}