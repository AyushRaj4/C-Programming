// Name: prime.c
// Purpose: To check if a number is prime or not.
// Author: Ayush Raj

#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    // if I declare i inside for loop again, then the outer i and inner i are 2 separate variables, did this purposefull just for notes.
    int i;
    for (i = 2; i * i <= num; i++) {
        if (!(num % i)) {
            return false;
        }
    }
    return num > 1 && true;
}

int main(void) {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (is_prime(num)) {
        printf("Prime\n");
    }

    else {
        printf("Not Prime\n");
    }

    return 0;
}
