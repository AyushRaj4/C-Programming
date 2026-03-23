// Name: squareroot.c
// Purpose: To calculate square root using Newton's method
// Author: Ayush Raj

#include <math.h>
#include <stdio.h>

int main(void) {
    double x, y = 1.0;

    printf("Enter a positive number: ");
    scanf("%lf", &x);

    while (1) {
        double temp = y;
        y = (y + (x / y)) / 2.0;

        if (fabs(y - temp) < 0.00001 * temp)
            break;
    }

    printf("Square root: %lf\n", y);

    return 0;
}
