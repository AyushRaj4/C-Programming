// Name: rawxor.c
// Putpose: To implement a simple file encryptor in C.
// Author: Ayush Raj

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 16

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Less arguments!\n");
        exit(EXIT_FAILURE);
    }

    // opening input file in read mode
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Check if %s exists!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // opening output file in write mode
    FILE *fp2 = fopen(argv[2], "w");
    if (fp2 == NULL) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    // this is the key used to encrypt the message
    unsigned char key = (unsigned char)argv[3][0]; // explicitly casted to clarify the reader as well as compiler to strictly convert it
    while (true) {
        // reading 16 bytes from stream fp into buffer
        size_t n = fread(buffer, 1, 16, fp);

        // if all bytes are read we end loop because nothing to encrypt
        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            buffer[i] ^= key;
        }

        // writing 16 bytes from buffer into stream fp2
        size_t n2 = fwrite(buffer, 1, n, fp2);
        // printf("%zu %zu\n", n, n2);
    }

    if (feof(fp)) {
        printf("Reached end of file.\n");
        printf("File encrypted!\n");
    }
    if (ferror(fp)) {
        printf("Error in reading file\n");
    }

    fclose(fp);
    fclose(fp2);

    return 0;
}
