// Name: gcd.c
// Purpose: To write a function for finding gcd of 2 numbers
// Author: Ayuhs Raj

#include <stdio.h>

int gcd(int m, int n);

int main(void) {
    int m, n;

    printf("Enter 2 numbers: ");
    scanf("%d%d", &m, &n);

    int ans = gcd(m, n);
    printf("GCD = %d\n", ans);

    return 0;
}

int gcd(int m, int n) {
    for (;;) {
        int r = m % n;
        if (!r)
            return n;
        m = n;
        n = r;
    }
    // return 1;  //no warning
}
