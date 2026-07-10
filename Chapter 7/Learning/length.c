// Name: length.c
// Purpose: To calculate the length of an input message
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    int length = 0;

    printf("Enter a message: ");
    while (getchar() != '\n') // used idiom to shorten the program
        length++;

    printf("Your message was %d character(s) long.\n", length);

    return 0;
}
