#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}


struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    if (head == NULL)
        return NULL;

    
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;
    struct Node* prev = NULL;

    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    
    if (curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }

    return head;
}


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" ");
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    int value;

    
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    int key;
    scanf("%d", &key);

    
    head = deleteFirstOccurrence(head, key);

    
    printList(head);

    return 0;
}