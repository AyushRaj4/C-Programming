// Name: factorial.c
// Purpose: To calculate factorial of a given number.
// Author: Ayush Raj

#include <stdio.h>

int factorial(int num);
int factorial_condensed(int num);

int main(void) {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factorial = %d\n", factorial_condensed(num));

    return 0;
}

int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int factorial_condensed(int n) {
    return n <= 1 ? 1 : n * factorial_condensed(n - 1);
}
