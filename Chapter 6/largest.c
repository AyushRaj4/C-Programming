// Name: largest.c
// Purpose: To display the largest non-negative number.
// Author: Ayush Raj

#include <stdio.h>
int main(void) {
    float num, largest_num = 0;

    while (1) {
        printf("Enter a number: ");
        scanf("%f", &num);

        if (num <= 0)
            break;
        largest_num = largest_num < num ? num : largest_num;
    }
    printf("The largest number entered was %.2f\n", largest_num);

    return 0;
}
