#include <stdio.h>

char board[3][3]; // The Tic-Tac-Toe board

void initBoard() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

char checkWin() {
    int i, j;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
    }

    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
            return board[0][j];
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return ' ';
        }
    }
    return 'D';
}

int main() {
    int row, col, player = 1;
    char mark;

    initBoard(); 

    printf("Welcome to Tic-Tac-Toe!\n");

    do {
        displayBoard(); 

        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d, enter row (1-3) and column (1-3) to place your %c: ", player, mark);
        scanf("%d %d", &row, &col);

        row--;
        col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = mark;
            char winner = checkWin();
            if (winner != ' ') {
                displayBoard();
                if (winner == 'D')
                    printf("It's a draw!\n");
                else
                    printf("Player %d wins!\n", player);
                break;
            }
            player = (player == 1) ? 2 : 1; 
        } else {
            printf("Invalid move! Please try again.\n");
        }
    } while (1); 

    return 0;
}

