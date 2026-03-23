// Name: seven_segment.c
// Purpose: To display numbers in seven segment display.
// Author: Ayush Raj

#include <stdio.h>

#define MAX_DIGITS 10
#define NUM_ROWS 3
#define SEG_ROWS 10
#define SEG_COLS 7

const int segments[SEG_ROWS][SEG_COLS] = {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1}, {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1}, {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};

char digits[NUM_ROWS][MAX_DIGITS * 4];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void) {
    clear_digits_array();

    int c = 0;
    printf("Enter a number: ");
    for (;;) {
        char ch;
        scanf("%c", &ch);

        if (ch == '\n' || c >= MAX_DIGITS) {
            break;
        }

        if (ch >= '0' && ch <= '9') {
            process_digit(ch - '0', c * 4);
            c++;
        }
    }

    print_digits_array();

    return 0;
}

void clear_digits_array(void) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < MAX_DIGITS * 4; j++) {
            digits[i][j] = ' ';
        }
    }
}

void process_digit(int digit, int position) {
    // We are mapping all the segments to their specific rows and columns in the number, e.g., segment 0 will always be maped to row 0 and column position + 1
    /*
    for (int i = 0; i < SEG_COLS; i++) {
        int row = 0, col = 0;
        if (segments[digit][i]) {
            if (i == 0 || i == 3 || i == 6) {
                col = 1;
            } else if (i == 1 || i == 2) {
                col = 2;
            }

            if (i == 1 || i == 5 || i == 6) {
                row = 1;
            } else if (i >= 2 && i <= 4) {
                row = 2;
            }

            if (col == 1) {
                digits[row][position + col] = '_';
            } else {
                digits[row][position + col] = '|';
            }
        }
    }
    */

    // We can hard code which segment goes to which row and which column because a segment will have the same position in any number
    const int seg_row[7] = {0, 1, 2, 2, 2, 1, 1};
    const int seg_col[7] = {1, 2, 2, 1, 0, 0, 1};

    for (int i = 0; i < SEG_COLS; i++) {
        if (segments[digit][i]) {
            int row = seg_row[i];
            int col = seg_col[i];

            // If it's the middle column, it's an underscore. Otherwise, a pipe.
            digits[row][position + col] = (col == 1) ? '_' : '|';
        }
    }
}

void print_digits_array(void) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < MAX_DIGITS * 4; j++) {
            printf("%c", digits[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
