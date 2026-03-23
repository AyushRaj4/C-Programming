// Name: reverse_2_digits.c
// Purpose: To print a 2 digit number with its digits reversed 
// Author: Ayush Raj

#include <stdio.h>

int main (void) {
    int num;

    printf("Enter a 2 digit number: ");
    scanf("%2d", &num);

    int ones_place = num % 10, tens_place = num / 10;
    printf("The reversal is: %2d\n", ones_place * 10 + tens_place);

    return 0;
}
