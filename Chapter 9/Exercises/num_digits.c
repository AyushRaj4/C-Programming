// Name: num_digits.c
// Purpose: To find the no. of digits in a number
// Author: Ayush Raj

#include <math.h>
#include <stdio.h>

int num_digits(int n);
int num_digits2(int n);
int num_digits3(int n);

int main(void) {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int digits = num_digits3(num < 0 ? num * -1 : num); // use any of the 3 functions, all are correct
    printf("%d has %d digit(s).\n", num, digits);

    return 0;
}

int num_digits(int n) {
    int c = 0;
    while (n != 0) {
        n /= 10;
        c++;
    }
    return c;
}

// best
int num_digits2(int n) {
    return n == 0 ? 1 : (int)log10(n) + 1;
}

// recursion
int num_digits3(int n) {
    if (n == 0)
        return 0;
    return num_digits3(n / 10) + 1;
}
