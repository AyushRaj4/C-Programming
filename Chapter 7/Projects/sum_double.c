// Name: sum2.c
// Purpose: To sum a series of floating point integers of type double
// Author: Ayush Raj

#include <stdio.h>
int main(void) {
    double num, sum = 0.0;

    printf("This program sums a series of double integers.\n");

    while (1) {
        printf("Enter integer, (0 to terminate): ");
        scanf("%lf", &num);
        if (num == 0.0)
            break;
        sum += num;
    }
    printf("Sum = %f\n", sum);

    return 0;
}
