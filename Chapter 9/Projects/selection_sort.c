// Name: selection_sort.c
// Purpose: To perform selection sort on a series of numbers.
// Author: Ayush Raj

#include <stdio.h>

void selection_sort(int arr[], int n);

int main(void) {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    selection_sort(arr, n);
    printf("Sorted array after selection sort: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void selection_sort(int a[], int n) {
    if (n == 0)
        return;
    ;

    int max_i = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[max_i])
            max_i = i;
    }
    int temp = a[max_i];
    a[max_i] = a[n - 1];
    a[n - 1] = temp;

    selection_sort(a, n - 1);
}
