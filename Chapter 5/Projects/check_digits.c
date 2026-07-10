// Name: check_digits.c
// Purpose: To calculate the no. of digits in a given number(max 4 digits)
// Author: Ayush Raj

#include <stdio.h>

int main (void) {
    int num;

    printf("Enter a number (<= 4 digits): ");
    scanf("%4d", &num);

    printf("The number %d has ", num);
    if (num % 10 == num) printf("1 digit.");
    else if (num % 100 == num) printf("2 digits.");
    else if (num % 1000 == num) printf("3 digits.");
    else printf("4 digits.\n");

    return 0;
}
