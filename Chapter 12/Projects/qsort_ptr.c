// Name: qsort_ptr.c
// Purpose: To update the qsort.c program to use pointers.
// Author: Ayush Raj

#include <stdio.h>

void quicksort(int a[], int *low, int *high);
int *split(int a[], int *low, int *high);

int main(void) {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for (int *p = arr; p < arr + n; p++) {
        scanf("%d", p);
    }

    quicksort(arr, arr, arr + n - 1);
    printf("Sorted array: ");
    for (int *p = arr; p < &arr[n]; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    return 0;
}

void quicksort(int a[], int *low, int *high) {
    if (low >= high) {
        return;
    }

    int *mid = split(a, low, high);
    quicksort(a, low, mid - 1);
    quicksort(a, mid + 1, high);
}

int *split(int a[], int *low, int *high) {
    int partition_element = *low;

    for (;;) {
        while (low < high && partition_element <= *high)
            high--;
        if (low >= high)
            break;
        *low = *high;
        low++;

        while (low < high && *low <= partition_element)
            low++;
        if (low >= high)
            break;
        *high = *low;
        high--;
    }
    *high = partition_element;
    return high;
}
