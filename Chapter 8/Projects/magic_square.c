// Name: magic_square.c
// Purpose: To create a magic square of a specified size. (To know about magic square see project 17)
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    printf("This program creates a magic square of a specified size.\nThe size must be an odd number between 1 and 99.\n");
    int n;
    printf("Enter size of magic square: ");
    scanf("%d", &n);
    printf("\n");

    // variable sized arrays and objects cannot be initialized
    int magic_sq[n][n] = {};
    int curr = 2, i = 0, j = n / 2;
    magic_sq[i][j] = 1;
    while (curr <= n * n) {
        int temp_i = i, temp_j = j;
        if (i - 1 < 0)
            temp_i = n - 1;
        else
            temp_i = i - 1;

        if (j + 1 >= n)
            temp_j = 0;
        else
            temp_j = j + 1;

        if (magic_sq[temp_i][temp_j])
            i += 1;

        else {
            i = temp_i;
            j = temp_j;
        }

        magic_sq[i][j] = curr++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%5d", magic_sq[i][j]);
        printf("\n");
    }

    return 0;
}
