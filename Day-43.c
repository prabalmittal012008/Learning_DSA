#include <stdio.h>
#include <stdlib.h>

// Tree Node
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
    printf("Created node: %d\n", data);
    return newNode;
}

// Queue for level order construction
struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++(q->rear)] = node;
    printf("Enqueued node: %d\n", node->data);
}

struct Node* dequeue(struct Queue* q) {
    struct Node* temp = q->arr[(q->front)++];
    printf("Dequeued node: %d\n", temp->data);
    return temp;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Queue q;
    initQueue(&q);

    struct Node* root = createNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while (i < n) {
        struct Node* current = dequeue(&q);

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            printf("Added left child %d to %d\n", arr[i], current->data);
            enqueue(&q, current->left);
        } else {
            printf("Left child of %d is NULL\n", current->data);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            printf("Added right child %d to %d\n", arr[i], current->data);
            enqueue(&q, current->right);
        } else {
            printf("Right child of %d is NULL\n", current->data);
        }
        i++;
    }

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order elements (-1 for NULL):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}