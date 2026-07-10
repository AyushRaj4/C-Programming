// Name: vowels.c
// Purpose: To vowels the no. of vowels in a sentence
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    short int vowels = 0;
    char alphabet;

    printf("Enter a sentence: ");
    while (1) {
        scanf("%c", &alphabet);

        if (alphabet == '.')
            break;

        if (alphabet == 'a' || alphabet == 'e' || alphabet == 'i' || alphabet == 'o' || alphabet == 'u')
            vowels++;
    }

    printf("Your sentence contains %d vowels.\n", vowels);

    return 0;
}
