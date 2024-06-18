// https://www.w3schools.com/dsa/dsa_data_linkedlists_types.php
// https://www.w3schools.com/dsa/trydsa.php?filename=demo_linkedLists_doubly
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

int main() {
    Node* node1 = (Node*) malloc(sizeof(Node));
    node1->data = 3;
    node1->next = NULL;
    node1->prev = NULL;

    Node* node2 = (Node*) malloc(sizeof(Node));
    node2->data = 5;
    node2->next = NULL;
    node2->prev = node1;
    node1->next = node2;

    Node* node3 = (Node*) malloc(sizeof(Node));
    node3->data = 13;
    node3->next = NULL;
    node3->prev = node2;
    node2->next = node3;

    Node* node4 = (Node*) malloc(sizeof(Node));
    node4->data = 2;
    node4->next = NULL;
    node4->prev = node3;
    node3->next = node4;

    Node* currentNode = node1;
    printf("Forward: ");
    while (currentNode) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");

    currentNode = node4;
    printf("Backward: ");
    while (currentNode) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->prev;
    }
    printf("NULL\n");

    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}

//C