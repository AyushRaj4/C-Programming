// Name: eulers_num.c
// Purpose: To keep calculating the value of constant e expressed as an infinite series and stop after it becomes less than a numumber epsilon
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    float num;

    printf("Enter a numumber: ");
    scanf("%f", &num);

    float sum = 1;
    for (int i = 1;; i++) {
        float factorial = 1;
        for (int j = 1; j <= i; j++)
            factorial *= j;

        if (1 / factorial < num)
            break;
        sum += 1 / factorial;
    }

    printf("Value of Euler's constant e = %.10f\n", sum);

    return 0;
}
