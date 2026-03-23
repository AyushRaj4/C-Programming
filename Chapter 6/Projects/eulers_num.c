// Name: eulers_num.c
// Purpose: To calculate the value of constant e expressed as an infinite series
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    float sum = 1;
    for (int i = 1; i <= n; i++) {
        float factorial = 1;
        for (int j = 1; j <= i; j++)
            factorial *= j;

        sum += 1 / factorial;
    }

    printf("Value of Euler's constant e = %.10f\n", sum);

    return 0;
}
