// Name: calendar.c
// Purpose: To display calendar based on no. of days and start date
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    int days, start_day;

    printf("Enter number of days in month: ");
    scanf("%d", &days);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start_day);

    int spaces = start_day - 1, count = 7 - start_day, day = 1;
    for (int i = 1; i <= start_day - 1 + days; i++) {
        if (spaces) {
            printf("\t");
            spaces--;
            continue;
        }

        if (count)
            printf("%d\t", day);
        else {
            printf("%d\n", day);
            count = 7;
        }
        day++;
        count--;
    }
    if (count != 6)
        printf("\n");

    return 0;
}
