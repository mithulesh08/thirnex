# Mini Game Project – Tic Tac Toe in C++

## Objective

Create a console-based Tic Tac Toe game in C++ that demonstrates programming concepts such as loops, arrays, functions, and conditional statements.

---

# Features Implemented

* Two-player Tic Tac Toe game
* Dynamic board display after every move
* Win detection
* Draw detection
* Replay option
* Menu-driven gameplay
* Uses arrays, loops, and condition statements

---

# C++ Program

```cpp
#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Function to initialize board
void initializeBoard() {
    char position = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = position;
            position++;
        }
    }

    currentPlayer = 'X';
}

// Function to display board
void displayBoard() {
    cout << "\n";

    for (int i = 0; i < 3; i++) {
        cout << " ";

        for (int j = 0; j < 3; j++) {
            cout << board[i][j];

            if (j < 2)
                cout << " | ";
        }

        cout << endl;

        if (i < 2)
            cout << "-----------" << endl;
    }

    cout << "\n";
}

// Function to place move
bool makeMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9)
        return false;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }

    return false;
}

// Function to check winner
bool checkWinner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;
    }

    // Check diagonals
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

// Function to check draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

// Function to switch player
void switchPlayer() {
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

// Main game function
void playGame() {
    int choice;

    initializeBoard();

    while (true) {
        displayBoard();

        cout << "Player " << currentPlayer
             << ", enter your move (1-9): ";
        cin >> choice;

        if (!makeMove(choice)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        if (checkWinner()) {
            displayBoard();
            cout << "Player " << currentPlayer
                 << " wins!\n";
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "The game is a draw!\n";
            break;
        }

        switchPlayer();
    }
}

// Main Function
int main() {
    char replay;

    do {
        cout << "\n===== TIC TAC TOE GAME =====\n";

        playGame();

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> replay;

    } while (replay == 'Y' || replay == 'y');

    cout << "Thanks for playing!\n";

    return 0;
}
```

---
