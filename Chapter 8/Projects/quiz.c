// Name: quiz.c
// Purpose: To print the row and column sums of the input matrix.
// Author: Ayush Raj

#include <stdio.h>
#define N 5

int main(void) {
    int matrix[N][N];
    int row_sums[N] = {}, col_sums[N] = {};
    int quiz_high_low[N][2] = {{999}, {999}, {999}, {999}, {999}};

    for (int i = 0; i < N; i++) {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
            row_sums[i] += matrix[i][j];
            col_sums[j] += matrix[i][j];

            if (matrix[i][j] < quiz_high_low[j][0])
                quiz_high_low[j][0] = matrix[i][j];

            if (matrix[i][j] > quiz_high_low[j][1])
                quiz_high_low[j][1] = matrix[i][j];
        }
    }
    printf("\n");

    printf("Students' total and average scores:\n");
    printf("Student\t\tTotal\tAvg\n");
    for (int i = 0; i < N; i++)
        printf("Student%d\t%3d\t%2.1f\n", i + 1, row_sums[i], row_sums[i] / 5.0);
    printf("\n");

    printf("Quiz average, high and low scores:\n");
    printf("Quiz\tAvg\tHigh\tLow\n");
    for (int i = 0; i < N; i++)
        printf("Quiz%d\t%2.1f\t%3d\t%2d\n", i + 1, col_sums[i] / 5.0, quiz_high_low[i][1], quiz_high_low[i][0]);
    printf("\n");

    return 0;
}
