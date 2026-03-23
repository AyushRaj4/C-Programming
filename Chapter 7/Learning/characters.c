// Name: char_functions.c
// Purpose: To learn about some functions for characters in C
// Author: Ayush Raj

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch = 'a', ch2 = 98;
    int a = 97, b = 'b';

    printf("%c, %c, %d, %d\n", ch, ch2, ch, ch2);
    printf("%c, %c, %d, %d\n", a, b, a, b);

    ch += 5;
    ch2++;
    printf("%c, %c, %d, %d\n", ch, ch2, ch, ch2);

    // it's generally better to not use signed or unsigned for char type until absolutely necessary
    signed char ch3;
    unsigned char ch4;

    printf("Escape\tsequences\vtab_end\n");
    printf("Octal escape sequence (ESC): \33zesc_end\n");
    printf("Hexadecimal escape sequence (ESC): \x1b zesc_end\n");

    // some char functions
    printf("r to %c\n", toupper('r'));

    printf("\n");
    // if the 1st input is \n, the 2nd input will be normal but if it's anything else then getchar will read the 1st char from whatever is left in the buffer after the 1st input
    char ch5;
    printf("Enter 1st character: ");
    scanf("%c", &ch5);
    printf("1st character: %c\n", ch5);

    printf("Enter 2nd character: ");
    ch5 = getchar();
    printf("2nd character: %c\n", ch5);

    // some idioms
    // below idioms (different versions but same function) flush all input from buffer till \n (including) is encountered
    /*
    do {
        scanf("%c", &ch);
    } while (ch != '\n');

    do {
        ch6 = getchar();
    } while (ch != '\n');

    while (ch = getchar() != '\n')
        ;

    while (getchar() != '\n')
        ;
    */

    // skips blanks
    /*
    while (ch = getchar() == ' ')
        ;
    OR
    while (getchar() == ' ')
        ;
    */

    return 0;
}
