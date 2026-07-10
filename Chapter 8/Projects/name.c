// Name: name.c
// Purpose: To take a first name and last name entered by the user and displays the last name, a comma, and the first initial, followed by a period.
// Author: Ayush Raj

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#define N 20

int main(void) {
    int last_name[N], len = 0;

    char first_initial, ch;
    printf("Enter first and last name: ");
    scanf("%c", &first_initial);

    bool flag = false;
    while ((ch = getchar()) != '\n') {
        if (flag) {
            if (len >= N)
                break;
            if (ch != ' ' && ch != '\t') {
                last_name[len] = ch;
                len++;
            }
        }

        if (ch == ' ' || ch == '\t')
            flag = true;
    }
    last_name[len] = '\0';

    printf("You entered the name: ");
    for (int i = 0; i < len; i++)
        printf("%c", last_name[i]);
    printf(", %c.\n", toupper(first_initial));

    return 0;
}
