// Name: fracops.c
// Purpose: To add, subtract, multiply or divide 2 fractions based on input
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    int num1, num2, den1, den2;
    char operation;

    printf("Enter 2 fractions separated by +, -, * or /: ");
    scanf("%d /%d %c %d /%d", &num1, &den1, &operation, &num2, &den2);

    float ans;
    if (operation == '+')
        ans = (float)(num1 * den2 + num2 * den1) / (den1 * den2);

    else if (operation == '-')
        ans = (float)(num1 * den2 - num2 * den1) / (den1 * den2);

    else if (operation == '*')
        ans = (float)(num1 * num2) / (den1 * den2);

    else
        ans = (float)(num1 * den2) / (den1 * num2);

    printf("%d/%d %c %d/%d = %f\n", num1, den1, operation, num2, den2, ans);

    return 0;
}
