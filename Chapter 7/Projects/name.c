// Name: name.c
// Purpose: To display a name in formal short form (last name, initial of first name, ".")
// Author: Ayush Raj

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    char f_init, ch = 0;

    printf("Enter a first and last name: ");
    scanf(" %c", &f_init);

    _Bool flag = false;
    while (f_init != '\n' && ch != '\n') {
        scanf("%c", &ch);

        if (ch == '\n')
            break;

        if (flag && ch != ' ' && ch != '\t')
            printf("%c", ch);

        if (ch == ' ' || ch == '\t')
            flag = true;
    }

    printf(", %c.\n", toupper(f_init));

    return 0;
}
