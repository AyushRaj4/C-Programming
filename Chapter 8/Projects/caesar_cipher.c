// Name: caesar_cipher.c
// Purpose: To encrypt input message using the Caesar cipher technique.
// Author: Ayush Raj

#include <stdio.h>
#define N 80

int main(void) {
    int msg[N], msg_len = 0;
    int key;

    printf("Enter message to be encrypted: ");
    while ((msg[msg_len++] = getchar()) != '\n' && msg_len < N)
        ;
    msg[msg_len] = '\0';

    printf("Enter shift amount (1-25): ");
    scanf("%d", &key);

    printf("Encrypted message: ");
    int i = 0;
    while (msg[i] != '\0') {
        if (msg[i] >= 'A' && msg[i] <= 'Z')
            msg[i] = (msg[i] - 'A' + key) % 26 + 'A';

        else if (msg[i] >= 'a' && msg[i] <= 'z')
            msg[i] = (msg[i] - 'a' + key) % 26 + 'a';

        printf("%c", msg[i]);
        i++;
    }

    return 0;
}
