// Name: sizeof.c
// Purpose: To learn the size of int, short, long, float, double and long double using sizeof operator
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    printf("1) Printing the sizes of different types using sizeof in C89:\n");
    printf("Size of short = %lu\n", (unsigned long)sizeof(short));
    printf("Size of int = %lu\n", (unsigned long)sizeof(int));
    printf("Size of long = %lu\n", (unsigned long)sizeof(long));

    printf("\n");

    // in my machine the size_t type is actually unsigned long int, the reason I casted sizeof expression to unsigned int is coz I know the value will be small and int can cover it, still in C89 the best approach is to convert the sizeof expression's type to the largest type available (unsigned long in C89)
    printf("Size of float = %u\n", (unsigned int)sizeof(float));
    printf("Size of double = %lu\n", sizeof(double)); // proof that size_t on my machine is unsigned long int
    printf("Size of long double = %lu\n", sizeof(long double));

    // In C99, we just need to use the letter z before the conversion specifier, no need of casting of the sizeof expression
    printf("\n2) Printing the sizes of different types using sizeof in C99:\n");
    printf("Size of short = %zu\n", sizeof(short));
    printf("Size of int = %zu\n", sizeof(int));
    printf("Size of long = %zu\n", sizeof(long));

    printf("\n");
    printf("Size of float = %zu\n", sizeof(float));
    printf("Size of double = %zu\n", sizeof(double));
    printf("Size of long double = %zu\n", sizeof(long double));

    return 0;
}
