// Name: str_read_write.c
// Purpose: To learn how reading and writing on a string is done in C.
// Author: Ayush Raj

#include <stdio.h>

int read_line(char str[], int n);

int main(void) {
    char str[] = "Are we having fun yet?";
    printf("%s\n%s\n", str, "Yes we are!");
    printf("%.6s\n", str);
    printf("%10.6s\n", str); // %m.ps works the same way in strings as in numbers, even the '-' sign
    puts(str);
    puts("Holy shitto!");
    puts("");

    char sentence[11];
    printf("Enter a sentence: ");
    scanf("%s", sentence);
    puts(sentence);

    char ch;
    while ((ch = getchar()) != '\n')
        ;

    char sentence2[] = "hjk"; // initializing this string with 2 characters means it's size is set to 3 bytes by the compiler, 1 byte for the null character
    printf("Enter a sentence: ");
    scanf("%2s", sentence2); // this ensures that there will be no buffer overflow even if user enters more than 2 characters
    puts(sentence2);

    // gets function was depreceated in C99 and completely removed from the C standard in C11, so I can't experiment with it now.
    // gets doesn't skip any whitespace character except '\n', it reads the full string until it encounters '\n', then discards it and replaces it with '\0' and stores it in array

    while ((ch = getchar()) != '\n')
        ;

    // READING STRINGS CHARACTER BY CHARACTER
    // This function doesn’t skip white-space characters, stops reading at the first new-line character (which isn’t stored in the string), and discards extra characters.
    char s[11];
    printf("Enter a string: ");
    read_line(s, 11);
    puts(s);

    return 0;
}

int read_line(char str[], int n) {
    int ch;
    int i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < n - 1) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';

    return i;
}
