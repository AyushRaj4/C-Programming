// Name: q7.c
// Purpose: To write the split_date function in q7.
// Author: Ayush Raj

#include <stdio.h>

void split_date(int day_of_year, int year, int *month, int *day);

int main(void) {
    int day_of_year, year;
    printf("Enter day of year and year: ");
    scanf("%d%d", &day_of_year, &year);

    int month, day;
    split_date(day_of_year, year, &month, &day);
    printf("Month = %d, Day = %d\n", month, day);

    return 0;
}

void split_date(int day_of_year, int year, int *month, int *day) {
    int day_sum = 0, month_days[12] = {31, year % 4 ? 28 : 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i;
    for (i = 0; i < 12; i++) {
        day_sum += month_days[i];
        if (day_sum >= day_of_year) {
            break;
        }
    }

    *month = i + 1;
    *day = month_days[i] - (day_sum - day_of_year);
}
