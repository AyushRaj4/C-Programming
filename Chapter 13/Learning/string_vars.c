// Name: string_vars.c
// Purpose: To learn about string variables in C.
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    // if we did not initalize the string there would be garbage values just like any other array
    // just like normal arrays, strings initialize the rest of the elements to 0, in this case '\0' (null) character.
    char str[10] = {'a', '$'};

    for (char *ch = str; ch < str + 10; ch++) {
        printf("%c", *ch);
    }

    char str2[10] = "a$r-47";
    for (char *ch = str2; ch < str2 + 10; ch++) {
        printf("%c", *ch);
    }

    // my terminal is treating null char as lin feed, that means it takes cursor to new line but the horizintal position/column remains the same, as can be seen in output
    // printf("\n"); this does both a line feed and a carriage return, going to the next line and resetting the horizontal position to the start.
    char str3[] = "ayush raj the great";
    // this the most suitable way to print strings in my opinion
    for (char *ch = str3; *ch != '\0'; ch++) {
        printf("%c", *ch);
    }
    printf("\n");

    char str4[8] = {'a', 'b', 'c'};
    char str5[] = {'a', 'b', 'c'};
    char str6[4] = "abcdefgh"; // unusable string, initialization is longer than the length, so the null character is ommited, behaviour undefined
    for (char *ch = str6; *ch != '\0'; ch++) {
        printf("%c", *ch);
    }

    char *s = "456";
    s = str;
    s = "1234";

    return 0;
}

// SUMMARY
// String literals cannot be modified, variables can be.
// The pointer version of strings which point to literals can point to any other string, variables (char arrays) cannot.
