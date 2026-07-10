// Name: computing_interest.c
// Purpose: To print a table showing the value of $100 invested at different rates over a period of years.
// Author: Ayush Raj

#include <stdio.h>

#define NUM_RATES ((int)(sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00f

int main(void) {
    float rate;
    int years;
    float value[5];

    printf("Enter rate rate: ");
    scanf("%f", &rate);

    printf("Enter number of years: ");
    scanf("%d", &years);

    printf("\nYears\t");
    for (int i = 0; i < NUM_RATES; i++) {
        printf("%3d%%\t", (int)rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (int i = 1; i <= years; i++) {
        printf("%3d\t", i);
        for (int j = 0; j < NUM_RATES; j++) {
            value[j] += value[j] * ((rate + j) / 100);
            printf("%.2f\t", value[j]);
        }
        printf("\n");
    }

    return 0;
}
