// Name: return_pointers.c
// Purpose: To see how to return pointers in C.
// Author: Ayush Raj

#include <stdio.h>

int *max(int *a, int *b) {
    if (*a > *b) {
        // return &a;   // error, reason 1 is below this function, reason 2 is we need to return a pointer to an int object, not a pointer to a pointer
        return a;
    }
    return b;
}

// never return pointers to automatic local variables as they don' exist after function returns
int *f(void) {
    int i = 9;
    return &i;
}

// an example of why the first max function is the correct one
// since, a and b are automatic local variables, they will be destroyed from memory after max2's execution is complete, so their pointers don't exist after that
int *max2(int a, int b) {
    if (a > b) {
        return &a;
    }
    return &b;
}

int main(void) {
    int i = 12, j = 9;
    printf("%p %d\n", max(&i, &j), *max(&i, &j)); // see the use of * to directly use the value from the pointer returned by max function
    return 0;
}
