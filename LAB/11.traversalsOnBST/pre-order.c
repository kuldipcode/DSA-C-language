// https://www.w3schools.com/dsa/dsa_algo_binarytrees_preorder.php

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNewNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%c, ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    TreeNode* root = createNewNode('R');
    TreeNode* nodeA = createNewNode('A');
    TreeNode* nodeB = createNewNode('B');
    TreeNode* nodeC = createNewNode('C');
    TreeNode* nodeD = createNewNode('D');
    TreeNode* nodeE = createNewNode('E');
    TreeNode* nodeF = createNewNode('F');
    TreeNode* nodeG = createNewNode('G');

    root->left = nodeA;
    root->right = nodeB;

    nodeA->left = nodeC;
    nodeA->right = nodeD;

    nodeB->left = nodeE;
    nodeB->right = nodeF;

    nodeF->left = nodeG;

    // Traverse
    preOrderTraversal(root);

    free(nodeG);
    free(nodeF);
    free(nodeE);
    free(nodeB);
    free(nodeC);
    free(nodeD);
    free(nodeA);
    free(root);

    return 0;
}

//C