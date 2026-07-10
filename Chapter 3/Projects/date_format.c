// Name: date_format.c
// Purpose: Converts mm/dd/yyyy to yyyymmdd
// Author: Ayush Raj

#include <stdio.h>

int main (void) {
    int d, m, y;
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m, &d, &y);
    
    printf("You entered the date %.4d%.2d%.2d", y, m, d);

    return 0;
}
