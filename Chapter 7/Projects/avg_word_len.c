// Name: avg_word_len.c
// Purpose: To calculate the average word length of a sentence
// Author: Ayush Raj

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    char alpha;
    int letters = 0, words = 0;
    _Bool spaceBefore = true;

    printf("Enter a sentence: ");
    while (1) {
        scanf("%c", &alpha);

        if (alpha == '\n')
            break;

        if (alpha != ' ') {
            if (spaceBefore)
                words++;
            letters++;
            spaceBefore = false;
        }

        else
            spaceBefore = true;
    }

    printf("Average word length: %.2f\n", (float)letters / words);

    return 0;
}
