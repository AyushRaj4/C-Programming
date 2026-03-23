// Name: quicksort.c
// Purpose: To implement the quicksort algorithm (not the most effecient).
// Author: Ayush Raj

// NOTE:- FUNCTION DECLARATIONS ARE VERY IMPORTANT, THEY IMPROVE READABILITY AND ALSO MAKE MUTUAL RECURSION POSSIBLE, E.G., FUNCTION 1 CALLS FUNCTION 2 AND FUNCTION 2 CALLS FUNCTION 1 IT'S PHYSICALLY IMPOSSIBLE TO DEFINE ONE FUNCTION ABOVE THE OTHER. WITH PROTOTYPES WE DECLARE BOTH AT TOP AND THE COMPILER IS HAPPY.

#include <stdio.h>

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

int main(void) {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quicksort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void quicksort(int a[], int low, int high) {
    if (low >= high)
        return;

    int mid = split(a, low, high);
    quicksort(a, low, mid - 1);
    quicksort(a, mid + 1, high);
}

int split(int a[], int low, int high) {
    int partition_element = a[low];

    for (;;) {
        while (low < high && partition_element <= a[high])
            high--;
        if (low >= high)
            break;
        a[low++] = a[high];

        while (low < high && a[low] <= partition_element)
            low++;
        if (low >= high)
            break;
        a[high--] = a[low];
    }
    a[high] = partition_element;
    return high;
}
