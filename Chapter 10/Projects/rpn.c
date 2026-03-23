// Name: rpn.c
// Purpose: To evaluate expressions in the RPN Notation, Q6.
// Author: Ayush Raj

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);
int rpn_expr_calc();

int main(void) {
    while (1) {
        int ans = rpn_expr_calc();
        make_empty();
        printf("Value of expression: %d\n", ans);
    }

    return 0;
}

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void push(int i) {
    if (is_full()) {
        stack_overflow();
    }

    else {
        contents[top++] = i;
    }
}

int pop(void) {
    if (is_empty()) {
        stack_underflow();
        return -1;
    }

    else {
        return contents[--top];
    }
}

void stack_overflow(void) {
    printf("Expression is too complex\n");
    exit(1);
}

void stack_underflow(void) {
    printf("Not enough operands in expression\n");
    exit(0);
}

int rpn_expr_calc() {
    printf("Enter an RPN expression: ");

    while (1) {
        char ch;
        scanf(" %c", &ch);

        if (ch == '=') {
            break;
        }

        else if (ch >= '0' && ch <= '9') {
            push(ch - '0');
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int num1 = pop(), num2 = pop();
            switch (ch) {
                case '+':
                    push(num1 + num2);
                    break;
                case '-':
                    push(num2 - num1);
                    break;
                case '*':
                    push(num1 * num2);
                    break;
                case '/':
                    push(num2 / num1);
                    break;
            }
        } else {
            exit(0);
        }
    }

    return pop();
}
