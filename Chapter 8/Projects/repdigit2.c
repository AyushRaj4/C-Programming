// Name: repdigit2.c
// Purpose: To display the repeated digits of a number.
// Author: Ayush Raj

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // only works for +ve integers
    int repeated_count[10] = {};
    bool is_repeated = false;
    while (num != 0) {
        int r = num % 10;

        repeated_count[r]++;
        if (repeated_count[r] > 1)
            is_repeated = true;

        num /= 10;
    }

    if (is_repeated) {
        printf("Repeated digit(s): ");
        for (int i = 0; i < 10; i++)
            if (repeated_count[i] > 1)
                printf("%d ", i);
    }

    else
        printf("No repeated digits.");
    printf("\n");

    return 0;
}
