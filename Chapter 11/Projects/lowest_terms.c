// Name: reduced_terms.c
// Purpose: To reduce a fraction to its lowest terms.
// Author: Ayush Raj

#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);
void gcd(int num1, int num2, int *ans);

int main(void) {
    int numerator, denominator;
    printf("Enter fraction: ");
    scanf("%d /%d", &numerator, &denominator);

    int reduced_numerator, reduced_denominator;
    reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);
    printf("Reduced fraction = %d/%d\n", reduced_numerator, reduced_denominator);

    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {
    int ans;
    gcd(numerator, denominator, &ans);
    *reduced_denominator = denominator / ans;
    *reduced_numerator = numerator / ans;
}

void gcd(int n1, int n2, int *ans) {
    while (1) {
        int r = n1 % n2;
        if (!r) {
            break;
        }
        n1 = n2;
        n2 = r;
    }
    *ans = n2;
}
