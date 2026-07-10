// Name: checkers.c
// Purpose: To implement a checkers board using characters and arrays in C
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    /*
    // This method is correct but we still ahve to initialize the 1st row, what if we want to initialize each element in the array in the loop dynamically only?
    char checker_board[8][8] = {'B', 'R', 'B', 'R', 'B', 'R', 'B', 'R'};

    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (checker_board[i - 1][j] == 'B')
                checker_board[i][j] = 'R';
            else
                checker_board[i][j] = 'B';
        }
    }
    */

    char checker_board[8][8];

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2)
                checker_board[i][j] = 'R';
            else
                checker_board[i][j] = 'B';
        }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            printf("%c ", checker_board[i][j]);
        printf("\n");
    }

    return 0;
}
