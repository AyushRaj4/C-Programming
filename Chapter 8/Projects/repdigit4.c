// Name: repdigit4.c
// Purpose: To check if each +ve integer entered by user has repeated digits
// Author: Ayush Raj

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int num;

    printf("Enter +ve integers: ");

    // only works for +ve integers

    while (1) {
        scanf("%d", &num);

        if (!num)
            break;

        bool digit_seen[10] = {};
        bool is_repeated = false;
        while (num != 0) {
            int r = num % 10;

            if (digit_seen[r]) {
                is_repeated = true;
                break;
            }
            digit_seen[r] = true;

            num /= 10;
        }

        if (is_repeated)
            printf("Repeated digits!\n\n");
        else
            printf("No repeated digits!\n\n");
    }

    return 0;
}
