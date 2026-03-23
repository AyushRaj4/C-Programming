// Name: sphere_volume.c
// Purpose: Calculate volume of a sphere
// Author: AR

#include <stdio.h>
#define PI 3.14f
#define SCALE_FACTOR 4.0f / 3.0f

int main(void) {
    float radius;

    printf("Volume of sphere: ");
    scanf("%f", &radius);


    printf("Volume of sphere with radius %.2f = %.2f\n", radius, SCALE_FACTOR * PI * radius * radius * radius);

    return 0;
}
