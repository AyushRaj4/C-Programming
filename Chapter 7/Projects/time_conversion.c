// Name: time_conversion.c
// Purpose: To convert 12 hour time to 24 hour time
// Author: Ayush Raj

#include <ctype.h>
#include <stdio.h>

int main(void) {
    int hours, minutes;
    char meridian;

    printf("Enter a 12-hour time: ");
    scanf("%d :%d %c", &hours, &minutes, &meridian);

    meridian = tolower(meridian);
    if (meridian == 'p') {
        if (hours < 12)
            hours += 12;
    }

    printf("Equivalent 24-hour time: %.2d:%.2d\n", hours, minutes);

    return 0;
}
