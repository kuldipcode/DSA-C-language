#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int length;
} Queue;

Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->length = 0;
    return newQueue;
}

void enqueue(Queue* q, char element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        q->length++;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
    q->length++;
}

char dequeue(Queue* q) {
    if (q->length == 0) {
        printf("Queue is empty\n");
        return ' ';
    }
    Node* temp = q->front;
    q->front = temp->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    q->length--;
    char dequeued = temp->data;
    free(temp);
    return dequeued;
}

char peek(Queue* q) {
    if (q->length == 0) {
        printf("Queue is empty\n");
        return ' ';
    }
    return q->front->data;
}

int isEmpty(Queue* q) {
    return q->length == 0;
}

int size(Queue* q) {
    return q->length;
}

void printQueue(Queue* q) {
    Node* temp = q->front;
    while (temp) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* myQueue = createQueue();
    
    enqueue(myQueue, 'A');
    enqueue(myQueue, 'B');
    enqueue(myQueue, 'C');
    printf("Queue: ");
    printQueue(myQueue);
    
    printf("Dequeue: %c\n", dequeue(myQueue));
    printf("Peek: %c\n", peek(myQueue));
    printf("isEmpty: %d\n", isEmpty(myQueue));
    printf("Size: %d\n", size(myQueue));

    return 0;
}

//C