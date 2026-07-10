// Name: count_vowels.c
// Purpose: To count vowels in a string.
// Author: Ayush Raj

#include <stdio.h>

int count_vowels(char *str) {
    int ans = 0;

    for (; *str != '\0'; str++) {
        switch (*str) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                ans++;
                break;
        }
    }
    return ans;
}

int main() {
    char test1[] = "recovery";
    char test2[] = "hardware architecture";

    printf("Vowels in '%s': %d\n", test1, count_vowels(test1));
    printf("Vowels in '%s': %d\n", test2, count_vowels(test2));

    return 0;
}
