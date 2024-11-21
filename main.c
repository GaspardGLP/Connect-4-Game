#include <stdio.h>

//Display Board Function
void display_board(char board[6][7]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            printf("  %c  ", board[i][j]);
            if (j < 6) {
                printf("|");
            }
        }
        printf("\n");
    }
    printf("\n");
}

//Check if board is full or not
int check_board(char board[6][7]) {
    for (int j = 0; j < 7; j++) {
        if (board[0][j] == '.') {
            return 0;
        }
    }
    return 1;
}

//Check if a colomn is full
int is_colomn_full(char board[6][7], int col) {
    return board[0][col] != '.';
}

// Add a token in a column
int drop_token(char board[6][7], int col, char player)
{
    for (int i = 5; i >= 0; i--) {
        if (board[i][col] == '.') {
            board[i][col] = player;
            return 1;
        }
    }
}

//Check lines, colognes and diagonals
int victory_handling(char board[6][7], char player) {
    //Check Lines
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == player && board[i][j + 1] == player &&
                board[i][j + 2] == player && board[i][j + 3] == player) {
                return 1;
                }
        }
    }

    //Check Colognes
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == player && board[i + 1][j] == player &&
                board[i + 2][j] == player && board[i + 3][j] == player) {
                return 1;
            }
        }
    }

    //Check diagonales (Bottom left to Top right)
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == player && board[i - 1][j + 1] == player &&
                board[i - 2][j + 2] == player && board[i - 3][j + 3] == player) {
                return 1;
            }
        }
    }

    //Check diagonles (Top left to bottom right)
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == player && board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
                return 1;
            }
        }
    }
    return 0;
}

// Game Function
void game() {
    char board[6][7];
    int col;
    char player = 'X';

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = '.';
        }
    }

    printf("Welcome to Connect-4 Game\n");
    display_board(board);

    while (1) {
        printf("Player %c, enter your move (column between 1 and 7):", player);
        scanf("%d",&col);

        if (col < 1 || col > 7) {
            printf("Invalid position, Please enter a colum between 1 and 7.\n");
            continue;
        }

        col--;

        if (is_colomn_full(board, col)) {
            printf("This colomn is already full! Try another column.\n");
            continue;
        }

        drop_token(board, col, player);
        display_board(board);

        if (victory_handling(board, player)) {
            printf("Congratulations! Player %c has won!\n", player);
            break;
        }

        if (check_board(board)) {
            printf("It's a draw!\n");
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    printf("Game Over. Thanks for playing!\n");
}

int main() {
    game();
    return 0;
}
