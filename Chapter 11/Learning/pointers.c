// Name: pointers.c
// Purpose: To learn about pointers and experiment on them.
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    // a pointer is an address to an object, a pointer variable is a variable which stores the address
    int a = 1;
    // int *p = a;  wrong
    int *p = &a; // use of address opearator is necessary to point to a variable or object
                 // the * here is not the indirection operator, just a normal asterisk to specify that p is a pointer to an int object

    // *p = &a;  // error, address of a is assigned to itself

    int b, *p2 = &b;
    printf("%d %d\n", *p, *p2); // indirection operator used to access the value stored in the object the pointer points to

    *p = 10, *p2 = 9;
    printf("%d %d %d\n", a, b, *&a);
    printf("%p %p %p %p\n", p, p2, &a, &b); // p conversion specifier is used for pointers to display addresses in hexadecimal
                                            // p and p2 are pointer variables while &a and &b are addresses/pointers (Address is a better term here)
                                            // p and &a are same because p points to a, same for p2 and &b

    int c = 3, *q = &c, *r;
    r = q; // pointer assignment
    *r = 5;
    printf("%d %d %d\n", c, *q, *r);
    printf("%p %p\n", q, r); // addresses same, both point to same object

    int d = -9;
    int *q2 = &c, *r2 = &d;
    *r2 = *q2;                 // not a pointer assignment, value of c is copied to d
    printf("%p %p\n", q2, r2); // addresses not same, both point to different objects

    return 0;
}
