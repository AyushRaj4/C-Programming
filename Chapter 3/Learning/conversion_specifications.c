// Name: conversion_specifications.c
// Purpose: Learn and test conversion specifications d & e in C
// Author: AR

// abbreviations
// nod = no. of digits

#include <stdio.h>

int main (void) {
    /* integer conversion specifier- d, used to display an integer in decimal(base 10) form
    1) %-m.pd, m specifies the min. no. of characters to display, p specifies the min. no. of digits to display, "-" means spaces will be added at last, not front
    2) if m > nod adds spaces; if m < nod, m increases to the no. of digits to avoid data loss
    3) if p > nod adds zeroes; if p < nod, p increases to the no. of digits to avoid data loss
    4) if m or p = nod then, no extra spaces or 0s
    5) if we only understand point 2 to the fullest, we can understand any type of expression related to d
    */

    printf("%.3d\n", 8); // p = 3, "8" becomes "008"
    printf("%3d\n", 8); // m = 3, "8" becomes "  8"
    printf("%5.3d\n", 8); // m = 5, p = 3, "8" becomes "  008"
    printf("%3.5d\n", 8); // m = 3, p = 5, here no. characters already exceed m, so no extra spaces, 8 becomes 00008

    // with "-"
    printf("%-.3d\n", 8); // p = 3 with a "-"(but no change in justification/direction becuase it will change the values meaning), "8" becomes "008"
    printf("%-3d9\n", 8); // m = 3 with "-", so space on right side, "8" will become "8  ", full expression = "8  9"
    printf("%-5.3d9\n", 8); // m = 5, p = 3 with "-", "8" becomes "008  ", full expression = "008  9"
    printf("%-3.5d9\n", 8); // m = 3, p = 5, here no. of characters already exceed m, so no extra spaces, 8 becomes 00008

    printf("%.3d\n", 888); // p = 3 but value already of length 3, so no extra zeroes
    printf("%3d\n\n", 888); // m = 3 but value already of length 3, so extra spaces

    // exponential conversion specifier e, has 4 parts: 1 (digit) + 1 (dot) + 6 (precision, 6 is default) + 4 (exponent part) = 12
    // %-m.pe, here m is the same as above, p is the no. of digits to display after decimal. 
    // 1.234e+08 is an example of resultant formatted string in output
    // always remember, "p" and the exponent number shown at last are different, p is the no. of digits to be shown after decimal while the exponent number is the no. in 10^num
    printf("%e\n", 31.4); // extra zeroes in precision because precision is by default of length 6
    printf("%.3e\n", 31.4); // extra zeroes because p = 2
    printf("%e\n", 2147483.647);
    printf("%10e\n", 2147483.647); // here 10 is redundant because the output "2.147484e+06" is already of 12 characters, so no extra space at the beginning
    printf("%10.2e\n", 2147483.647); // here there will be 2 extra spaces in the beginning because total char length = 1 (digit) + 1 (dot) + 2 (precision) + 4 (exponent)
    printf("%15e\n", 2147483.647); // here the formatted string will have 3 extra spaces at the beginning, 15 - 12 = 3
    printf("%.2e\n", 2147483.647);
    printf("%.9e\n", 2147483.647);
    printf("%.15e\n\n", 2147483.647); // extra zeroes are add after decimal if the precision part is completed already

    // using "-"
    printf("%-15ehello\n", 2147483.647); // here the formatted string will have 3 extra spaces after the formatted string, because of the "-"
    printf("%e\n\n", 12345678.987); // just a last example for exponent conversion specifier
    
    // the floating specifier "f" is same as exponent except the fact that the decimal point is not fixed as the 2nd position(index 1) in the whole format string
    // the g specifier displays a number in fixed decimal format or exponent format depending on the size, moreover it will not use decimal point if there's no need(e.g., 1234)
    // the g specifier has many nuances but we don't have time to discuss everything right now
    printf("%g\n", 1234.0);
    printf("%g\n", 1234);
    printf("%g\n", 1234.123);
    printf("%g\n", 123456.9999);
    printf("%g\n\a", 1234567.9999);
    printf("\a");

    return 0;
}
