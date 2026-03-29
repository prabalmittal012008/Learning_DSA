#include <stdio.h>
#include <stdlib.h>

// Define Node
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create linked list from array
struct Node* createList(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* head = newNode(arr[0]);
    struct Node* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = newNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Get length of list
int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection (by value comparison)
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    // Traverse both
    while (head1 && head2) {
        if (head1->data == head2->data)
            return head1->data;

        head1 = head1->next;
        head2 = head2->next;
    }

    return -1; // No intersection
}

int main() {
    int n, m;

    // First list
    scanf("%d", &n);
    int arr1[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);

    // Second list
    scanf("%d", &m);
    int arr2[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);

    struct Node* head1 = createList(arr1, n);
    struct Node* head2 = createList(arr2, m);

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection\n");
    else
        printf("%d\n", result);

    return 0;
}