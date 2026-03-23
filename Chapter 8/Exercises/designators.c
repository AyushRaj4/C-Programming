// Name: designators.c
// Purpose: Make the given multidimensional array as short as possible (Q7, CHapter 8)
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    const int segments[10][7] = {1, 1, 1, 1, 1, 1, 0, 0, 1, 1, [2][0] = 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, [8][0] = 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1};

    printf("Seven segment display for all digits from 0-9:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: ", i);
        for (int j = 0; j < 7; j++)
            printf("%d ", segments[i][j]);
        printf("\n");
    }

    return 0;
}
