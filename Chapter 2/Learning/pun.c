// Name: pun.c
// Purpose: Prints a bad pun.
//  Author: AR

#include<stdio.h>

// In C, main can be defined without an explicit return type
int main(void) {
    int i = 42;
    float f = 99.8899f; // 'f' suffix indicates a float literal

    printf("To C, or not to C: that is the question.\n");
    printf("%f\n",i * f);
    printf("Integer: %d, Float: %.2f\n", i, f); // round float to 2 decimal places
    return 0;
}
