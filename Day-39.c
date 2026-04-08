#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert
void insert(int x) {
    if (size == MAX) {
        printf("Heap is full!\n");
        return;
    }

    heap[size] = x;
    heapifyUp(size);
    size++;

    printf("Inserted %d into heap\n", x);
}

// Peek
void peek() {
    if (size == 0) {
        printf("-1 (Heap is empty)\n");
    } else {
        printf("Minimum element: %d\n", heap[0]);
    }
}

// Extract Min
void extractMin() {
    if (size == 0) {
        printf("-1 (Heap is empty)\n");
        return;
    }

    printf("Extracted Min: %d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

// Display heap
void display() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int n, x;
    char op[20];

    printf("Enter number of operations: ");
    scanf("%d", &n);

    printf("\nOperations allowed:\n");
    printf(" - insert <value>\n");
    printf(" - extractMin\n");
    printf(" - peek\n\n");

    for (int i = 0; i < n; i++) {
        printf("Enter operation %d: ", i + 1);
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            printf("Enter value: ");
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "extractMin") == 0) {
            extractMin();
        }
        else if (strcmp(op, "peek") == 0) {
            peek();
        }
        else {
            printf("Invalid operation!\n");
        }
    }

    printf("\nFinal ");
    display();

    return 0;
}