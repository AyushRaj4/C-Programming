// Name: vla.c
// Purpose: To understand VLAs
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    int n = 10;

    // Basically an array is a VLA if its length is defined through a variable, not a constant
    // In this case, the length of the array is computed when the program is executed, not when it is compiled
    // int arr[n] = {1, 2, 3};  VLAs can't be initialized
    int arr[n];

    return 0;
}
