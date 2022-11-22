/*
 Name: Nikita Dubinin
 Class: CPCS 121, Fall 2022
 Date: November 20, 2022
 Programming Assignment: PA8
 Description: Adventure Game
 Notes: -
*/

#include "header.h"

const int BOARD_SIZE = 10;
/*
* ASCII symbols: https://theasciicode.com.ar/extended-ascii-code/block-graphic-
character-ascii-code-219.html
* Note: Extended ASCII characters only work on Windows   unicode must be used on 😥
Linux but then the
* characters will not work on Windows. 😭
*/
void displayBoard(char board[][BOARD_SIZE], int rows, int cols);
char generateTile(void);
void initBoard(char board[][BOARD_SIZE], int rows, int cols);
char menuPrompt(void);
int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char choice = '\0';
    int gameScore = 0;
//seed random number generator
//initialize our game board with randomly generated tiles
    initBoard(board, BOARD_SIZE, BOARD_SIZE);
    do
    {
        displayBoard(board, BOARD_SIZE, BOARD_SIZE);
        choice = menuPrompt();
        switch (choice)
        {
            case 'w':
//TODO: move up
                break;
            case 's':
//TODO: move down
                break;
            case 'a':
//TODO: move left
                break;
            case 'd':
//TODO: move right
                break;
            case 'i':
//TODO: display player inventory
                break;
            case 'f':
//TODO: search a tile
                break;
            case 'c':
//TODO: clear a tile
                break;
            default:
                break;
        }
    } while (choice != 'q');
//DISPLAY GAME RESULTS
    cout << "Game Over!" << endl;
    cout << "Score: " << gameScore << endl;
    return 0;
}
/*
* TODO: function comment block and implement function definition
* TODO: replace or modify to include player current position
*/
void displayBoard(char board[][BOARD_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}
/*
* TODO: function comment block and implement function definition
*/
char generateTile(void)
{
    return '~';
}
/*
* TODO: function comment block and implement function definition
*/
void initBoard(char board[][BOARD_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = generateTile();
        }
    }
}
/*
* TODO: function comment block and implement function definition
*/
char menuPrompt(void) {
    char choice = '\0';
    cout << "Pick a direction to move in:" << endl;
    cout << "Directions: w (up), s (down), a (left), d (right) " << endl;
    cout << "Actions: f (search tile), c (clear tile)" << endl;
    cout << "Options: i (inventory), q (quit)" << endl;
    cin >> choice;
    return choice;
}