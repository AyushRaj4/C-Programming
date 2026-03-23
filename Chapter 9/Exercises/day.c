// Name: day.c
// Purpose: To find day of the year using given date
// Author: Ayush Raj

#include <stdio.h>

int day_of_year(int day, int month, int year);

int main(void) {
    int day, month, year;

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d /%d /%d", &day, &month, &year);

    printf("Day of the year = %d\n", day_of_year(day, month, year));

    return 0;
}

int day_of_year(int d, int m, int y) {
    int ans = 0;
    for (int i = 1; i < m; i++) {
        if (i == 2)
            ans += y % 4 ? 28 : 29;

        else if ((i % 2 && i <= 7) || (!(i % 2) && i > 7))
            ans += 31;

        else
            ans += 30;
    }
    return ans + d;
}
