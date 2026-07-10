// Name: hex_dump.c
// Purpose: I will know after making it.
// Author: Ayush Raj

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    // we only want to open one file
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1; // Exit early with an error code
    }

    // 1st element is the file name, rest are arguments provided in the terminal
    /*
    for (int i = 0; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    */

    FILE *fp = fopen(argv[1], "r");
    // if ((fp = fopen(argv[1], "r")) == NULL), shortcut
    if (fp == NULL) {
        printf("Error opening file, check if %s exists!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[16];
    size_t c = 0;
    while (true) {
        size_t n = fread(buffer, 1, 16, fp);
        if (n == 0) {
            // Offset
            printf("%.8zx\n", c);
            break;
        }

        // offset
        printf("%.8zx ", c);
        c += n;

        // hex dump
        for (int i = 0; i < n; i++) {
            printf("%.2x ", buffer[i]);
        }

        if (n < 16) {
            for (int i = 1; i <= (16 - n) * 2 + (16 - n); i++) {
                printf(" ");
            }
        }

        // ASCII print
        for (int i = 0; i < n; i++) {
            if (isprint(buffer[i])) {
                printf("%c", buffer[i]);
            } else {
                printf(".");
            }
        }
        printf("\n");

        // if less than 16 bytes are left to process we break out of loop after last offset
        if (n < 16) {
            if (feof(fp)) {
                printf("%.8zx\n", c);
            }
            if (ferror(fp)) {
                printf("Error in reading file\n");
            }
            break;
        }
    }
    // にほんごをかきます

    printf("\n");

    fclose(fp);

    return 0;
}
