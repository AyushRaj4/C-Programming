// Name: square24.c
// Purpose: To calculate and display squares till a number n
// Author: Ayush Raj

/* Prints a table of squares using a for statement */
#include <stdio.h>
int main(void) {
    int n, i;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    getchar();

    for (i = 1; i <= n; i++) {
        if (i % 24 == 1 && i != 1) {
            printf("Press Enter to continue...\n");
            while (getchar() != '\n')
                ;
        }

        printf("%20d%20d\n", i, i * i);
    }

    return 0;
}
