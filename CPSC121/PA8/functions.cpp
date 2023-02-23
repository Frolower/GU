#include "header.h"

//void displayBoard(char board[][BOARD_SIZE], int rows, int cols) { //i don't know why do i need this
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cout << board[i][j];
//        }
//        cout << endl;
//    }
//}

char generateTile(int numTileTypes) {
    return TILE_TYPES[rand() % numTileTypes]; //return tile
}

void initBoard(char board[][BOARD_SIZE], int rows, int cols , int numTileTypes) { //creating a board
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = generateTile(numTileTypes);
        }
    }
}

void menuPrompt(void) {// pronting menu
    cout << "Pick a direction to move in:" << endl;
    cout << "Directions: w (up), s (down), a (left), d (right) " << endl;
    cout << "Actions: f (search tile), c (clear tile)" << endl;
    cout << "Options: i (inventory), q (quit)" << endl;
}

void displayBoardPosition(char board[][BOARD_SIZE], int rows, int cols, int currRow, int currCol) {//displaying board with player icon
    char playerIcon = '@';
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == currRow && j == currCol) {//if current place show player icon
                cout << playerIcon;
            } else {
                cout << board[i][j];
            }
            cout << "  ";
        }
        cout << endl;
    }
}

void displayPlayerStats(int playerStats[3]) {//display stats
    cout << "Health: " << playerStats[0] << " Attack: " << playerStats[1] << " Defence: " << playerStats[2] << endl;
}

void displayInventoryStats(int playerCurrentInventoryStats[][2], const string inventoryDescription[], int numItems) {//display inventory
    if (numItems > 0) {
        cout << setw(15) << left  << "Item Name" << setw(15) << right << "Item Power" << endl;
        for (int i = 0; i < numItems; i++) {
            cout << setw(15) << left  << inventoryDescription[i] << setw(15) << right << playerCurrentInventoryStats[i][0] << endl;
        }
    } else {//if no items
        cout << "You don't have any items." << endl;
    }
}

void displayScore(int score) {// display score
    cout << "Current Score: " << score << endl;
}

void updateStats(int playerStats[3], int playerCurrentInventoryStats[][2], int numItems) {//if new item
    if (playerCurrentInventoryStats[numItems - 1][1] == 0) {//if defence item
        playerStats[2] += playerCurrentInventoryStats[numItems - 1][0];
//        if (playerStats[2] > 90) {//doesnt work with required mechanics
//            playerStats[2] = 90;
//            cout << "You can't carry more armour, your armour is now 90 units!" << endl;
//        }
    } else {//if attack item
        playerStats[1] += playerCurrentInventoryStats[numItems - 1][0];
    }
}

bool fightMonster(int playerStats[3]) {
    int monsterHealth = 0;
    int monsterAttack = 0;
    bool isPlayer = false;//to call player or monster attack
    bool isEnd = false;
    generateMonsterStats(monsterHealth , monsterAttack);//monster stats by reference
    cout << endl << "PMC operator found you! Prepare to fight!" << endl;
    while(!isEnd) {
        isPlayer = true;
        cout << "Your stats: ";
        displayPlayerStats(playerStats);
        cout << endl;
        cout << "Enemy stats: Health: " << monsterHealth << " Attack: " << monsterAttack << endl << endl;
        attack(isPlayer, monsterAttack , monsterHealth , playerStats);
        isPlayer = false;
        if (monsterHealth > 1) {
            attack(isPlayer, monsterAttack , monsterHealth , playerStats);
        } else {
            cout << "You won!" << endl;
            return true;
        }
        if (playerStats[0] < 1) {
            return false;
        }
    }

}

void wipeInventory (int& numPlayerItems) {//set num items to 0 => no items
    numPlayerItems = 0;
}

void clearTile (char board[][BOARD_SIZE], int currRow, int currCol , const char clearTile) { //set tile to ' ', maybe i should add numCells-- here
    board[currRow][currCol] = clearTile;
}

char getValidMovement (int row , int column) {//are we still on the board or this is a correct action // interesting fact% you can set a list of moves like ddssdifdc and it will be correct
    char choice = '\n';
    bool isValid = false;
    cin >> choice;
    while(!isValid) {
        if (choice == 'w' && row - 1 >= 0) {
            return choice;
        } else if (choice == 's' && row + 1 < 10) {
            return choice;
        } else if (choice == 'a' && column - 1 >= 0) {
            return choice;
        } else if (choice == 'd' && column + 1 < 10) {
            return choice;
        } else if (choice == 'i' || choice == 'f' || choice == 'c' || choice == 'q') {
            return choice;
        } else {//if invalid
            cout << "Unavailable action, enter another action:" << endl;
            cin >> choice;
            isValid = false;
        }
    }
}

void displayCurrTile (char tile , const string tileName[]) {// looking for a tile
    cout << "Current tile is: " << tile << " it's ";
    switch (tile) {
        case '!':
            cout << tileName[0] << endl;
            break;
        case '=':
            cout << tileName[1] << endl;
            break;
        case '+':
            cout << tileName[2] << endl;
            break;
        case '#':
            cout << tileName[3] << endl;
            break;
        default:
            cout << "clear tile" << endl;
            break;
    }
}

int getRandomLootId (void) {//loot id
    return rand()%10;
}

void generateMonsterStats(int& monsterHealth , int& monsterAttack) {//monster stats
    monsterHealth = rand() % 100 + 51;
    monsterAttack = rand() % 50 + 31;
}

void pressToContinue (void) {//working correct only in certain places in code for some reason, i need another function with 1 getchar()
    cout << endl << "Press enter to continue";
    getchar();
    getchar();
    cout << endl;
}

void attack (bool isPlayer, int monsterAttack , int& monsterHealth , int playerStats[]) {//battle function
    if (isPlayer) {//players attack
        monsterHealth -= playerStats[1];
        cout << "You hit PMC operator with " << playerStats[1] << " power" << endl;
    } else {//monster attack
        if (playerStats[2] - monsterAttack < 0) {
            playerStats[0] -= abs(playerStats[2] - monsterAttack);
            cout << " PMC operator hits you with " << abs(playerStats[2] - monsterAttack) << " power" << endl;
        } else {//if armour > monster attack
            cout << "PMC operator can't hit you through your armour" << endl;
        }
    }
}

void cls (void) {//clear console, doesn't work on mac os
    system("cls||clear");
    return;
}

void searchForLoot (int playerCurrentInventoryStats[][2] , string inventoryDescription[] , int& numPlayerItems , const string LOOT_LIST_DESCRIPTIONS[] , const int LOOT_LIST_VALUES[][2]) {// looking for a loot
    if (numPlayerItems <= 10) {
        int itemId = getRandomLootId();
        playerCurrentInventoryStats[numPlayerItems][0] = LOOT_LIST_VALUES[itemId][0];//power
        playerCurrentInventoryStats[numPlayerItems][1] = LOOT_LIST_VALUES[itemId][1];//is defence
        inventoryDescription[numPlayerItems] = LOOT_LIST_DESCRIPTIONS[itemId];//name
        cout << "You found " << inventoryDescription[numPlayerItems] << " it has " << playerCurrentInventoryStats[numPlayerItems][0] << " units of power" << endl;
        numPlayerItems++;
    } else {
        cout << "Your inventory is full." << endl;
    }
}