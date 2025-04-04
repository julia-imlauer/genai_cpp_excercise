#include <stdio.h>

void welcome_to_the_matrix() {
    printf("Welcome to the 2D Hypergrid Battle Simulator!\n");
    printf("Choose your destiny wisely. Only ONE will emerge victorious...\n\n");
}

char sacredTable[9] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'V'};

void showTheGrid() {
    printf(" Behold! The grid of your destiny:\n");
    printf(" %c | %c | %c\n", sacredTable[0], sacredTable[1], sacredTable[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", sacredTable[3], sacredTable[4], sacredTable[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", sacredTable[6], sacredTable[7], sacredTable[8]);
    printf("The fate of these symbols is in your hands...\n");
}

int consultTheOracles() {
    if (sacredTable[0] == sacredTable[1] && sacredTable[1] == sacredTable[2]) return 1;
    if (sacredTable[3] == sacredTable[4] && sacredTable[4] == sacredTable[5]) return 1;
    if (sacredTable[6] == sacredTable[7] && sacredTable[7] == sacredTable[8]) return 1;
    if (sacredTable[0] == sacredTable[3] && sacredTable[3] == sacredTable[6]) return 1;
    if (sacredTable[1] == sacredTable[4] && sacredTable[4] == sacredTable[7]) return 1;
    if (sacredTable[2] == sacredTable[5] && sacredTable[5] == sacredTable[8]) return 1;
    if (sacredTable[0] == sacredTable[4] && sacredTable[4] == sacredTable[8]) return 1;
    if (sacredTable[2] == sacredTable[4] && sacredTable[4] == sacredTable[6]) return 1;
    return 0;
}

int main() {
    int unknownVariable1 = 0;
    int turnCounter = 0;
    char currentPlayer = 'x';

    welcome_to_the_matrix();
    showTheGrid();

    while (unknownVariable1 == 0 && turnCounter < 9) {
        int playerDecision;

        printf("Player %c, select your mystic symbol location (1-9, but you already knew that): ", currentPlayer);
        scanf("%d", &playerDecision);
        playerDecision--;

        if (sacredTable[playerDecision] != 'X' && sacredTable[playerDecision] != 'o') {
            sacredTable[playerDecision] = currentPlayer;
            unknownVariable1 = consultTheOracles();
            turnCounter++;

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'x';
        } else {
            printf("Error 404: Position already occupied. Attempting recovery...\n");
        }

        showTheGrid();
    }

    if (unknownVariable1 == 0) {
        printf("It is a draw. The universe remains in balance... for now.\n");
    } else {
        printf("Player %c has achieved ultimate dominance. The world trembles.\n", currentPlayer == 'X' ? 'O' : 'X');
    }

    return 0;
}
