// Name: flights.c
// Purpose: To display the closest flight in terms of departure time based on input time.
// Author: Ayush Raj

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int hours, minutes;

    printf("Enter a 24-hours time: ");
    scanf("%2d : %2d", &hours, &minutes);

    int new_time = hours * 60 + minutes, time_diff = 999999, closest_time;
    int depart_time1 = 8 * 60 + 0, depart_time2 = 9 * 60 + 43, depart_time3 = 11 * 60 + 19, depart_time4 = 12 * 60 + 47, depart_time5 = 14 * 60 + 0, depart_time6 = 15 * 60 + 45, depart_time7 = 19 * 60 + 0, depart_time8 = 21 * 60 + 45;

    if (abs(new_time - depart_time1) < time_diff) {
        closest_time = depart_time1;
        time_diff = abs(new_time - depart_time1);
    }

    if (abs(new_time - depart_time2) < time_diff) {
        closest_time = depart_time2;
        time_diff = abs(new_time - depart_time2);
    }

    if (abs(new_time - depart_time3) < time_diff) {
        closest_time = depart_time3;
        time_diff = abs(new_time - depart_time3);
    }

    if (abs(new_time - depart_time4) < time_diff) {
        closest_time = depart_time4;
        time_diff = abs(new_time - depart_time4);
    }

    if (abs(new_time - depart_time5) < time_diff) {
        closest_time = depart_time5;
        time_diff = abs(new_time - depart_time5);
    }

    if (abs(new_time - depart_time6) < time_diff) {
        closest_time = depart_time6;
        time_diff = abs(new_time - depart_time6);
    }

    if (abs(new_time - depart_time7) < time_diff) {
        closest_time = depart_time7;
        time_diff = abs(new_time - depart_time7);
    }

    if (abs(new_time - depart_time8) < time_diff) {
        closest_time = depart_time8;
        time_diff = abs(new_time - depart_time8);
    }

    int hour_12 = closest_time / 60, minute_12 = closest_time % 60;
    if (hour_12 > 12)
        hour_12 %= 12;
    printf("Closest departure time is %.2d:%.2d ", hour_12, minute_12);
    if (closest_time / 60 >= 12)
        printf("p.m.\n");
    else
        printf("a.m.\n");

    return 0;
}
