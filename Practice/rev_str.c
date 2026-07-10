// Name: rev_str.c
// Purpose: To reverse strings using pointer arithmetic.
// Author: Ayush Raj

#include <stdio.h>

void reverse_string(char *str) {
    int len = 0;
    char *str2 = str;

    while (*str != '\0') {
        str++;
        len++;
    }

    for (int i = 0; i < len / 2; i++) {
        char temp = *(str2 + i);
        *(str2 + i) = *(str2 + len - i - 1);
        *(str2 + len - i - 1) = temp;
    }
}

int main(void) {
    int n;
    printf("Enter length of string: ");
    scanf("%d", &n);
    getchar();

    char string[n + 1];
    int i = 0;
    char ch;
    printf("Enter a string: ");
    while ((ch = getchar()) != '\n' && i < n) {
        string[i] = ch;
        i++;
    }
    string[i] = '\0';

    reverse_string(string);
    printf("Reversed string: %s\n", string);

    return 0;
}
