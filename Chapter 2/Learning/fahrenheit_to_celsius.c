// Name: fahrenheit_to_celsius.c
// Purpose: Converts fahrenheit temperatures to celsius.
// Author: AR

#include <stdio.h>
#define FREEZING_POINT 32.0f
#define SCALE_FACTOR 5.0f / 9.0f

int main(void) {
    float celsius, fahrenheit;
    
    printf("Enter temperature in fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - FREEZING_POINT) * SCALE_FACTOR;
    printf("%.2fF = %.2fC\n", fahrenheit, celsius);

    return 0;
}
