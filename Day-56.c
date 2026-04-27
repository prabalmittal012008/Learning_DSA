#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for level order construction
struct Node* queue[1000];
int front = 0, rear = 0;

// Function to build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* current = queue[front++];

        // Left child
        if (i < n) {
            current->left = createNode(arr[i]);
            if (current->left)
                queue[rear++] = current->left;
            i++;
        }

        // Right child
        if (i < n) {
            current->right = createNode(arr[i]);
            if (current->right)
                queue[rear++] = current->right;
            i++;
        }
    }

    return root;
}

// Function to check symmetry
int isMirror(struct Node* left, struct Node* right) {
    if (!left && !right) return 1;
    if (!left || !right) return 0;

    return (left->data == right->data) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

int isSymmetric(struct Node* root) {
    if (!root) return 1;
    return isMirror(root->left, root->right);
}

// Main function
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

    printf("Checking if the tree is symmetric...\n");

    if (isSymmetric(root)) {
        printf("Result: YES (Tree is symmetric)\n");
    } else {
        printf("Result: NO (Tree is NOT symmetric)\n");
    }

    return 0;
}