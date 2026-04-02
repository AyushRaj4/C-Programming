// Name: palindrome2.c
// Purpose: To check if a message is palindrome or not, use array name as pointer.
// Author: Ayush Raj

// NOTE: I AM ONLY CHECKING ALPHABETS, NO OTHER CHARACTERS.

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

#define N 100

bool check_palindrome(char *msg, int n);

int main(void) {
    char msg[N] = {'\0'};
    char ch, *chp = msg;

    printf("Enter message: ");
    while ((ch = getchar()) != '\n' && chp < msg + N) {
        if (isalpha(ch)) {
            *chp = tolower(ch);
            chp++;
        }
    }

    bool is_palindrome = check_palindrome(msg, chp - msg);
    if (is_palindrome) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}

bool check_palindrome(char *msg, int n) {
    for (char *ch1 = msg, *ch2 = msg + n - 1; ch1 < ch2; ch1++, ch2--) {
        // printf("%c %c\n", *ch1, *ch2);
        if (*ch1 != *ch2) {
            return false;
        }
    }
    return n > 0 ? true : false;
}
