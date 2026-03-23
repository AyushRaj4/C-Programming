// Name: b1ff.c
// Purpose: To translate input message into a B1FF speak.
// Author: Ayush Raj

#include <ctype.h>
#include <stdio.h>
#define N 1000

int main(void) {
    char message[N], ch;
    int msg_len = N;

    printf("Enter message: ");
    for (int i = 0; i < N; i++) {
        scanf("%c", &message[i]);
        message[i] = toupper(message[i]);

        if (message[i] == '\n') {
            msg_len = i;
            break;
        }
    }

    printf("In B1FF-speak: ");
    for (int i = 0; i < msg_len; i++) {
        switch (message[i]) {
            case 'A':
                message[i] = '4';
                break;

            case 'B':
                message[i] = '8';
                break;

            case 'E':
                message[i] = '3';
                break;

            case 'I':
                message[i] = '1';
                break;

            case 'O':
                message[i] = '0';
                break;

            case 'S':
                message[i] = '5';
                break;

            default:
                break;
        }
        printf("%c", message[i]);
    }
    printf("!!!!!!!!!!");
    printf("\n");

    return 0;
}
