// Name: calendar.c
// Purpose: To display the earlier date out of 2 input dates
// Author: Ayush Raj

#include <stdio.h>
int main(void) {
    int day1, day2, month1, month2, year1, year2;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%2d/ %2d/ %2d", &month1, &day1, &year1);

    printf("Enter 2nd date (mm/dd/yy): ");
    scanf("%2d/ %2d/ %2d", &month2, &day2, &year2);

    int ans = 1;
    if (year2 < year1)
        ans = 2;
    else if (month2 < month1 && year1 == year2)
        ans = 2;
    else if (day2 < day1 && month1 == month2 && year1 == year2)
        ans = 2;

    if (day1 == day2 && month1 == month2 && year1 == year2)
        ans = 0;

    if (ans == 0)
        printf("Both dates are same!");
    else if (ans == 1)
        printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d\n", month1, day1, year1, month2, day2, year2);
    else
        printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d\n", month2, day2, year2, month1, day1, year1);

    return 0;
}
