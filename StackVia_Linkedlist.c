#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *ptr;
}*top, *topextra, *temp;

int count = 0;

void push(int data) {
     if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
    printf("Node is Inserted\n\n");
}

int pop() {
     topextra = top;
 
    if (topextra == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
        topextra = topextra->ptr;
        
    int popped = top->info;
    free(top);
    top = topextra;
    count--;
    return popped;
}

void display() {
    // Display the elements of the stack
    topextra = top;
 
    if (topextra == NULL)
    {
        printf("\nStack Underflow\n");
        return;
    }
    
    printf("The stack is \n");
    while (topextra != NULL)
    {
        printf("%d--->", topextra->info);
        topextra = topextra->ptr;
    }
    printf("NULL\n\n");

}

int main() {
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}
