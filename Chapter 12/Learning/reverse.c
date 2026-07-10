// Name: reverse.c
// Purpose: To revere an array using pointers.
// Author: Ayush Raj

#include <stdio.h>

#define N 10

int main(void) {
    int a[N];
    printf("Enter array elements: ");

    for (int *p = a; p < a + N; p++) {
        scanf("%d", p);
    }

    for (int i = 0; i < N / 2; i++) {
        int temp = *(a + i);
        *(a + i) = *(a + N - i - 1);
        *(a + N - i - 1) = temp;
    }

    for (int *p = a; p < a + N; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    return 0;
}
