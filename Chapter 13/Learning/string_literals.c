// Name: string_literals.c
// Purpose: To understand and experiment on string literals.
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    // '\' can be used to continue a string on the next line, no character will come after '\' on the same line
    printf("When you come to a fork in the road, take it.\
--Yogi Berra\n");

    // the string must continue at the begining of the next line
    printf("When you come to a fork in the road, take it.\
            --Yogi Berra\n");

    // better way for splicing
    printf("Yo"
           "yo\n");
    printf("When you come to a fork in the road, take it."
           "--Yogi Berra\n");

    char *p = "araj";
    char ch = p[1], ch2 = "a47"[2];
    printf("%c%c\n", ch, ch2);
    p = "ayu";

    // attempting to modify read only memory, string literals are unmodifiable, read: https://gemini.google.com/share/21335b3308f6
    // *p = "ayu";
    // p[2] = 'l';
    // *p = 'z';

    return 0;
}
