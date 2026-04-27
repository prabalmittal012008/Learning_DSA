#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to find height
int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Main function (user input)
int main() {
    printf("===== Height of Binary Tree =====\n");

    int rootVal, leftVal, rightVal;

    printf("Enter root value: ");
    scanf("%d", &rootVal);

    struct TreeNode* root = createNode(rootVal);

    printf("Enter left child of root (-1 for NULL): ");
    scanf("%d", &leftVal);
    if (leftVal != -1)
        root->left = createNode(leftVal);

    printf("Enter right child of root (-1 for NULL): ");
    scanf("%d", &rightVal);
    if (rightVal != -1)
        root->right = createNode(rightVal);

    // You can extend this for more levels if needed

    int h = height(root);

    printf("\nHeight of Binary Tree = %d\n", h);

    return 0;
}