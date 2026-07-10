// Name: largest_smallest.c
// Purpose: To find largest and smallest of 4 integers
// Author: Ayush Raj

#include <stdio.h>
int main(void) {
    int a, b, c, d, max1, min1, max2, min2, largest, smallest;

    printf("Enter 4 integers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);

    if (a > b) {
        max1 = a;
        min1 = b;
    } else {
        max1 = b;
        min1 = a;
    }

    if (c > d) {
        max2 = c;
        min2 = d;
    } else {
        max2 = d;
        min2 = c;
    }

    if (max1 >= max2)
        largest = max1;
    else
        largest = max2;

    if (min1 <= min2)
        smallest = min1;
    else
        smallest = min2;

    printf("Largest number is %d\n", largest);
    printf("Smallest number is %d\n", smallest);

    return 0;
}
