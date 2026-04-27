#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree using preorder & inorder
struct Node* buildTree(int preorder[], int inorder[],
                       int inStart, int inEnd, int* preIndex, int n) {

    if (inStart > inEnd)
        return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = createNode(rootVal);

    // Find root in inorder
    int index;
    for (index = inStart; index <= inEnd; index++) {
        if (inorder[index] == rootVal)
            break;
    }

    // Build left and right subtree
    root->left = buildTree(preorder, inorder, inStart, index - 1, preIndex, n);
    root->right = buildTree(preorder, inorder, index + 1, inEnd, preIndex, n);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int preorder[n], inorder[n];

    printf("Enter preorder traversal:\n");
    for (int i = 0; i < n; i++) {
        printf("Preorder[%d]: ", i);
        scanf("%d", &preorder[i]);
    }

    printf("Enter inorder traversal:\n");
    for (int i = 0; i < n; i++) {
        printf("Inorder[%d]: ", i);
        scanf("%d", &inorder[i]);
    }

    printf("\nConstructing the binary tree...\n");

    int preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex, n);

    printf("Postorder traversal of constructed tree:\n");
    postorder(root);
    printf("\n");

    return 0;
}