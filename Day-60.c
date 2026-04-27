#include <stdio.h>

// Function to check Min-Heap property
int isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        // Left child
        int left = 2 * i + 1;
        // Right child
        int right = 2 * i + 2;

        if (left < n && arr[i] > arr[left])
            return 0;

        if (right < n && arr[i] > arr[right])
            return 0;
    }
    return 1;
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level-order traversal:\n");
    for (int i = 0; i < n; i++) {
        printf("Node[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nChecking Min-Heap property...\n");

    if (isMinHeap(arr, n)) {
        printf("Result: YES (Valid Min-Heap)\n");
    } else {
        printf("Result: NO (Not a Min-Heap)\n");
    }

    return 0;
}