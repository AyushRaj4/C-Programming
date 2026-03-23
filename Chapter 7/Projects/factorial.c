// Name: factorial.c
// Purpose: To calculate factorial of a positive integer and testing the largest value of n for which each type (integer as well as floating) can store correctly.
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    int num;
    long double fac = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
        fac *= i;

    printf("Factorial of %d: %Le\n", num, fac);

    return 0;
}
