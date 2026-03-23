// Name: telephone.c
// Purpose: To convert input phone number to it's numeric form.
// Author: Ayush Raj

#include <ctype.h>
#include <stdio.h>
#define N 15

int main(void) {
    char phone_num[N];
    int len = 0;
    char c;

    printf("Enter phone number: ");
    /*
    for (int i = 0; i < N; i++) {
        scanf("%c", &phone_num[i]);
        phone_num[i] = toupper(phone_num[i]);
        len++;
        if (phone_num[i] == '\n')
            break;
    }
    */
    while ((c = getchar()) != '\n' && len < N) {
        phone_num[len] = c;
        phone_num[len] = toupper(phone_num[len]);
        len++;
    }
    phone_num[len] = '\0'; // Null-terminate the string

    printf("In numeric form: ");
    for (int i = 0; i < len; i++) {
        if (phone_num[i] == 'A' || phone_num[i] == 'B' || phone_num[i] == 'C')
            phone_num[i] = '2';

        else if (phone_num[i] == 'D' || phone_num[i] == 'E' || phone_num[i] == 'F')
            phone_num[i] = '3';

        else if (phone_num[i] == 'G' || phone_num[i] == 'H' || phone_num[i] == 'I')
            phone_num[i] = '4';

        else if (phone_num[i] == 'J' || phone_num[i] == 'K' || phone_num[i] == 'L')
            phone_num[i] = '5';

        else if (phone_num[i] == 'M' || phone_num[i] == 'N' || phone_num[i] == 'O')
            phone_num[i] = '6';

        else if (phone_num[i] == 'P' || phone_num[i] == 'R' || phone_num[i] == 'S')
            phone_num[i] = '7';

        else if (phone_num[i] == 'T' || phone_num[i] == 'U' || phone_num[i] == 'V')
            phone_num[i] = '8';

        else if (phone_num[i] == 'W' || phone_num[i] == 'X' || phone_num[i] == 'Y')
            phone_num[i] = '9';

        printf("%c", phone_num[i]);
    }
    printf("\n");

    return 0;
}
