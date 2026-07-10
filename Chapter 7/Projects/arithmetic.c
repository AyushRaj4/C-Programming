// Name: arithmetic.c
// Purpose: To evaluate an expression (from left to right, no precedence) input by a user containing +, -, * and /.
// Author: Ayush Raj

#include <stdio.h>

int main(void) {
    char ch, op = 0;
    float ans = 0;

    printf("Enter an expression: ");
    scanf(" %c", &ch);

    float x = 10;
    while (ch != '\n') {
        if (ch >= '0' && ch <= '9') {
            if (op == '.') {
                ans += 1 / x * (ch - '0');
                x *= 10;
            }

            else if (op == '+') {
                ans += ch - '0';
                x = 10.0f;
            }

            else if (op == '-') {
                ans -= ch - '0';
                x = 10.0f;
            }

            else if (op == '*') {
                ans *= ch - '0';
                x = 10.0f;
            }

            else if (op == '/') {
                ans /= ch - '0';
                x = 10.0f;
            }

            else
                ans = ch - '0';
        }

        else if (ch == '.')
            op = '.';

        else if (ch == '+')
            op = '+';

        else if (ch == '-')
            op = '-';

        else if (ch == '*')
            op = '*';

        else
            op = '/';

        scanf("%c", &ch);
    }

    printf("Value of expression: %f\n", ans);

    return 0;
}
