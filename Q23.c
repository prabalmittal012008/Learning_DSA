#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}


struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    struct Node* dummy = createNode(0);  
    struct Node* tail = dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    
    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy->next;  
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
    int n, m, val;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&list1, val);
    }

    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        insertEnd(&list2, val);
    }

    
    struct Node* merged = mergeSortedLists(list1, list2);

    
    printList(merged);

    return 0;
}