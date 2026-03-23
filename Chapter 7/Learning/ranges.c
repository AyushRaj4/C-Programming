// Name: ranges.c
// Purpose: To display the range and precision of different types in C
// Author: Ayush Raj

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    printf("short range: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("int range: %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int max value (unsigned integers cannot be -ve): %u\n", UINT_MAX);
    printf("long range: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long max value: %lu\n", ULONG_MAX);
    printf("long long range: %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long max value: %llu\n", ULLONG_MAX);
    printf("\n");

    // floating point types in C (the name comes from the way these numbers are represented in computers, where the decimal (or binary) point is not fixed but can "float" depending on the magnitude of the number)
    // float type in C is used when there is not much need of precision, e.g., to store prices of daily use items on Amazon, to store temparature values etc.
    // double and long double are used for scientific calculations mainly where precision is very important.
    // never forget to use "f" at the end of a float constant.
    printf("Float precision: %d digits\n", FLT_DIG);
    printf("Float range %g to %g\n", FLT_MIN, FLT_MAX); // it's better to display the max size in exponent form because the no. is large
    printf("Double precision: %d digits\n", DBL_DIG);
    printf("Double range %e to %g\n", DBL_MIN, DBL_MAX); // g chooses exponent or decimal point notation based on number size, e will always display exponent notation
    printf("Long double precision: %d digits\n", LDBL_DIG);
    printf("Long Double range %Le to %Le\n", LDBL_MIN, LDBL_MAX);
    printf("\n");

    // some examples
    printf("%f\n", 123456789999.0000f);
    printf("%f\n", 123456789999.0000); // f specifier can be used for both float and double types in printf, in scanf use lf for double.
    printf("%.10f\n", 1.234567899990000f);
    printf("%.10f\n", 1.765432199990000f);

    return 0;
}
