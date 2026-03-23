// Name: pointers_sizes.c
// Purpose: To see the sizes of different types of pointers.
// Author: Ayush Raj

#include <stdio.h>

// The size of a pointer depends on the architecture of the CPU and the ABI (Application Binary Interface) of the operating system you are compiling for.
// A pointer just stores a memory address; the "type" (int, char, etc.) only tells the compiler how to interpret the data at that address once you dereference it.
// This is the reason why pointers pointing to int, double, char etc., all have the same size.

int main(void) {
    int a, *p = &a;
    printf("%zu %zu %zu\n", sizeof(a), sizeof(*p), sizeof(p));

    char ch, *p2 = &ch;
    printf("%zu %zu\n", sizeof(ch), sizeof(p2));

    float f, *p3 = &f;
    double u, *p4 = &u;
    printf("%zu %zu\n", sizeof(f), sizeof(p3));
    printf("%zu %zu\n", sizeof(u), sizeof(p4));

    return 0;
}
