// Name: anagrams.c
// Purpose: To check if 2 given words are anagrams or not.
// Author: Ayush Raj

#include <ctype.h>
#include <stdio.h>
#define N 100
#define LETTERS 26

int main(void) {
    char word1[N], word2[N];
    int alphabets[LETTERS] = {};
    int len1 = 0, len2 = 0;

    printf("Enter first word: ");
    while ((word1[len1++] = getchar()) != '\n' && len1 < N)
        ;
    word1[len1] = '\0';

    printf("Enter second word: ");
    while ((word2[len2++] = getchar()) != '\n' && len2 < N)
        ;
    word2[len2] = '\0';

    if (len1 != len2) {
        printf("The words are not anagrams.\n");
        return 0;
    }

    for (int i = 0; i < len1 - 1; i++) {
        if (isalpha(word1[i])) {
            if (word1[i] <= 90)
                alphabets[word1[i] - 'A']++;
            else
                alphabets[word1[i] - 'a']++;
        }
    }

    for (int i = 0; i < len2 - 1; i++) {
        if (isalpha(word2[i])) {
            if (word2[i] <= 90)
                alphabets[word2[i] - 'A']--;
            else
                alphabets[word2[i] - 'a']--;
        }
    }

    int i;
    for (i = 0; i < LETTERS; i++)
        if (alphabets[i])
            break;

    if (i == LETTERS)
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");

    return 0;
}
