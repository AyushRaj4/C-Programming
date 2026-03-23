// Name: arrays_functions.c
// Purpose: To see the behaviour of arrays (1D and multi-D) with functions.
// Author: Ayush Raj

#include <stdio.h>

// void arr_func1(int arr[]);  calling a function with only its prototype will give an error
void arr_func1(int arr[]) {}

void arr_func2(int arr[8]) {} // don't provide size in array parameter because the size is ignored by the compiler and it looks like a misconception

// void multid_arr(int arr[][]);  it's compulsory to provide column size and it should not be arbitrary but accurate
// the reason column size is necessary and cannot be arbitrary because multi-D matrices are stored in a linear fashion in memory (row major form), so the calculation of memory addresses will be wrong if the column size is arbitrary, see the formula: Address = Base_Address + (row_index * Total_Columns + column_index) * sizeof(Type), Total_Columns is the column size, as we can see the row size is not in the formula so no need (and in fact, better) to not write the row size (total rows).
void multid_arr(int arr[][5]) {}

int main(void) {
    /* 1D ARRAYS */

    int arr1[] = {0, 1, 2};
    arr_func1(arr1);
    // arr_func1({1, 2, 3});  error because the function expects a pointer, arrays passed as argument decay to pointers, the compiler has no idea what to do with this raw list
    arr_func1((int[]){1, 2, 3}); // compound literal, it's like type casting telling the compiler to treat the list as an array, ignore the red highlighting
                                 // more about compound literals in C book and also in vla_functions.c

    int arr2[100];
    arr_func2(arr2);
    // obviously 2d multi-D arrays should not be passed to function expecting 1D array

    /* 2D ARRAYS */

    int a[][6] = {0};
    int a2[100][5] = {};
    // scanf("%d", &a[0][6]);  error
    // scanf("%d", &a[1][5]);  segmentaion fault

    multid_arr(a);  // error, size mismatch
    multid_arr(a2); // no error

    printf("\nProgram ran!\n");

    // Some more points (more might be added later):
    // * A function is allowed to change the elements of an array parameter, and the change is reflected in the corresponding argument, reason is the argument array decays to a pointer when passed to the function and pointers follow pass by reference (this will be explained more clearly later when we study pointers in detail)

    return 0;
}
