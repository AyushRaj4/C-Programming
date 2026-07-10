// Name: beaufort_speed.c
// Purpose: To display the correct description according to wind speed
// Author: Ayush Raj

#include <stdio.h>
int main(void) {
    int speed;

    printf("Enter speed(knots): ");
    scanf("%d", &speed);

    if (speed < 1)
        printf("Calm");
    else if (speed < 4)
        printf("Light air");
    else if (speed < 28)
        printf("Breeze");
    else if (speed < 48)
        printf("Gale");
    else if (speed < 64)
        printf("Storm");
    else
        printf("Hurricane");

    return 0;
}
