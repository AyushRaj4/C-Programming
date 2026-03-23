// Name: row_col_sums.c
// Purpose: To print the row and column sums of the input matrix.
// Author: Ayush Raj

#include <stdio.h>
#define N 5

int main(void) {
    int matrix[N][N];
    int row_sums[N] = {}, col_sums[N] = {};

    for (int i = 0; i < N; i++) {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
            row_sums[i] += matrix[i][j];
            col_sums[j] += matrix[i][j];
        }
    }
    printf("\n");

    printf("Row totals: ");
    for (int i = 0; i < N; i++)
        printf("%d ", row_sums[i]);
    printf("\n");

    printf("Column totals: ");
    for (int i = 0; i < N; i++)
        printf("%d ", col_sums[i]);
    printf("\n");

    return 0;
}
