// Name: dweight.c
// Purpose: Demonstrates double weight calculations.
// Author: AR

#include <stdio.h>

int main(void) {
    int l, w, h;

    printf("Enter length of box: ");
    scanf("%d", &l);    // never provide wrong literal(e.g., double or float in int variable)
    printf("Enter width of box: ");
    scanf("%d", &w);
    printf("Enter height of box: ");
    scanf("%d", &h);

    int volume = l * w * h;
    int dweight = volume / 166;

    printf("Volume of box = %d\n", volume);
    printf("Dimensional weight of box = %d\n", dweight);
    return 0;
}
