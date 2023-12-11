#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct node{
    int top;
    int data[max];
}Stack;

void push(Stack *s, int item) {
    if (s->top < max) {
        s->data[s->top] = item;
        s->top++;
    } else {
        printf("Stack is full!\n");
    }
}

int pop(Stack *s) {
    int item;

    if (s->top == 0) {
        printf("Stack is empty!\n");
        return -1; // Return a sentinel value to indicate error
    } else {
        s->top--;
        item = s->data[s->top];
        return item;
    }
}

int main() {
    Stack mystack;
    int item;
    mystack.top = 0;

    push(&mystack, 1);
    push(&mystack, 2);
    push(&mystack, 3);

    item = pop(&mystack);
    if (item != -1) {
        printf("Item is %d\n", item);
    }

    item = pop(&mystack);
    if (item != -1) {
        printf("Item is %d\n", item);
    }

    return 0;
}
