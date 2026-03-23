// Name: loan_calculation.c
// Purpose: Loan balance calculation for an EMI
// Author: AR

#include <stdio.h>

int main(void) {
    float loan_balance, annual_interest, monthly_payment;
    int payment_count;

    printf("Enter amount of loan: ");
    scanf("%f", &loan_balance);

    printf("Enter annual interest rate: ");
    scanf("%f", &annual_interest);

    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    printf("Enter number of payments: ");
    scanf("%d", &payment_count);

    for (int i = 1; i <= payment_count; i++) {
        loan_balance = loan_balance + annual_interest / 100 / 12 * loan_balance - monthly_payment;
        printf("Balance remaining after payment %d = %.2f\n", i, loan_balance);
    }

    return 0;
}
