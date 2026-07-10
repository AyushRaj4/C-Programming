// Name: scanf_errors.c
// Purpose: To see how scanf can ause errors if not handled proeprly.
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    int a, *p = &a;
    /*
     * very dangerous, value of input will be stored in p which causes undefined behavior, p might access unauthorized memory and program may crash
    scanf("%d", &p);
    printf("%p %d %d\n", p, *p, a);
    */

    printf("Enter a number: ");
    scanf("%d", p); // valid because p = &a
    printf("%d\n", a);

    return 0;
}
