#include <iostream>
#include <vector>
#include <cstdlib> // For system("cls")

using namespace std;

// Function to print the Tic Tac Toe board
void printBoard(const vector<vector<char>>& board) {
    system("cls"); // Clear the console screen
    cout << "-------------" << endl;
    for (const auto& row : board) {
        cout << "| ";
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize empty Tic Tac Toe board
    char currentPlayer = 'X';
    int row, col;
    bool win = false;
    int moves = 0;

    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "Player 1: X, Player 2: O" << endl;

    // Game loop
    while (!win && moves < 9) {
        printBoard(board);

        cout << "Player " << currentPlayer << ", enter row and column (1-3): ";
        cin >> row >> col;

        // Adjust indices to match array indexing (0-based)
        row--;
        col--;

        // Check if cell is empty and within bounds
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            moves++;

            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                win = true;
            }
            else {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        else {
            cout << "Invalid move! Please try again." << endl;
        }
    }

    if (!win) {
        printBoard(board); // Print the final board
        cout << "It's a draw!" << endl;
    }

    return 0;
}
