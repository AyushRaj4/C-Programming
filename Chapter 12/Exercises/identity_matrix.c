// Name: identity_matrix.c
// Purpose: To initialize an identity matrix in a single loop using a pointer.
// Author: Ayush Raj

#include <stdio.h>

void init_identity_matrix(int *a, int n);
void print_matrix(int n, int a[][n]);

int main(void) {
    int n;
    printf("Enter dimension of identity matrix: ");
    scanf("%d", &n);

    if (n > 0) {
        int a[n][n];
        init_identity_matrix(a[0], n); // a is a pointer to the 1st row of matrix, type is (*)int[n], a[0] is a pointer to the 1st element of 1st row of matrix, type is int*
        print_matrix(n, a);
    }

    return 0;
}

void init_identity_matrix(int *a, int n) {
    int *p_start = a;
    int total_elements = n * n;

    for (int i = 0; i < total_elements; i++) {
        // Pointer arithmetic to access the i-th element from the start
        *(p_start + i) = i % (n + 1) == 0 ? 1 : 0;
    }
}

void print_matrix(int n, int a[][n]) {
    int *p_start = a[0], total_elements = n * n;
    for (int i = 0; i < total_elements; i++) {
        printf("%d%c", *(p_start + i), (i + 1) % n == 0 ? '\n' : ' ');
    }
    printf("\n");
}
