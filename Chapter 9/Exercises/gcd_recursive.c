// Name: gcd_recursive.c
// Purpose: To write a recursive GCD function.
// Author: Ayush Raj

#include <stdio.h>

int gcd_rec(int m, int n);

int main(void) {
    int m, n;

    printf("Enter 2 numbers: ");
    scanf("%d%d", &m, &n);

    printf("GCD = %d\n", gcd_rec(m, n));

    return 0;
}

int gcd_rec(int m, int n) {
    if (n == 0)
        return m;

    return gcd_rec(n, m % n);
}
