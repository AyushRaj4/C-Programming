// Name: two_largest.c
// Purpose: To find the largest and 2nd largest elements in an array using pointer arithmetic.
// Author: Ayush Raj

#include <limits.h>
#include <stdio.h>

void find_two_largest(const int *a, int n, int *largest, int *second_largest);

int main(void) {
    int a[] = {1, 2, 3, 4, 55};
    int l, sl;
    find_two_largest(a, 5, &l, &sl);
    printf("Largest: %d, second largest: %d\n", l, sl);

    return 0;
}

void find_two_largest(const int *a, int n, int *largest, int *second_largest) {
    *largest = *a;
    for (int i = 1; i < n; i++) {
        if (*(a + i) > *largest) {
            *largest = *(a + i);
        }
    }

    *second_largest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (*(a + i) < *largest && *(a + i) > *second_largest) {
            *second_largest = *(a + i);
        }
    }
}
