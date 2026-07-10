// Name: function_errors.c
// Purpose: To understand which rule breaks cause error in functions in C99.
// Author: Ayush Raj

#include <stdio.h>

// older function declaration style where "()" was left empty(becuase compiler was not designed to match parameters and arguments bw the declaration and definition), not be used now in any version
void func1();

int main(void) {
    int b = a();
    r();

    printf("Program ran!\n");

    return 0;
}

// conflicting declaration of this function above
void func1(int a) {}

int a() {}
void r() {}

// SUMMARY
// IMPLICIT DECLARATIONS ARE NOT SUPPORTED IN C>=99
// DON'T DEFINE FUNCTIONS AFTER THEIR CALLS IF THERE IS NO DECLARATION
// STANDARD WAY IS TO PROVIDE DECLARATION THEN USE
// FOR MORE DETAIL SEE SECTION 9.2 IN THE C BOOK
