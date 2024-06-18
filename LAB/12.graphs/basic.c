// https://www.w3schools.com/dsa/dsa_theory_graphs.php
// https://www.w3schools.com/dsa/dsa_data_graphs_implementation.php
// https://www.w3schools.com/dsa/trydsa.php?filename=demo_graphs_undirected_class
#include <stdio.h>

void printAdjacencyMatrix(int matrix[4][4], int size) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char vertexData[4] = {'A', 'B', 'C', 'D'};
    int adjacencyMatrix[4][4] = {
        {0, 1, 1, 1}, // Edges for A
        {1, 0, 1, 0}, // Edges for B
        {1, 1, 0, 0}, // Edges for C
        {1, 0, 0, 0}  // Edges for D
    };

    printf("vertexData: ");
    for (int i = 0; i < 4; i++) {
        printf("%c ", vertexData[i]);
    }
    printf("\n");

    printAdjacencyMatrix(adjacencyMatrix, 4);

    return 0;
}

//C