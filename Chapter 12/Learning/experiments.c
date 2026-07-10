// Name: experiments.c
// Purpose: No purpose, have fun.
// Author: Ayush Raj

#include <stdio.h>

void fn(int a[]) {
    int b[9];
    a = b;
}

int main(void) {
    // GGs
    int z[10];
    for (int i = 0; i < 10; i++) {
        i[z] = 9;
        printf("%d ", i[z]);
    }
    printf("\n");

    int a[9];
    *(a + 2) = 3;
    printf("%d\n", a[2]);

    return 0;
}
