// Name: polynomial.c
// Purpose: Evaluate polynomial 3x5 + 2x4 – 5x3 – x2 + 7x – 6 on input
// Author: AR

#include<stdio.h>

int main(void) {
    int x, polynomial, polynomial_horners_rule;

    printf("Enter x: ");
    scanf("%d", &x);

    polynomial = 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6;
    polynomial_horners_rule = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
    printf("For f(x) = 3x⁵ + 2x⁴ - 5x³ - x² + 7x - 6, f(%d) = %d\n", x, polynomial);
    printf("Using Horner's rule f(x) ((((3x + 2)x – 5)x – 1)x + 7)x – 6, f(%d) = %d\n", x, polynomial_horners_rule);
}
