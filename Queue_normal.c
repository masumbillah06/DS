#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

#define max 100

typedef struct node{
    int data[max+1];
    int head, tail;
}Queue;

void enqueue(Queue *q, int item){
    if(q->tail == max){
        printf("Queue is full!\n");
        return; 
    }
    q->data[q->tail] = item;
    q->tail++;
}

int dequeue(Queue *q){
    int item;
    if(q->head == q->tail){
        printf("Queue is empty!\n");
        return -1;
    }
    item = q->data[q->head];
    q->head++;
    return item;
}

int main()
{
    Queue myq;
    myq.head=0;
    myq.tail=0;

    int item;
    enqueue(&myq, 1);
    enqueue(&myq, 2);
    enqueue(&myq, 3);

    item = dequeue(&myq);
    if(item != -1) printf("Value is %d and head is %d.\n", item, myq.head);
    else printf("Queue is empty!\n");

    item = dequeue(&myq);
    if(item != -1) printf("Value is %d and head is %d.\n", item, myq.head);
    else printf("Queue is empty!\n");

    item = dequeue(&myq);
    if(item != -1) printf("Value is %d and head is %d.\n", item, myq.head);
    else printf("Queue is empty!\n");

    item = dequeue(&myq);
    if(item != -1) printf("Value is %d and head is %d.\n", item, myq.head);
    else printf("Queue is empty!\n");

    return 0;
}