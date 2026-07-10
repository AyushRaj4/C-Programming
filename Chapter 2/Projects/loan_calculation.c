// Name: loan_calculation.c
// Purpose: Loan balance calculation for an EMI
// Author: AR

#include <stdio.h>

int main(void) {
    float loan_balance, annual_interest, monthly_payment;

    printf("Enter amount of loan: ");
    scanf("%f", &loan_balance);

    printf("Enter annual interest rate: ");
    scanf("%f", &annual_interest);

    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    // alternatively to take all inputs at once
    // scanf("%f %f %f", loan_balance, annual_interest, monthly_payment);

    // after 1st payment
    loan_balance = loan_balance + annual_interest / 100 / 12 * loan_balance - monthly_payment;
    printf("Balance remaining after first payment= %.2f\n", loan_balance);

    // after 2nd payment
    loan_balance = loan_balance + annual_interest / 100 / 12 * loan_balance - monthly_payment;
    printf("Balance remaining after second payment= %.2f\n", loan_balance);

    // after 3rd payment
    loan_balance = loan_balance + annual_interest / 100 / 12 * loan_balance - monthly_payment;
    printf("Balance remaining after third payment= %.2f\n", loan_balance);

    return 0;
}
