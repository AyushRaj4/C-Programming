// Name: twelve_hour.c
// Purpose: To display 24-hour time in 12-hour format.
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    int hour_24, minute;

    printf("Enter a 24-hour time: ");
    scanf("%2d : %2d", &hour_24, &minute);

    if (hour_24 <= 12) {
        printf("Equivalent 12-hour time: %.2d:%.2d ", hour_24, minute);
        if (hour_24 == 12)
            printf("PM\n");
        else
            printf("AM\n");
    } else
        printf("Equivalent 12-hour time: %.2d:%.2d PM\n", hour_24 % 12, minute);

    return 0;
}
