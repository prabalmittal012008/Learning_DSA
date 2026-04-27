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

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        printf("Inserted %d\n", val);
        return createNode(val);
    }

    if (val < root->val) {
        printf("Going left from %d\n", root->val);
        root->left = insert(root->left, val);
    } else {
        printf("Going right from %d\n", root->val);
        root->right = insert(root->right, val);
    }

    return root;
}

// Inorder traversal (to display sorted BST)
void inorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Main
int main() {
    printf("===== BST Insert =====\n");

    struct TreeNode* root = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nInorder Traversal (Sorted BST): ");
    inorder(root);
    printf("\n");

    return 0;
}