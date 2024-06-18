// https://www.w3schools.com/dsa/dsa_data_queues.php
// First In First Out. Ex office printer, order processing for e-tickets, or to create algorithms for breadth-first search in graphs.

#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 10

struct Queue {
    int queue[CAPACITY];
    int front;
    int size;
};

void enqueue(struct Queue *q, int element);
int dequeue(struct Queue *q);
int peek(struct Queue *q);
bool isEmpty(struct Queue *q);
int size(struct Queue *q);
void printQueue(struct Queue *q);

int main() {
    struct Queue myQueue = { .front = 0, .size = 0 };

    enqueue(&myQueue, 'A');
    enqueue(&myQueue, 'B');
    enqueue(&myQueue, 'C');
    
    printQueue(&myQueue);

    printf("Dequeue: %c\n", dequeue(&myQueue));
    printf("Peek: %c\n", peek(&myQueue));
    printf("isEmpty: %d\n", isEmpty(&myQueue));
    printf("Size: %d\n", size(&myQueue));

    return 0;
}

void enqueue(struct Queue *q, int element) {
    if (q->size == CAPACITY) {
        printf("Queue is full\n");
        return;
    }
    q->queue[(q->front + q->size) % CAPACITY] = element;
    q->size++;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->queue[q->front];
    q->front = (q->front + 1) % CAPACITY;
    q->size--;
    return item;
}

int peek(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->queue[q->front];
}

bool isEmpty(struct Queue *q) {
    return q->size == 0;
}

int size(struct Queue *q) {
    return q->size;
}

void printQueue(struct Queue *q) {
    printf("Queue: ");
    for (int i = 0; i < q->size; ++i) {
        printf("%c ", q->queue[(q->front + i) % CAPACITY]);
    }
    printf("\n");
}


//C