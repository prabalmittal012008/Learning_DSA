#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue
struct Queue {
    struct TreeNode* arr[100];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Level Order Traversal with printing
void levelOrder(struct TreeNode* root) {
    if (!root) {
        printf("Tree is empty!\n");
        return;
    }

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    printf("\nLevel Order Traversal:\n");

    while (!isEmpty(&q)) {
        int size = q.rear - q.front;

        printf("[ ");

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(&q);

            printf("%d ", node->val);

            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }

        printf("]\n");
    }
}

// Main function (user input)
int main() {
    printf("Create a simple binary tree manually:\n");

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

    // You can extend more levels if needed

    levelOrder(root);

    return 0;
}