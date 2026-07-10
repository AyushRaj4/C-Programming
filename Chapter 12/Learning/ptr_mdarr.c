// Name: ptr_mdarr.c
// Purpose: To understand how pointers work with multidimensional arrays (mostly same as 1D arrays).
// Author: Ayush Raj

#include <stdio.h>

#define NUM_ROWS 3
#define NUM_COLS 3

int find_largest(int a[], int n) {
    int i, max;
    max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int main(void) {
    int a[NUM_ROWS][NUM_COLS];

    // initalizing a 2D array with 0s, treating it like a 1d array using pointers, C stores multidimensional arrays in the same way in row major form
    // we can use just a[0] also as it points to a[0][0]
    for (int *p = &a[0][0]; p <= &a[NUM_ROWS - 1][NUM_COLS - 1]; p++) {
        *p = 0;
    }

    for (int *p = &a[0][0]; p <= &a[NUM_ROWS - 1][NUM_COLS - 1]; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    // intializing a row of a 2d array, 1st method
    for (int *p = &a[2][0]; p <= &a[2][NUM_COLS]; p++) {
        *p = 1;
    }

    for (int *p = &a[0][0]; p <= &a[NUM_ROWS - 1][NUM_COLS - 1]; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    // 2nd method, just using a[i] instead of &a[i][0], both do the same thing
    for (int *p = a[1]; p < a[1] + NUM_COLS; p++) {
        *p = 2;
    }

    for (int *p = &a[0][0]; p <= &a[NUM_ROWS - 1][NUM_COLS - 1]; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    // a bit of a new concept
    // int(*p)[10];  this declaration means that p is a pointer which points to an array of 10 elements

    // PROCESSING THE COLUMNS OF A MULTIDIMENSIONAL ARRAY
    // &a[0] is the pointer/address to the 1st row of the 2d array, when p++ is executed, the pointer jumps an entire row
    // a pointer jumps the whole number of bytes it's pointing 2 when p++ is executed
    // this means that pointers can point to many different things in C other than just numbers
    // &a[i][0] is a pointer/address to 1st element in ith row
    // a[i] is a pointer doing the same thing as above, it's just more concise
    // &a[i] is completely different from &a[i][0] or a[i] because the former is pointing to a whole array
    int(*p)[NUM_COLS];
    for (p = &a[0]; p < &a[NUM_ROWS]; p++) {
        (*p)[1] = 9;
    }

    for (int *p = &a[0][0]; p <= &a[NUM_ROWS - 1][NUM_COLS - 1]; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    // all 3 have the same address but as explained above &a[0] and (&a[0][0], a[0]) are completely different
    printf("%p %p %p\n", &a[0][0], a[0], &a[0]);

    // USING NAME OF A MULTIDIMENSIONAL ARRAY AS A POINTER
    // updated column processing loop of 2d array, usign array name
    // a is th same as &a[0] when used in an expression, a decays to type int (*) [NUM_COLS] while &a[0] is laready of that type as we saw in earlier example
    for (p = a; p < a + NUM_ROWS; p++) {
        (*p)[0] = 8;
    }

    for (int *p = &a[0][0]; p <= &a[NUM_ROWS - 1][NUM_COLS - 1]; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    // we can trick the compiler to treat a multidimensional array as a 1d array if we pass the correct pointer
    // largest = find_largest(a, NUM_ROWS * NUM_COLS);  // wrong call because as we know 'a' decays to a pointer to an array, find_largest is expecting int* (pointer to an integer)
    // the above call is wrong not because of the pointers/addresses ('a' points to the same address) but the types don't match
    printf("%d\n", find_largest(a[0], NUM_ROWS * NUM_COLS));

    return 0;
}

// POINTS TO REMEMBER
// A 1d array decays to a pointer to the 1st element in the array
// A multidimensional array decays to a a pointer to it's 1st child, e.g., a 2d array decyas to pointer to a 1d array, a 3d array points to 2d and so on.
