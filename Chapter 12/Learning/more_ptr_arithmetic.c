// Name: more_ptr_arithmetic.c
// Purpose: To process arrays using pointers.
// Author: Ayush Raj

#include <stdio.h>

#define N 5

int main(void) {
    int a[N] = {1, 2, 3, 4, 5};

    int sum = 0;
    int *p;
    for (p = &a[0]; p < &a[N]; p++) { // no problrm for accessing a[N] becuase we are not examining or using it
        sum += *p;
    }
    printf("%d\n", sum);

    p = &a[0]; // we can subscript any index (p[0], p[N - 1], etc.) as long as we don't go out of bounds (not access unauthorized memory)
    int b = 9, *p2 = &b;
    printf("%d %d %d\n", p[1], p2[0], p2[1]); // pointer subscripting is allowed, we should take care not to access unauthorized memory, examining p2[1] can be disastrous

    // using * with ++
    int *q = &a[0];
    // the below operations can be formed by mixing * (indirection operator) and post or pre ++ operators
    printf("%d ", *q++);   // Value of *q, then move pointer q to next element
    printf("%d ", (*q)++); // Value of *q, then increment the value stored at that address
    printf("%d ", *++q);   // Move pointer q to next element, then get value at that new address
    printf("%d\n", ++*q);  // Increment value at current address, then get that new value/ *q++, (*q)++, *++q, ++*q

    return 0;
}
