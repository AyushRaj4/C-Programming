// Name: magic_square.c
// Purpose: To include 2 function is the magic square program from chapter 8.
// Author: Ayush Raj

#include <stdio.h>
#include <stdbool.h>

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int main(void) {
    // In professional scenario handle the seg faults when user give even nos., going out of bounds may lead to undefined behavior
    // In this program I did not get any error even if I am going out of bounds because the memory being accessed (out of bounds) is within the stack where my program is located, I am not violating or accessing other private memory, so OS doesn't complain, but this is also completely unsafe as I corrupted my own data.
    printf("This program creates a magic square of a specified size.\nThe size must be an odd number between 1 and 99.\n");

    int n;
    printf("Enter magic square size: ");
    scanf("%d", &n);

    int magic_square[n][n] = {}; // VLAs cannot be intitalized as their size is determined at runtime not compile time, it's also better to avoid using {}
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magic_square[i][j] = 0;

    create_magic_square(n, magic_square);
    printf("\n");
    print_magic_square(n, magic_square);
    printf("\n");

    return 0;
}

void create_magic_square(int n, int ms[n][n]) {
    int c = 1, i = 0, j = n / 2;
    ms[i][j] = c++;

    while (c <= n * n) {
        int i2 = i, j2 = j;

        if (i - 1 >= 0)
            i--;
        else
            i = n - 1;
        if (j + 1 < n)
            j++;
        else
            j = 0;

        if (ms[i][j]) {
            i = i2 + 1;
            j = j2;
        }
        ms[i][j] = c++;
    }
}

void print_magic_square(int n, int ms[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%5d", ms[i][j]);
        printf("\n");
    }
}
