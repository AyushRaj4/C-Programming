// Name: vla_functions.c
// Purpose: To see the use of VLAs in functions in C.
// Author: Ayush Raj

// IF YOU DON'T HAVE MUCH TIME, SEE THE SUMMARY AT THE END OF FILE TO REVISE, OTHERWISE READ WHOLE. DON'T FORGET TO REVISE FROM BOOK ALSO ON THIS TOPIC.
// NOTE:- I have done many experimentations in this code because many of the results were not explicitly stated in the book, these experiments are for learning puproses only.
// When creating a project the best way is to follow all the rules strictly and improve code if we get a warning or error, these experiments help me to avoid many mistakes in the future provided I remember the experiments.

#include <stdio.h>

// void func1(double);  //if we use this prototype we will get errors for the below ones, because the compiler considers the 1st one as the valid one

// all these protypes are equivalent, except there is one catch
// the 1st prototype is the most robust one to tell the commpiler about the function, so we will get warnings/errors during buffer overflows and wrong memory access
// so it's better to stick with the 1st one although we might get small warnings with the other ones also but still they are (warnings) are worse than the 1st one
void func1(int n, int a[n]);
void func1(int n, int[*]);
void func1(int, int[*]);
void func1(int n, int a[]);
// void func1(double, double);  //error, conflicting types for func1

// the compiler will consider the 1st protype as the correct one always
/*
void func2(double);
void func2(int);
*/

// possible protypes for a function having 2D VLA as parameter
int sum_two_dimensional_array(int n, int m, int a[n][m]);
int sum_two_dimensional_array(int n, int m, int a[*][*]);
int sum_two_dimensional_array(int n, int m, int a[][m]);
int sum_two_dimensional_array(int n, int m, int a[][*]);

// using static does not change the behaviour of code but still we must provide atleast n elements in passing array because we used "static n"
void static_example(int n, int a[static n]);

int main(void) {
    /* 1D VLAs with functions*/

    // func1 has vla as parameter but ultimately the size of array is decided by the number in "int[]" or "int arr[]" either in compound litera or normal array declaration
    // trying to print the last 4 elements will result in garbage values, sometimes undefined behavior like in 3rd func1 call, run program for clarity
    // we will get an error/warning after running program because we are trying to access 32 bytes but the array is 16 bytes, the error is because we used vla
    func1(8, (int[]){1, 2, 3, 4});  // size of array is 4
    func1(8, (int[4]){1, 2, 3, 4}); // size of array is still 4

    // arr and arr2 are adjacent in stack, we can say that becuase in output, the last 4 elements we try to print for arr are the same as the 1st 4 elements of arr2
    // try changing arr2 and we can prove it 100%
    int arr[4] = {1, 2, 3, 4};
    int arr2[4] = {7, 9, 2, 1};
    func1(8, arr);
    func1(8, arr2);
    printf("\n");

    // as we can see, int[8] is the part that makes the array of size 8, not because we used vla as parameter in func1
    // compound literals and initializers obey the same rules
    // they are not required to provide full initialization (rest will be 0) and they can contain designators also
    func1(8, (int[8]){1, 2, 3, 4});          // size of array is 8 now
    func1(8, (int[8]){1, 2, 3, 4, [7] = 8}); // size of array is 8
    printf("\n");

    /* 2D VLAs with functions */

    // will get error for 1st sum if we the value of row_size in compound literal [] is less than n, this is probably becuase we are directly providing the values instead of a pre-defined array, so compiler knows that it's a guaranteed buffer overflow
    int b[1][2] = {1};
    int sum = sum_two_dimensional_array(2, 3, (int[][3]){1, 2, [1][1] = 47});
    int sum2 = sum_two_dimensional_array(2, 3, b);
    printf("Sum of 2D array = %d\n", sum);

    return 0;
}

// cannot use * in definition
// void func1(int n, int a[*]) {}

void func1(int n, int a[n]) {
    // Sizeof an array function parameter will return the size of "int *" instead of "int [n]", 8 bytes for my sytem (64-bit)
    printf("Size using sizeof: %zu\n", sizeof(a));
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int sum_two_dimensional_array(int n, int m, int a[n][m]) {
    int i, j, sum = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            sum += a[i][j];
    return sum;
}

/*
SUMMARY of VLA and Array Parameter Experiments

- Array Decay in Functions: Regardless of whether a parameter is declared as int a[n], int a[], or int *a, it "decays" into a simple pointer. Consequently, sizeof(a) inside a function will return the size of a pointer (8 bytes on 64-bit systems) rather than the total size of the array.

- The "Hint" vs. Reality Rule: The n in a VLA parameter (like void func1(int n, int a[n])) is merely a hint to the compiler for safety checks; it does not determine the actual size of the array passed to it. The real memory size is determined solely by the array's declaration (e.g., int arr[4]) or the explicit size in a compound literal (e.g., (int[8]){...}).

- VLA Parameter Safety: Using the VLA syntax void func(int n, int a[n]) is the most robust prototype. It establishes a formal link between the size variable n and the array a, allowing the compiler to perform static analysis and issue [-Wstringop-overflow] warnings if you pass an array that is too small.

- Memory Bleeding (Buffer Over-read): Variables declared sequentially in code (like arr and arr2) are often adjacent on the stack. If a function reads past the bounds of the first array, it will "bleed" into the memory of the second array, printing its values as if they were part of the first.

- Compound Literal Visibility: The compiler has high visibility into compound literals. If you define a literal as (int[1][3]){...} but tell the function to read 2 rows, the compiler can "prove" the overflow and will likely throw an error immediately.

- Static in Parameters: Using static in a VLA parameter like int a[static n] is a guarantee to the compiler that the array is non-null and contains at least n elements. While it doesn't change the program's output, it allows for "prefetching" optimizations and stricter compiler warnings.

- Prototype Compatibility: Multiple prototypes for the same function are allowed as long as the types are compatible (e.g., int a[n][m] and int a[][m]). However, once a "Contract" is set by the first prototype, any incompatible subsequent declaration will cause a compilation error.
*/
