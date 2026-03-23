// Name: dates.c
// Purpose: To determine the earliest date
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    int day, month, year, ans1 = 99, ans2 = 99, ans3 = 99;

    while (1) {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d /%d /%d", &month, &day, &year);

        if (day == 0 && month == 0 && year == 0)
            break;

        if (year < ans3) {
            ans1 = day;
            ans2 = month;
            ans3 = year;
        } else if (month < ans2 && year == ans3) {
            ans1 = day;
            ans2 = month;
            ans3 = year;
        } else if (day < ans1 && month == ans2 && year == ans3) {
            ans1 = day;
            ans2 = month;
            ans3 = year;
        }
    }

    printf("%.2d/%.2d/%.2d is the earliest date.\n", ans2, ans1, ans3);

    return 0;
}
