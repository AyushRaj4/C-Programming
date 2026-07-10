// Name: scrabble.c
// Purpose: To calculate the value of a word by summing the SCRABBLE value of its letters using arrays
// Author: Ayush Raj

#include <ctype.h>
#include <stdio.h>
#define N 26

int main(void) {
    int alphabets[N] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    char ch;
    int sum = 0;

    printf("Enter a word: ");
    while (1) {
        scanf("%c", &ch);

        if (ch == '\n')
            break;

        ch = toupper(ch);
        sum += alphabets[ch - 'A'];
    }

    printf("Scrabble value: %d\n", sum);

    return 0;
}
