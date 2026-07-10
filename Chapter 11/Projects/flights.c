// Name: flights.c
// Purpose: To display the closest flight in terms of departure time based on input time.
// Author: Ayush Raj

#include <stdio.h>
#include <stdlib.h>

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void) {
    int hours, minutes;

    printf("Enter a 24-hours time: ");
    scanf("%2d : %2d", &hours, &minutes);

    int desired_time = hours * 60 + minutes, departure_time, arrival_time;
    find_closest_flight(desired_time, &departure_time, &arrival_time);

    printf("Departure time: %d, Arrival time: %d\n", departure_time, arrival_time);

    return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time) {
    int depart_times[8] = {480, 583, 679, 767, 840, 945, 1140, 1305}, min_time = 9999;
    int arrival_times[8] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    for (int i = 0; i < 8; i++) {
        if (abs(depart_times[i] - desired_time) < min_time) {
            *departure_time = depart_times[i];
            *arrival_time = arrival_times[i];
            min_time = abs(depart_times[i] - desired_time);
        }
    }
}
