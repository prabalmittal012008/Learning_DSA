#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create node
struct TreeNode *createNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to count leaf nodes
int countLeaves(struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

// Main function (user input)
int main()
{
    printf("===== Count Leaf Nodes in Binary Tree =====\n");

    int rootVal, leftVal, rightVal;

    printf("Enter root value: ");
    scanf("%d", &rootVal);

    struct TreeNode *root = createNode(rootVal);

    printf("Enter left child of root (-1 for NULL): ");
    scanf("%d", &leftVal);
    if (leftVal != -1)
        root->left = createNode(leftVal);

    printf("Enter right child of root (-1 for NULL): ");
    scanf("%d", &rightVal);
    if (rightVal != -1)
        root->right = createNode(rightVal);

    // Count leaf nodes
    int leafCount = countLeaves(root);

    printf("\nNumber of leaf nodes = %d\n", leafCount);

    return 0;
}