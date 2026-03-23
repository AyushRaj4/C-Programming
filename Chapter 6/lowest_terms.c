// Name: lowest_terms.c
// Purpose: To calculate and display the lowest terms of a fraction
// Author: Aysh Raj

#include <stdio.h>

int main(void) {
    int num, den;

    printf("Enter 2 integers: ");
    scanf("%d /%d", &num, &den);

    int dividend = num, divisor = den, gcd;

    if (den != 0) {
        while (1) {
            int r = dividend % divisor;

            if (!r) {
                gcd = divisor;
                break;
            }

            dividend = divisor;
            divisor = r;
        }

        num /= gcd;
        den /= gcd;

        printf("In lowest terms: %d/%d\n", num, den);
    } else
        printf("0/0 is undefined!\n");

    return 0;
}
