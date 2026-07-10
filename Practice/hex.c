// Explaination: https://share.gemini.google/xnqrQYVhsy43

#include <stdio.h>

int main() {
    unsigned int val = 0x12345678;
    unsigned char *ptr = (unsigned char *)&val;

    printf("0x%x\n", *(ptr + 1));
    return 0;
}
