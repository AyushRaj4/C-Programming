// Name: binary.c
// Purpose: To print the binary of a +ve integer.
// Author: Ayush Raj

#include <stdio.h>

void pb(int num); // pb name is from q19 in exercises, probably means print binary

int main(void) {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Binary of %d: ", num);
    pb(num);
    printf("\n");

    return 0;
}

void pb(int n) {
    if (n != 0) {
        pb(n / 2);
        putchar('0' + n % 2);
    }
}
