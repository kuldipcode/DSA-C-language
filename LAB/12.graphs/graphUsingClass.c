// https://www.w3schools.com/dsa/dsa_theory_graphs.php
// https://www.w3schools.com/dsa/dsa_data_graphs_implementation.php
// https://www.w3schools.com/dsa/trydsa.php?filename=demo_graphs_undirected_class
#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

typedef struct Graph {
    int adjMatrix[SIZE][SIZE];
    char vertexData[SIZE];
} Graph;

void initGraph(Graph *g) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            g->adjMatrix[i][j] = 0;
        }
        g->vertexData[i] = 0;
    }
}

void addEdge(Graph *g, int u, int v) {
    if (u >= 0 && u < SIZE && v >= 0 && v < SIZE) {
        g->adjMatrix[u][v] = 1;
        g->adjMatrix[v][u] = 1;
    }
}

void addVertexData(Graph *g, int vertex, char data) {
    if (vertex >= 0 && vertex < SIZE) {
        g->vertexData[vertex] = data;
    }
}

void printGraph(Graph *g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\nVertex Data:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Vertex %d: %c\n", i, g->vertexData[i]);
    }
}

int main() {
    Graph g;
    initGraph(&g);

    addVertexData(&g, 0, 'A');
    addVertexData(&g, 1, 'B');
    addVertexData(&g, 2, 'C');
    addVertexData(&g, 3, 'D');
    addEdge(&g, 0, 1); // A - B
    addEdge(&g, 0, 2); // A - C
    addEdge(&g, 0, 3); // A - D
    addEdge(&g, 1, 2); // B - C

    printGraph(&g);

    return 0;
}

//C