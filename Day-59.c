#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from inorder & postorder
struct Node* buildTree(int inorder[], int postorder[],
                       int inStart, int inEnd, int* postIndex) {

    if (inStart > inEnd)
        return NULL;

    // Root from postorder (last element)
    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = createNode(rootVal);

    // Find root in inorder
    int index;
    for (index = inStart; index <= inEnd; index++) {
        if (inorder[index] == rootVal)
            break;
    }

    // IMPORTANT: build right first
    root->right = buildTree(inorder, postorder, index + 1, inEnd, postIndex);
    root->left = buildTree(inorder, postorder, inStart, index - 1, postIndex);

    return root;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Main
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter inorder traversal:\n");
    for (int i = 0; i < n; i++) {
        printf("Inorder[%d]: ", i);
        scanf("%d", &inorder[i]);
    }

    printf("Enter postorder traversal:\n");
    for (int i = 0; i < n; i++) {
        printf("Postorder[%d]: ", i);
        scanf("%d", &postorder[i]);
    }

    printf("\nConstructing the binary tree...\n");

    int postIndex = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Preorder traversal of constructed tree:\n");
    preorder(root);
    printf("\n");

    return 0;
}