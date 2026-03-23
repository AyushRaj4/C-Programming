// Name: repdigit3.c
// Purpose: To display the count of digit in the given integer.
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // only works for +ve integers
    int repeated_count[10] = {};
    while (num != 0) {
        int r = num % 10;
        repeated_count[r]++;
        num /= 10;
    }

    printf("Digit:        ");
    for (int i = 0; i < 10; i++)
        printf("%d ", i);
    printf("\n");

    printf("Occurrences:  ");
    for (int i = 0; i < 10; i++)
        printf("%d ", repeated_count[i]);
    printf("\n");

    return 0;
}
