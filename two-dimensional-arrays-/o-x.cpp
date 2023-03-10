#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

// Function to print the current state of the playing field
void printField(vector<vector<char>>& field) {
    cout << "Current field state:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(vector<vector<char>>& field, char symbol) {
    // Check rows for winning
    for (int i = 0; i < ROWS; i++) {
        if (field[i][0] == symbol && field[i][1] == symbol && field[i][2] == symbol) {
            return true;
        }
    }

    // Check columns for winning
    for (int j = 0; j < COLS; j++) {
        if (field[0][j] == symbol && field[1][j] == symbol && field[2][j] == symbol) {
            return true;
        }
    }

    // No winning combination found
    return false;
}

int main() {
    // Initializing playing field
    vector<vector<char>> field(ROWS, vector<char>(COLS, ' '));

    // Player 1 is X and player 2 is O
    char player1 = 'X';
    char player2 = 'O';

    // Initialize current player and move counter
    char currentPlayer = player1;
    int moveCounter = 0;

    // Game loop
    while (true) {
        // Print current field state
        printField(field);

        // Get player's move
        int row, col;
        cout << "Player " << currentPlayer << "'s move:" << endl;
        cout << "Enter row (1-3): ";
        cin >> row;
        cout << "Enter column (1-3): ";
        cin >> col;

        // Check if move is valid
        if (row < 1 || row > ROWS || col < 1 || col > COLS) {
            cout << "Invalid coordinates! Please try again." << endl;
            continue;
        }
        if (field[row-1][col-1] != ' ') {
            cout << "Cell already occupied! Please try again." << endl;
            continue;
        }

        // Update playing field and move counter
        field[row-1][col-1] = currentPlayer;
        moveCounter++;

        // Check for win or draw
        if (checkWin(field, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        if (moveCounter == ROWS*COLS) {
            cout << "Draw!" << endl;
            break;
        }

        // Switch current player
        if (currentPlayer == player1) {
            currentPlayer = player2;
        } else {
            currentPlayer = player1;
        }
    }

    return 0;
}
