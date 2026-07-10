// Name: const_pointers.c
// Purpose: To see the behavior of const pointer in C.
// Author: Ayush Raj

#include <stdio.h>

void f(const int *p) {
    *p = 9; // error, trying to assign read only variable

    int j = 99;
    p = &j; // completely valid because "const int *p" means the integer p points to is constant and can't be changed
            // this statement will have no effect since arguments are passed by value
}

// here pointer p is protected
void f2(int *const p) {
    int j;
    *p = 0;
    p = &j; // error
}

// here both the pointer as well as the object the pointer points to is protected
void f3(const int *const p) {
    int j;
    *p = 0; // error
    p = &j; // error
}

int main() {
    // due to the above compiler error, the program does not compile and never goes to the linking phase where it checks the existence of main
    printf("acd\n");

    return 0;
}
