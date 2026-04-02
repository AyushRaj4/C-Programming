// Name: reverse_msg2.c
// Purpose: To print the reversal of a message, use array name as a pointer.
// Author: Ayush Raj

#include <stdio.h>

#define N 100

void print_reversed_msg(char *msg, int n);

int main(void) {
    char msg[N] = {'\0'};
    char ch, *p = msg;

    printf("Enter message: ");
    while ((ch = getchar()) != '\n' && p < msg + N) {
        *p = ch;
        p++;
    }

    print_reversed_msg(msg, p - msg); // subtraction b/w pointers gives the address block difference (distance b/w the addresses both pointers point to)

    return 0;
}

void print_reversed_msg(char *msg, int n) {
    for (char *ch = msg + n - 1; ch >= msg; ch--) {
        printf("%c", *ch);
    }
    printf("\n");
}
