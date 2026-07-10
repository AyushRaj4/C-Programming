// Name: repeated.c
// Purpose: To check if a digit in the given number appears more than once
// Author: Ayush Raj

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    bool digit_seen[10] = {false}, is_repeated = false;

    while (num > 0) {
        int digit = num % 10;
        if (digit_seen[digit]) {
            is_repeated = true;
            break;
        }
        digit_seen[digit] = true;
        num /= 10;
    }

    if (is_repeated)
        printf("Repeated digit\n");
    else
        printf("No repeated digit\n");

    return 0;
}
