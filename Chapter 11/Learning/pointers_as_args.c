// Name: pointers_as_args.c
// Purpose: To experiment passing pointers as arguments to a function.
// Author: Ayush Raj

#include <stdio.h>

void decompose(double x, long *int_part, double *frac_part);

int main(void) {
    long i;
    double d;
    decompose(3.14159, &i, &d);
    printf("%ld %lf\n", i, d);

    return 0;
}

void decompose(double x, long *int_part, double *frac_part) {
    *int_part = (long)x;
    *frac_part = x - *int_part;
}
