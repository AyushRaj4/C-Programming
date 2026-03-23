// Name: identity_matrix.c
// Purpose: To initialize an identity matrix in a single loop using a pointer.
// Author: Ayush Raj

#include <stdio.h>

void init_identity_matrix(int *a, int n);
void print_matrix(int *a, int n);

int main(void) {
    int n;
    printf("Enter dimension of identity matrix: ");
    scanf("%d", &n);

    int a[n][n];
    init_identity_matrix(a[0], n); // a is a pointer to the 1st row of matrix, type is (*)int[n], a[0] is a pointer to the 1st element of 1st row of matrix, type is int*
    print_matrix(a[0], n);

    return 0;
}

void init_identity_matrix(int *a, int n) {
    int c = 0;
    for (int *p = a; p < a + n * n; p++) {
        if (p == a || c == n) {
            *p = 1;
            c = 0;
            continue;
        }
        c++;
    }
}

void print_matrix(int *a, int n) {
    int c = 0;
    for (int *p = &a[0]; p < a + n * n; p++) {
        if (c == n) {
            printf("%d\n", *p);
            c = 1;
        } else {
            printf("%d ", *p);
            c++;
        }
    }
}
