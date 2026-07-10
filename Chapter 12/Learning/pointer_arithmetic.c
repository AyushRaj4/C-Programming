// Name: pointer_arithmetic.c
// Purpose: To see pointer arithmetic and how it works in an array.
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p = &a[0]; // this can be in the same line as the array declaration or intialization but after it
    printf("%d %d\n", *p, *(p + 1));

    p = &a[2];      // points to 2nd index
    int *q = p + 3; // q points to 5th index
    p += 6;         // p points to 8th index

    printf("%d %d\n", *p, *q);

    q = p - 3;
    p -= 6;
    printf("%d %d\n", *p, *q);

    // When we subtract two pointers of the same type (like p - q), the result isn't the number of bytes between them; it's the number of elements.
    printf("%d %d\n", (int)(p - q), (int)(q - p));
    printf("%ld %td\n", p - q, q - p); // td is the conversion specifier for printing values of type ptrdiff_t which represents the result of subtracting 2 pointers
                                       // ld will also work here because ptrdiff_t and long int are same on most systems but they are conceptually different
                                       // it's better to use td for pointer subtraction for portable code

    // comparing pointers
    p = q;
    printf("%d %d %d\n", p == q, p <= q, p > q); // using relational operators (<, > etc.) on pointers is useful only if both pointers point to elements of the same array
    p = &a[0];
    q = &a[9];
    printf("%d %d\n", p == q, p != q);

    // compound literals
    int *r = (int[]){3, 9, -22, 4}; // we can use pointers to point to an array created with compound literals, this saves us the time of declaring the array first
    printf("%d %p\n", *r, r);

    return 0;
}
