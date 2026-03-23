// Name: reverse.c
// Purpose: To reverse the given number
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);
    int num_copy = num;

    printf("Reversed number: ");
    do {
        int r = num % 10;

        // handles -ve numbers properly as well
        if (r < 0 && num != num_copy)
            r *= -1;

        printf("%d", r);
        num /= 10;
    } while (num != 0);
    printf("\n");

    return 0;
}
