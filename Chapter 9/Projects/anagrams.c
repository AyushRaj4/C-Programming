// Name: anagrams.c
// Purpose: To check whether 2 words are anagrams or not.
// Author: Ayush Raj

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define N 100
#define ALPHA 26

void read_word(int counts[ALPHA], char word[N]);
bool equal_array(int counts1[ALPHA], int counts2[ALPHA]);

int main(void) {
    char word1[N], word2[N];
    int counts1[ALPHA] = {0}, counts2[ALPHA] = {0};

    printf("Enter 1st word: ");
    int i = 0;
    while ((word1[i++] = getchar()) != '\n' && i < N)
        ;
    word1[i] = '\0';

    printf("Enter 2nd word: ");
    int j = 0;
    while ((word2[j++] = getchar()) != '\n' && j < N)
        ;
    word2[j] = '\0';

    if (i != j) {
        printf("The words are not anagrams.\n");
        return 0;
    }

    read_word(counts1, word1);
    read_word(counts2, word2);

    if (equal_array(counts1, counts2)) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }

    return 0;
}

void read_word(int counts[ALPHA], char word[N]) {
    for (int i = 0; i < N && word[i] != '\0'; i++)
        counts[tolower(word[i]) - 'a']++;
}

bool equal_array(int counts1[ALPHA], int counts2[ALPHA]) {
    for (int i = 0; i < ALPHA; i++) {
        if (counts1[i] != counts2[i])
            return false;
    }

    return true;
}
