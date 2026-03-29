#include <stdio.h>
#include <stdlib.h>

// Define node
struct Node {
    int data;
    struct Node* next;
};

// Create circular linked list
struct Node* createCircularList(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;

    struct Node* temp = head;

    for (int i = 1; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }

    // Make it circular
    temp->next = head;

    return head;
}

// Traverse circular linked list
void printCircularList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* head = createCircularList(arr, n);

    printCircularList(head);

    return 0;
}