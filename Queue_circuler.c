#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

#define max 50
#define Queue struct node

Queue{
    int data[max+1];
    int head , tail;
};

void enqueue(Queue *q, int item){
    if((q->tail+1)%(max+1) == q->head){
        printf("Queue is full!\n");
        return;
    }
    q->data[q->tail] = item;
    q->tail = (q->tail+1)%(max+1);
}

int dequeue(Queue *q){
    int item;
    if(q->tail==q->head){
        printf("Queue is empty!\n");
        return -1;
    }
    item = q->data[q->head];
    q->head = (q->head+1)%(max+1);
    return item;
}

int main()
{
    int data;
    Queue myq;
    myq.head=0;
    myq.tail=0;

    enqueue(&myq,1);
    enqueue(&myq,2);
    enqueue(&myq,3);
    enqueue(&myq,4);
    
    data = dequeue(&myq);
    printf("Data is %d Head is %d\n", data, myq.head);

    data = dequeue(&myq);
    printf("Data is %d Head is %d\n", data, myq.head);

    data = dequeue(&myq);
    printf("Data is %d Head is %d\n", data, myq.head);
    return 0;
}


