// Name: product_info_format.c
// Purpose: To format product information entered by user to a specific format, refer Q2 in Programming Projects
// Author: Ayush Raj

#include <stdio.h>

int main (void) {
    int item_num; 
    float unit_price;
    int day, month, year;

    printf("Enter item number: ");
    scanf("%d", &item_num);

    printf("Enter unit price: ");
    scanf("%f", &unit_price);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("\n");

    // using double tab sequences
    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
    printf("%-d\t\t$%7.2f\t%-.2d/%-.2d/%-.4d\n\n", item_num, unit_price, month, day, year);

    // using single tab sequences
    // printf("Item\tUnit\tPurchase\n\tPrice\tDate\n");
    // printf("%-d\t$%7.2f%-.2d/%-.2d/%-.4d\n", item_num, unit_price, month, day, year);

    return 0;
}
