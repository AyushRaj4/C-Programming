// Name: reverse_sentence.c
// Purpose: To reverse the words in a sentence.
// Author: Ayush Raj

#include <stdio.h>
#define N 1000

// this program will run fine as long as there is a single punctuation like '.', '?' etc. at the end.
int main(void) {
    char sentence[N];
    int len = 0;

    printf("Enter a sentence: ");
    while ((sentence[len++] = getchar()) != '\n' && len < N)
        ;
    sentence[len] = '\0';

    printf("Reversal of sentence: ");
    for (int i = len - 3; i >= 0; i--) {
        if (sentence[i] == ' ' || i == 0) {
            int j;
            if (i == 0)
                j = i;
            else
                j = i + 1;
            while (sentence[j] != ' ' && j != len - 2) {
                printf("%c", sentence[j]);
                j++;
            }
            if (i != 0)
                printf(" ");
            else
                printf("%c", sentence[len - 2]);
        }
    }
    printf("\n");

    return 0;
}
