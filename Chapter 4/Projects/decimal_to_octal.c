// Name: decimal_to_octal.c
// Purpose: To convert decimal number to octal
// Author: Ayush Raj

#include <stdio.h>

int main (void) {
    int num;

    printf("Enter a number b/w 0 and 32767: ");
    scanf("%5d", &num);

    int d1, d2, d3, d4, d5;
    d1 = num % 8;
    num /= 8;
    d2 = num % 8;
    num /= 8;
    d3 = num % 8;
    num /= 8;
    d4 = num % 8;
    num /= 8;
    d5 = num % 8;
    num /= 8;

    printf("In octal, your number is: %d%d%d%d%d", d5, d4, d3, d2, d1);

    return 0;
}
