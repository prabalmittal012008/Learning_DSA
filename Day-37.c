#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert (sorted)
void insert(int x) {
    if (size == MAX) {
        printf("Queue is full!\n");
        return;
    }

    int i = size - 1;

    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    size++;

    printf("Inserted %d successfully.\n", x);
}

// Delete (remove smallest)
void deleteMin() {
    if (size == 0) {
        printf("-1 (Queue is empty)\n");
        return;
    }

    int val = pq[0];

    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }

    size--;

    printf("Deleted element: %d\n", val);
}

// Peek
void peek() {
    if (size == 0) {
        printf("-1 (Queue is empty)\n");
    } else {
        printf("Top priority element: %d\n", pq[0]);
    }
}

int main() {
    int n, x;
    char op[20];

    printf("Enter number of operations: ");
    scanf("%d", &n);

    printf("\nOperations allowed:\n");
    printf(" - insert <value>\n");
    printf(" - delete\n");
    printf(" - peek\n\n");

    for (int i = 0; i < n; i++) {
        printf("Enter operation %d: ", i + 1);
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            printf("Enter value to insert: ");
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "delete") == 0) {
            deleteMin();
        }
        else if (strcmp(op, "peek") == 0) {
            peek();
        }
        else {
            printf("Invalid operation!\n");
        }
    }

    return 0;
}