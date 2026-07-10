// Name: type_conversions.c
// Purpose: To understand implicit and explicit type conversions in C
// Author: Ayush Raj

#include <stdint.h>
#include <stdio.h>

int main(void) {
    char c;
    short s;
    int i;
    unsigned int u;
    long int l; // long for short
    unsigned long int ul;
    long long int ll;
    unsigned long long int ull;

    float f;
    double d;
    long double ld;

    i = i + c;   /* c is converted to int */
    i = i + s;   /* s is converted to int */
    u = u + i;   /* i is converted to unsigned int */
    l = l + u;   /* u is converted to long int */
    ul = ul + l; /* l is converted to unsigned long int */
    f = f + ul;  /* ul is converted to float */
    d = d + f;   /* f is converted to double */
    ld = ld + d; /* d is converted to long double */

    // during assignment, follow the simple rule that the expression on the right side of the assignment operator converts to the type of the left side variabe
    i = 666;
    c = i; // c will get garbage value as 666 is out of range for char
    printf("%c, %d\n", c, i);
    printf("%d\n", i = 6667.77f);

    // C99 has a bit different rules for implicit type conversion but it's generally the same idea as C89, refer to book.

    // casting
    int a = (int)67.89;
    printf("%d\n", a);

    float quotient, quotient2;
    int dividend = 5, divisor = 2;

    quotient = dividend / divisor;         // first division then implicit conversion
    quotient2 = (float)dividend / divisor; // first value of dividend converts to float, then divisor value becomes float, then divison

    printf("%.1f vs %.1f\n", quotient, quotient2); // from the output we can determine why the 2nd one is better

    long j, j2;
    int x = 100000;
    j = x * x;        // j gets garbage value because x * x is an int and the value from the multiplication becomes out of range
    j2 = (long)x * x; // j2 gets correct value because both values of x become long before multiplication

    printf("%ld vs %ld\n", j, j2);

    return 0;
}
