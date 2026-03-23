// Name: kth_digit.c
// Purpose: To find the kth digit from right in a number
// Author: Ayush Raj

#include <stdio.h>

int kth_digit_right(int num, int k, int c);

int main(void) {
    int num, k;

    printf("Enter a number and position from right: ");
    scanf("%d%d", &num, &k);

    printf("Kth digit from right = %d\n", kth_digit_right(num < 0 ? num * -1 : num, k, 1));

    return 0;
}

int kth_digit_right(int n, int k, int c) {
    if (n == 0)
        return 0;
    if (c == k)
        return n % 10;

    return kth_digit_right(n / 10, k, c + 1);
}
