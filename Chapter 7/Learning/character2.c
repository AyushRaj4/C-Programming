// Name: characters2.c
// Purpose: To do some more experiments on characters
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    char ch;
    scanf(" %c", &ch); // all white space characters lie space, \n, \t etc. will be ignored adn only non-whitespace characters will be read
    printf("%c\n", ch);

    return 0;
}
