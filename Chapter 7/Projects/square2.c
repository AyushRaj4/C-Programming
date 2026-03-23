// Name: square2.c
// Purpose: To know the no. of bits used to store integer types on my machine
// Author: Ayush Raj

/* Prints a table of squares using a for statement */
#include <stdio.h>
int main(void) {
    int n;
    long i;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        printf("%20ld%20ld\n", i, i * i);

    return 0;
}
