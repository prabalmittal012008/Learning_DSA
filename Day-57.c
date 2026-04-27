#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int val) {
    if (val == -1) return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for level order
struct Node* queue[1000];
int front = 0, rear = 0;

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];

        // Left child
        if (i < n) {
            curr->left = createNode(arr[i]);
            if (curr->left) queue[rear++] = curr->left;
            i++;
        }

        // Right child
        if (i < n) {
            curr->right = createNode(arr[i]);
            if (curr->right) queue[rear++] = curr->right;
            i++;
        }
    }

    return root;
}

// Mirror function
void mirrorTree(struct Node* root) {
    if (root == NULL) return;

    // Swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level-order traversal (-1 for NULL):\n");

    for (int i = 0; i < n; i++) {
        printf("Enter node %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nBuilding the binary tree...\n");
    struct Node* root = buildTree(arr, n);

    printf("Creating mirror of the tree...\n");
    mirrorTree(root);

    printf("Inorder traversal of mirrored tree:\n");
    inorder(root);
    printf("\n");

    return 0;
}