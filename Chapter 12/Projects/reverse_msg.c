// Name: reverse_msg.c
// Purpose: To print the reversal of a message.
// Author: Ayush Raj

#include <stdio.h>

#define N 100

void print_reversed_msg(char *msg, int n);

int main(void) {
    char msg[N] = {'\0'};
    char ch;
    int i = 0;

    printf("Enter message: ");
    while ((ch = getchar()) != '\n' && i < N) {
        msg[i] = ch;
        i++;
    }

    print_reversed_msg(msg, i);

    return 0;
}

void print_reversed_msg(char *msg, int n) {
    for (char *ch = msg + n - 1; ch >= msg; ch--) {
        printf("%c", *ch);
    }
    printf("\n");
}
