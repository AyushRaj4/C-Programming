// Name: reverse_3_digits_v2.c
// Purpose: To print a 3 digit number with its digits reversed without using arithmetic operators
// Author: Ayush Raj

#include <stdio.h>

int main (void) {
    int a, b, c;

    printf("Enter a 3-digit number: ");
    scanf("%1d%1d%1d", &a, &b, &c);

    printf("The reversal is: %d%d%d", c, b, a);

    return 0;
}
