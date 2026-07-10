// Name: fibonacci.c
// Purpose: To fill the 1st 40 numbers in the fibonacci sequence in an array.
// Author: Ayush Raj

#define FIBO_LEN 40
#include <stdio.h>

int main(void) {
    long long fibo[FIBO_LEN]; // used long long because the numbers in the sequence can get very large pretty fast

    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < FIBO_LEN; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    printf("Fibonacci sequence till %dth element:\n", FIBO_LEN);
    for (int i = 0; i < FIBO_LEN; i++)
        printf("%lld ", fibo[i]);
    printf("\n");

    return 0;
}
