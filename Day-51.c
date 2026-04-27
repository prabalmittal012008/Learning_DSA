#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Find LCA in BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    return root;
}

int main() {
    int n, i, val, n1, n2;
    struct Node* root = NULL;

    // Input size
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input elements
    printf("Enter %d values to insert into BST:\n", n);
    for (i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input nodes for LCA
    printf("Enter two node values to find LCA:\n");
    printf("First node: ");
    scanf("%d", &n1);
    printf("Second node: ");
    scanf("%d", &n2);

    // Find and print LCA
    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("Lowest Common Ancestor is: %d\n", lca->data);
    else
        printf("LCA not found.\n");

    return 0;
}