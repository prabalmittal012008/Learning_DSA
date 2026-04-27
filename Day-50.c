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

// Insert into BST (for building tree)
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Search in BST with print statements
struct TreeNode* search(struct TreeNode* root, int val) {
    if (root == NULL) {
        printf("Value %d not found in BST.\n", val);
        return NULL;
    }

    printf("Checking node: %d\n", root->val);

    if (root->val == val) {
        printf("Value %d found!\n", val);
        return root;
    }

    if (val < root->val) {
        printf("Going left from %d\n", root->val);
        return search(root->left, val);
    } else {
        printf("Going right from %d\n", root->val);
        return search(root->right, val);
    }
}

// Inorder traversal (for display)
void inorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Main
int main() {
    printf("===== BST Search =====\n");

    struct TreeNode* root = NULL;
    int n, val, searchVal;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nInorder Traversal (BST): ");
    inorder(root);
    printf("\n");

    printf("\nEnter value to search: ");
    scanf("%d", &searchVal);

    search(root, searchVal);

    return 0;
}