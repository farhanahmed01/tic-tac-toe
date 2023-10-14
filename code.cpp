#include <iostream>
#include <vector>

const int BOARD_SIZE = 3;

// Function to display the Tic-Tac-Toe board
void displayBoard(const std::vector<std::vector<char> >& board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << board[i][j];
            if (j < BOARD_SIZE - 1) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i < BOARD_SIZE - 1) {
            std::cout << "---------" << std::endl;
        }
    }
    std::cout << std::endl;
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char> >& board, char player) {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char> >& board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char> > board(BOARD_SIZE, std::vector<char>(BOARD_SIZE, ' '));
    char currentPlayer = 'X';

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    while (true) {
        displayBoard(board);

        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE || board[row - 1][col - 1] != ' ') {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins! Congratulations!" << std::endl;
            break;
        } else if (checkDraw(board)) {
            displayBoard(board);
            std::cout << "It's a draw! The game ends in a tie." << std::endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
