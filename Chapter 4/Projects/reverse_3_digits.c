// Name: reverse_3_digits.c
// Purpose: To print a 3 digit number with its digits reversed 
// Author: Ayush Raj

#include <stdio.h>

int main (void) {
    int num;

    printf("Enter a 2 digit number: ");
    scanf("%3d", &num);

    int ones_place = num % 10, tens_place = num / 10 % 10, hundreds_place = num / 100;
    printf("The reversal is: %3d\n", ones_place * 100 + tens_place * 10 + hundreds_place);

    return 0;
}
