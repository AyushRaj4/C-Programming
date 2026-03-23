// Name: taxes.c
// Purpose: To display the tax on taxable income.
// Author: Ayush Raj

#include <stdio.h>

float calc_tax(float tax_inc);

int main(void) {
    float tax_inc;

    printf("Enter your taxable income: ");
    scanf("%f", &tax_inc);

    printf("Tax due: %.2f\n", calc_tax(tax_inc));

    return 0;
}

float calc_tax(float income) {
    float tax = 0.0f;

    if (income <= 750.0f) {
        tax = 0.01f * income;
    } else if (income <= 2250.0f) {
        tax = 7.5f + 0.02f * (income - 750.0f);
    } else if (income <= 3750.0f) {
        tax = 37.5f + 0.03f * (income - 2250.0f);
    } else if (income <= 5250.0f) {
        tax = 82.5f + 0.04f * (income - 3750.0f);
    } else if (income <= 7000.0f) {
        tax = 142.5f + 0.05f * (income - 5250.0f);
    } else {
        // Taincome for amounts over 7000
        tax = 230.0f + 0.06f * (income - 7000.0f);
    }

    return tax;
}
