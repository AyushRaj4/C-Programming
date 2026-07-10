// Name: gcd.c
// Purpose: To calculate the GCD of 2 numbers
// Author: Aysh Raj

#include <stdio.h>

int main(void) {
    int num1, num2;

    printf("Enter 2 integers: ");
    scanf("%d%d", &num1, &num2);

    int dividend = num1, divisor = num2, gcd;

    if (num1 == 0 && num2 == 0) {
        printf("0/0 is undefined!");
        return 0;
    }

    if (num1 == 0) {
        gcd = num2;
        goto gcd;
    }

    if (num2 == 0) {
        gcd = num1;
        goto gcd;
    }

    while (1) {
        int r = dividend % divisor;

        if (!r) {
            gcd = divisor;
            break;
        }

        dividend = divisor;
        divisor = r;
    }
gcd:
    printf("Greatest common divisor: %d\n", gcd);

    return 0;
}
