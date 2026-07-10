// Name: isbn.c
// Purpose: To show different parts of ISBN-13 separately
// Author: Ayush Raj

#include <stdio.h>

int main (void) {
    int gsi_prefix, group_id, publisher_code, item_num, check_digit;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gsi_prefix, &group_id, &publisher_code, &item_num, &check_digit);

    printf("GSI prefix: %d\n", gsi_prefix);
    printf("Group identifier: %d\n", group_id);
    printf("Publisher Code: %d\n", publisher_code);
    printf("Item number: %d\n", item_num);
    printf("Check digit: %d\n", check_digit);

    return 0;
}
