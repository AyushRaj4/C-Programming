// Name: sphere_volume.c
// Purpose: Calculate total amount after tax
// Author: AR

#include <stdio.h>

int main(void) {
    float dollars, cents, amount_in_decimal;

    printf("$: ");
    scanf("%f", &dollars);
    printf("¢: ");
    scanf("%f", &cents);

    amount_in_decimal = dollars + cents / 100.0f;

    printf("Entered amount: %.2f\n", amount_in_decimal);
    printf("Amount after 5 percent tax: %.2f\n", amount_in_decimal + 0.05f * amount_in_decimal);

    return 0;
}
