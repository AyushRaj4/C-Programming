// Name: polynomial.c
// Purpose: To compute a polynomial in a function and display the result.
// Author: Ayush Raj

// Given polynomial: 3x5 + 2x4 – 5x3 – x2 + 7x – 6

#include <stdio.h>

double polynomial(double x), power(double x, int n);

int main(void) {
    double x;

    printf("Enter value to be computed for polynomial: ");
    scanf("%lf", &x);

    printf("f(%.2f) = %.2f\n", x, polynomial(x));

    return 0;
}

double polynomial(double x) {
    return 3 * power(x, 5) + 2 * power(x, 4) - 5 * power(x, 3) - power(x, 2) + 7 * x - 6;
}

double power(double x, int n) {
    return n == 0 ? 1 : x * power(x, n - 1);
}
