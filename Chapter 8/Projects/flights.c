// Name: flights.c
// Purpose: To find the closest departure time to the input time and dispaly both the departure and arrival times of the flight
// Author: Ayush Raj

#include <stdio.h>
#include <stdlib.h>
#define N 8

int main(void) {
    int departure_times[N] = {480, 583, 679, 767, 840, 945, 1140, 1305};
    int arrival_times[N] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    int hours, minutes;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hours, &minutes);

    int time_minutes = hours * 60 + minutes, ans = 0, closest_time = 9999;
    for (int i = 0; i < N; i++) {
        int depart_reverse = 1440 - departure_times[i];
        int diff = abs(departure_times[i] - time_minutes), diff2 = depart_reverse + time_minutes;
        if (diff2 < diff)
            diff = diff2;

        if (diff < closest_time) {
            closest_time = diff;
            ans = i;
        }
    }

    int depart_hrs = departure_times[ans] / 60, depart_mins = departure_times[ans] % 60;
    char meridian = 'a';
    if (depart_hrs >= 12)
        meridian = 'p';
    if (depart_hrs > 12) {
        depart_hrs -= 12;
    }

    int arrival_hrs = arrival_times[ans] / 60, arrival_mins = arrival_times[ans] % 60;
    char meridian2 = 'a';
    if (arrival_hrs >= 12)
        meridian2 = 'p';
    if (arrival_hrs > 12) {
        arrival_hrs -= 12;
    }

    printf("Closest departure time is %.2d:%.2d %c.m., arriving at %.2d:%.2d %c.m.", depart_hrs, depart_mins, meridian, arrival_hrs, arrival_mins, meridian2);
    //printf("Closest departure time is %.2d:%.2d, arriving at %.2d:%.2d.", departure_times[ans] / 60, departure_times[ans] % 60, arrival_times[ans] / 60, arrival_times[ans] % 60);

    return 0;
}
