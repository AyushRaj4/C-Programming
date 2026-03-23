// Name: test.c
// Purpose: Learn and test various C(C99) features
// Author: AR

#include <stdio.h>

int main(void) {
    // not initializing variables
    int a, b, c;
    float d, e, f;

    printf("Integers: %d, %d, %d\nFloating point numbers: %f %f %f\n", a, b, c, d, e, f);

    float fl = 100 / 6.0f;
    printf("%f\n", fl);

    return 0;
}
