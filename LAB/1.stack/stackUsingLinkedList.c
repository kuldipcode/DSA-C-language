#include <stdio.h>
#include <stdlib.h>

struct Node {
    char value;
    struct Node *next;
};

struct Stack {
    struct Node *head;
    int size;
};

struct Stack *createStack() {
    struct Stack *s = malloc(sizeof(struct Stack));
    s->head = NULL;
    s->size = 0;
    return s;
}

void push(struct Stack *s, char value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = s->head;
    s->head = newNode;
    s->size++;
}

char pop(struct Stack *s) {
    if (s->size == 0) {
        return ' ';
    }
    struct Node *popped = s->head;
    s->head = s->head->next;
    char poppedValue = popped->value;
    free(popped);
    s->size--;
    return poppedValue;
}

char peek(struct Stack *s) {
    if (s->size == 0) {
        return ' ';
    }
    return s->head->value;
}

int isEmpty(struct Stack *s) {
    return s->size == 0;
}

int stackSize(struct Stack *s) {
    return s->size;
}

int main() {
    struct Stack *myStack = createStack();

    push(myStack, 'A');
    push(myStack, 'B');
    push(myStack, 'C');

    printf("Pop: %c\n", pop(myStack));
    printf("Peek: %c\n", peek(myStack));
    printf("isEmpty: %d\n", isEmpty(myStack));
    printf("Size: %d\n", stackSize(myStack));
    
    return 0;
}



//C