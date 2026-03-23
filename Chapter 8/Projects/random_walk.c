// Name: random_walk.c
// Purpose: To trace a random walk in a 10 * 10 matrix, labeling each step from 'A' to 'Z'
// Author: Ayush Raj

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 10

int main(void) {
    char matrix[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = '.';
        }
    }

    srand((unsigned)time(NULL));

    int row = 0, col = 0;
    char curr_step = 'B';
    matrix[row][col] = 'A';

    static const int move_y[] = {-1, 0, 1, 0};
    static const int move_x[] = {0, 1, 0, -1};

    while (curr_step <= 'Z') {
        if ((row - 1 < 0 || matrix[row - 1][col] != '.') && (col + 1 >= N || matrix[row][col + 1] != '.') && (row + 1 >= N || matrix[row + 1][col] != '.') && (col - 1 < 0 || matrix[row][col - 1] != '.'))
            break;

        while (1) {
            int rem = rand() % 4;

            // this is the novice way of checking out of bounds as well as if path for next step is available or not
            /*
            if (rem == 0) {
                if (row - 1 < 0 || matrix[row - 1][col] != '.')
                    continue;
                row -= 1;
            } else if (rem == 1) {
                if (col + 1 >= N || matrix[row][col + 1] != '.')
                    continue;
                col += 1;
            } else if (rem == 2) {
                if (row + 1 >= N || matrix[row + 1][col] != '.')
                    continue;
                row += 1;
            } else {
                if (col - 1 < 0 || matrix[row][col - 1] != '.')
                    continue;
                col -= 1;
            }
            */

            // this is the best way to check out of bounds as well as next step path availability, remember this pattern
            // the arrays here are just for demonstration, they are declared and initialized outside the outermost loop
            // int move_y[] = {-1, 0, 1, 0}; // Up, Right, Down, Left
            // int move_x[] = {0, 1, 0, -1};

            if (row + move_y[rem] < 0 || row + move_y[rem] >= N || col + move_x[rem] < 0 || col + move_x[rem] >= N || matrix[row + move_y[rem]][col + move_x[rem]] != '.')
                continue;
            row += move_y[rem];
            col += move_x[rem];

            matrix[row][col] = curr_step++;
            break;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}
