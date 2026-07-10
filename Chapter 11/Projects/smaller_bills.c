// Name: smaller_bills.c
// Purpose: Divide amount into smaller bills.
// Author: AR

#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void) {
    int amount, bills20, bills10, bills5, bills1;

    printf("Enter amount in $: ");
    scanf("%d", &amount);

    pay_amount(amount, &bills20, &bills10, &bills5, &bills1);

    printf("$20 bills = %d\n", bills20);
    printf("$10 bills = %d\n", bills10);
    printf("$5 bills = %d\n", bills5);
    printf("$1 bills = %d\n", bills1);

    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    *twenties = dollars / 20;
    dollars = dollars - dollars / 20 * 20;

    *tens = dollars / 10;
    dollars = dollars - dollars / 10 * 10;

    *fives = dollars / 5;
    dollars = dollars - dollars / 5 * 5;

    *ones = dollars;
}
