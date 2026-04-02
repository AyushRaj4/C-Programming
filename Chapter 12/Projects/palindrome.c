// Name: palindrome.c
// Purpose: To check if a message is palindrome or not.
// Author: Ayush Raj

// NOTE: I AM ONLY CHECKING ALPHABETS, NO OTHER CHARACTERS.

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

#define N 100

bool check_palindrome(char *msg, int n);

int main(void) {
    char msg[N] = {'\0'};
    char ch;
    int i = 0;

    printf("Enter message: ");
    while ((ch = getchar()) != '\n' && i < N) {
        if (isalpha(ch)) {
            msg[i] = tolower(ch);
            i++;
        }
    }

    bool is_palindrome = check_palindrome(msg, i);
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
