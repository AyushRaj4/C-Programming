// Name: maxmin.c
// Purpose: Finds the largest and smallest elements in an array.
// Author: Ayush Raj

#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void) {
    int b[N], big, small;
    printf("Enter %d numbers: ", N);
    for (int *p = b; p < b + N; p++)
        scanf("%d", p);

    max_min(b, N, &big, &small);
    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
}

void max_min(int a[], int n, int *max, int *min) {
    *max = *min = a[0];
    for (int *i = a + 1; i < a + n; i++) {
        if (*i > *max) {
            *max = *i;
        } else if (*i < *min) {
            *min = *i;
        }
    }
}
