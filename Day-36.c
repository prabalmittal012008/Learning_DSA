#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

// Dequeue
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

// Display
void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main() {
    int n, m, x;

    // Input with prompts
    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &x);
        enqueue(x);
    }

    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);

    // Perform dequeue
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    // Output
    printf("\nFinal ");
    display();

    return 0;
}