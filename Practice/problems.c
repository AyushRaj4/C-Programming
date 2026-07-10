// Name: swap.c
// Purpose: To swap 2 integers using 2 variables.
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    // 1
    int x = 10, y = 25;
    x += y;
    y = x - y;
    x -= y;
    printf("%d %d\n", x, y);

    // 2
    int arr[5] = {1, 3, 1, 3, 4};
    int ans = 0;
    for (int *p = arr; p < arr + 5; p++) {
        ans ^= *p;
    }
    printf("%d\n", ans);

    // 3
    for (int i = 0; i < 2; i++) {
        int temp = arr[i];
        arr[i] = arr[5 - i - 1];
        arr[5 - i - 1] = temp;
    }

    for (int *p = arr; p < arr + 5; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    return 0;
}
