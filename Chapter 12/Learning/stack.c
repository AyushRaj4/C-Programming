// Name: stack.c
// Purpose: To implement a simple stack using pointers.
// Author: Ayush Raj

#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int *top_ptr = &contents[0];

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);

int main(void) {
    push(10);
    printf("%d\n", is_empty());
    make_empty();
    printf("%d\n", is_empty());
    push(20);
    printf("%d\n", pop());
    printf("%d\n", is_full());

    for (int i = 1; i <= 100; i++) {
        push(1);
    }
    printf("%d\n", is_full());

    return 0;
}

void make_empty(void) {
    top_ptr = &contents[0];
}

bool is_empty(void) {
    return top_ptr == &contents[0];
}

bool is_full(void) {
    return top_ptr == &contents[STACK_SIZE];
}

void push(int i) {
    if (is_full()) {
        printf("Stack Overflow!\n");
    } else {
        *top_ptr++ = i;
    }
}

int pop(void) {
    if (is_empty()) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return *--top_ptr;
    }
}
