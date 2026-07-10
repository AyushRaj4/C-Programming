// Name: random_walk.c
// Purpose: Updating Programming Project 9 fron Chapter 8 to include 2 functions.
// Author: Ayush Raj

#include <complex.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define N 10

void generate_random_walk(char walk[N][N]);
void print_array(char walk[N][N]);

int main(void) {
    char walk[N][N];

    generate_random_walk(walk);
    print_array(walk);

    return 0;
}

void generate_random_walk(char walk[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            walk[i][j] = '.';
    walk[0][0] = 'A';

    srand(time(NULL));

    int count = 25, i = 0, j = 0;
    char ch = 'B';
    _Bool flag = true;
    while (count > 0) {
        if ((i - 1 < 0 || walk[i - 1][j] != '.') && (j + 1 >= N || walk[i][j + 1] != '.') && (i + 1 >= N || walk[i + 1][j] != '.') && (j - 1 < 0 || walk[i][j - 1] != '.'))
            break;
        flag = true;
        int next = rand() % 4;

        if (!next && i - 1 >= 0 && walk[i - 1][j] == '.')
            i--;
        else if (next == 1 && j + 1 < N && walk[i][j + 1] == '.')
            j++;
        else if (next == 2 && i + 1 < N && walk[i + 1][j] == '.')
            i++;
        else if (next == 3 && j - 1 >= 0 && walk[i][j - 1] == '.')
            j--;
        else
            flag = false;

        if (flag) {
            walk[i][j] = ch++;
            count--;
        }
    }
}

void print_array(char walk[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", walk[i][j]);
        }
        printf("\n");
    }
}
