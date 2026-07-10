// Name: reverse_words.c
// Purpose: To reverse the words in a sentence.
// Author: Ayush Raj

#include <stdio.h>
#include <ctype.h>

#define N 100

void reverse_words(char *sentence, char *back);

int main(void) {
    char sentence[N];
    char ch, *chp = sentence;

    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n' && chp < sentence + N) {
        *chp = ch;
        chp++;
        if (ch == '?' || ch == '.' || ch == '!') {
            break;
        }
    }

    if (chp != sentence) {
        reverse_words(sentence, chp - 1);
    }

    return 0;
}

void reverse_words(char *sentence, char *back) {
    char *stop = isalpha(*back) ? back + 1 : back;
    for (char *ch = back; ch >= sentence; ch--) {
        if (*ch == ' ' || ch == sentence) {
            for (char *ch2 = ch == sentence ? ch : ch + 1; ch2 < stop; ch2++) {
                printf("%c", *ch2);
            }
            if (ch != sentence) {
                printf(" ");
            }
            stop = ch;
        }
    }
    if (!isalpha(*back)) {
        printf("%c\n", *back);
    }
}
