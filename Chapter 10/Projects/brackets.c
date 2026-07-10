// Name: brackets.c
// Purpose: To check if the series of brackets are nested properly or not.
// Author: Ayush Raj

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
char pop(void);
void stack_overflow(void);
bool are_nested_properly(void);

int main(void) {
    printf("Enter brackets () or [] or {}: ");
    if (are_nested_properly()) {
        printf("Brackets are nested properly.\n");
    } else {
        printf("Brackets are not nested properly.\n");
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
    } else {
        contents[top++] = i;
    }
}

char pop(void) {
    if (is_empty()) {
        // printf("Stack Underflow!\n");
        return '\0';
    } else {
        return contents[--top];
    }
}

void stack_overflow(void) {
    printf("Stack overflow\n");
    exit(1);
}

bool are_nested_properly(void) {
    char bracket_ch;

    for (;;) {
        bracket_ch = getchar();

        if (bracket_ch == '\n')
            break;

        else if (bracket_ch == '(' || bracket_ch == '{' || bracket_ch == '[') {
            push(bracket_ch);
        }

        else if (bracket_ch == ')' || bracket_ch == '}' || bracket_ch == ']') {
            char ch = pop();
            if (ch == '\0')
                return false;

            // Sum of ASCII values of () = 81, [] = 184, {} = 248
            if (ch + bracket_ch != 81 && ch + bracket_ch != 184 && ch + bracket_ch != 248) {
                return false;
            }
        }
    }

    if (is_empty()) {
        return true;
    }
    return false;
}
