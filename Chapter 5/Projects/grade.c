// Name: grade.c
// Purpose: To convert numerical grade into a letter grade using switch
// Author: Ayush Raj

#include <stdio.h>
int main(void) {
    int grade, tens_place;
    char l_grade;

    printf("Enter numerical grade: ");
    scanf("%3d", &grade);
    tens_place = grade == 100 ? 0 : grade > 100 || grade < 0 ? -1
                                                             : grade / 10;

    switch (tens_place) {
        case 0:
            if (grade == 100)
                l_grade = 'A';
            else
                l_grade = 'F';
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            l_grade = 'F';
            break;

        case 6:
            l_grade = 'D';
            break;

        case 7:
            l_grade = 'C';
            break;

        case 8:
            l_grade = 'B';
            break;

        case 9:
            l_grade = 'A';
            break;

        default:
            printf("Invalid number grade!\n");
            return 0;
    }

    printf("Letter grade: %c", l_grade);

    return 0;
}
