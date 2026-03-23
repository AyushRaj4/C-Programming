// Name: eff_pow.c
// Purpose: To make the power function faster using formulas given in Q7.
// Author: Ayush Raj

#include <stdio.h>

int power(int x, int n);

int main(void) {
    int x, n;
    printf("Enter number and its power: ");
    scanf("%d%d", &x, &n);

    printf("%d^%d = %d\n", x, n, power(x, n));

    return 0;
}

int power(int x, int n) {
    if (n == 0)
        return 1;

    if (n % 2 == 0) {
        int temp = power(x, n / 2);
        return temp * temp;
    } else
        return x * power(x, n - 1);

    // my approach, less efficient because eventually I am doing more recursion by using an outside p(p(x, n / 2), 2)
    // better approach is to store the value in a variable and send the square
    // TC: my version = O(n), optimized version = O(log n)
    // return n % 2 ? x * power(x, n - 1) : power(power(x, n / 2), 2);
}
