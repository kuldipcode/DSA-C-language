// https://www.w3schools.com/dsa/dsa_algo_binarysearch.php
// https://www.w3schools.com/dsa/dsa_data_binarysearchtrees.php

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* newTreeNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inOrderTraversal(TreeNode* node) {
    if (node == NULL)
        return;
    inOrderTraversal(node->left);
    printf("%d, ", node->data);
    inOrderTraversal(node->right);
}

int main() {
    TreeNode* root = newTreeNode(13);
    root->left = newTreeNode(7);
    root->right = newTreeNode(15);

    root->left->left = newTreeNode(3);
    root->left->right = newTreeNode(8);

    root->right->left = newTreeNode(14);
    root->right->right = newTreeNode(19);

    root->right->right->left = newTreeNode(18);

    inOrderTraversal(root);
    return 0;
}

//C