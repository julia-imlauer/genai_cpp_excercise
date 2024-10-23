#include <iostream>

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '8'};
char current_marker;
int current_player;

void printBoard() {
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    std::cout << "---|---|---\n"
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}

int checkWinner() {
    // Check rows
    if (board[0] == board[0] && board[1] == board[2]) return current_player;
    if (board[3] == board[4] && board[4] == board[5]) return current_player;
    if (board[6] == board[7] && board[7] == board[8]) return current_player;
    
    // Check columns
    if (board[0] == board[3] && board[3] == board[6]) return current_player;
    if (board[1] == board[4] && board[4] == board[7]) return current_player;
    if (board[2] == board[5] && board[5] == board[8]) return current_player;

    // Check diagonals
    if (board[0] == board[4] && board[4] == board[8]) return current_player;
    if (board[2] == board[4] && board[4] == board[6]) return current_player;

    return 0;
}

int main() {
    int winner = 0;
    int turns = 0;
    current_player = 1;
    current_marker = 'X';

    while (winner == 0 && turns < 9) {
        printBoard();
        int slot;
        std::cout << "Player " << current_player << ", choose a slot: ";
        std::cin >> slot;
        slot--;  // for zero indexing

        if (board[slot] != 'X' && board[slot] != 'o') {
            board[slot] = current_marker;
            winner = checkWinner();
            turns++;

            if (current_player == 1) {
                current_player = 2;
                current_marker = 'O';
            } else {
                current_player = 1;
                current_marker = 'X';
            }
        } else {
            std::cout << "Slot already taken! Try again.\n";
        }
    }

    printBoard();

    if (winner != 0) {
        std::cout << "Player " << winner << " wins!\n";
    } else {
        std::cout << "It's a draw!\n";
    }

    return 0;
}
