// Name: arrays.c
// Purpose: To learn about arrays
// Author: Ayush Raj

#define N 10

#include <stdio.h>

int main(void) {
    int arr[N];
    arr[0] = 9;
    printf("%d %d\n", arr[0], arr[5]);
    printf("%d\n", arr[20]); // accessing out of bounds element

    // any variable of any type in C stores garbage values (whatever value was there before in the memory where the variable is allocated space) if it's not intialized
    // for arrays, all elements can have garbage values if not initalized
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Enter array elements(5): ");
    int arr2[5];
    for (int i = 0; i < 5; i++)
        scanf("%d", &arr2[i]);

    for (int i = 0; i < 5; i++)
        printf("%d ", arr2[i]);
    printf("\n\n");

    // array intialization
    int arr3[10] = {};
    int arr4[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr5[10] = {0};
    int arr6[10] = {0, 9, -7};

    // if an intializer is present then length may be ommited, compiler uses the length of the initializer to determine length of array
    int arr7[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int arr8[10] = {[2] = 29, [6] = 7, [9] = 48};
    int arr9[10] = {[9] = 48, [6] = 7, [2] = 29};

    // length is ommited, so designator can be any non -ve integer, length of array will be the largest designator, length of array10 = 24
    int arr10[] = {[5] = 10, [23] = 13, [11] = 36, [15] = 29};
    int arr11[10] = {5, 1, 9, [4] = 3, 7, 2, [8] = 6};

    printf("arr3\tarr4\tarr5\tarr6\tarr7\tarr8\tarr9\tarr10\tarr11\n");
    for (int i = 0; i < 10; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", arr3[i], arr4[i], arr5[i], arr6[i], arr7[i], arr8[i], arr9[i], arr10[i], arr11[i]);

    // Note
    int z[] = {1, 2, 3};
    // z[] = {11, 22, 33};  // after initializing an array, we cannot change it like this

    return 0;
}
