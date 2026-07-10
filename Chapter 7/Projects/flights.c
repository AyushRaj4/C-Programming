// Name: flights.c
// Purpose: Remodifying programming project 8 from Chapter 8 so that the user enters a time using the 12-hour clock
// Author: Ayush Raj

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int main(void) {
    int hours, minutes;
    char meridian;

    printf("Enter a 12-hour time: ");
    scanf("%d :%d %c", &hours, &minutes, &meridian);

    meridian = tolower(meridian);

    int curr_time_minutes;
    if (meridian == 'a')
        curr_time_minutes = hours * 60 + minutes;
    else
        curr_time_minutes = (hours + 12) * 60 + minutes;

    int depart1 = 8 * 60 + 0, depart2 = 9 * 60 + 43, depart3 = 11 * 60 + 19, depart4 = 12 * 60 + 47, depart5 = 14 * 60 + 0, depart6 = 15 * 60 + 45, depart7 = 19 * 60 + 0,
        depart8 = 21 * 60 + 45;

    int forward_diff, backward_diff, min_diff, correct_diff = 9999, closest_time;

    forward_diff = abs(depart1 - curr_time_minutes);
    backward_diff = 1440 - depart1 + curr_time_minutes;
    // printf("%d, %d\n", forward_diff, backward_diff);
    if (forward_diff < backward_diff)
        min_diff = forward_diff;
    else
        min_diff = backward_diff;

    if (min_diff < correct_diff) {
        closest_time = depart1;
        correct_diff = min_diff;
    }

    forward_diff = abs(depart2 - curr_time_minutes);
    backward_diff = 1440 - depart2 + curr_time_minutes;
    if (forward_diff < backward_diff)
        min_diff = forward_diff;
    else
        min_diff = backward_diff;

    if (min_diff < correct_diff) {
        closest_time = depart2;
        correct_diff = min_diff;
    }

    forward_diff = abs(depart3 - curr_time_minutes);
    backward_diff = 1440 - depart3 + curr_time_minutes;
    if (forward_diff < backward_diff)
        min_diff = forward_diff;
    else
        min_diff = backward_diff;

    if (min_diff < correct_diff) {
        closest_time = depart3;
        correct_diff = min_diff;
    }

    forward_diff = abs(depart4 - curr_time_minutes);
    backward_diff = 1440 - depart4 + curr_time_minutes;
    if (forward_diff < backward_diff)
        min_diff = forward_diff;
    else
        min_diff = backward_diff;

    if (min_diff < correct_diff) {
        closest_time = depart4;
        correct_diff = min_diff;
    }

    forward_diff = abs(depart5 - curr_time_minutes);
    backward_diff = 1440 - depart5 + curr_time_minutes;
    if (forward_diff < backward_diff)
        min_diff = forward_diff;
    else
        min_diff = backward_diff;

    if (min_diff < correct_diff) {
        closest_time = depart5;
        correct_diff = min_diff;
    }

    forward_diff = abs(depart6 - curr_time_minutes);
    backward_diff = 1440 - depart6 + curr_time_minutes;
    if (forward_diff < backward_diff)
        min_diff = forward_diff;
    else
        min_diff = backward_diff;

    if (min_diff < correct_diff) {
        closest_time = depart6;
        correct_diff = min_diff;
    }

    forward_diff = abs(depart7 - curr_time_minutes);
    backward_diff = 1440 - depart7 + curr_time_minutes;
    if (forward_diff < backward_diff)
        min_diff = forward_diff;
    else
        min_diff = backward_diff;

    if (min_diff < correct_diff) {
        closest_time = depart7;
        correct_diff = min_diff;
    }

    forward_diff = abs(depart8 - curr_time_minutes);
    backward_diff = 1440 - depart8 + curr_time_minutes;
    if (forward_diff < backward_diff)
        min_diff = forward_diff;
    else
        min_diff = backward_diff;

    if (min_diff < correct_diff) {
        closest_time = depart8;
        correct_diff = min_diff;
    }

    int ans_hours = closest_time / 60, ans_minutes = closest_time % 60;
    if (ans_hours > 12)
        ans_hours %= 12;

    printf("%.2d:%.2d ", ans_hours, ans_minutes);
    if (closest_time / 60 >= 12)
        printf("p.m.\n");
    else
        printf("a.m.\n");

    return 0;
}
