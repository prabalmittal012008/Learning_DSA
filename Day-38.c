#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty() {
    return front == -1;
}

// Check full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

// Push front
void push_front(int x) {
    if (isFull()) {
        printf("Deque is full!\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    deque[front] = x;
    printf("Inserted %d at front\n", x);
}

// Push back
void push_back(int x) {
    if (isFull()) {
        printf("Deque is full!\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = x;
    printf("Inserted %d at rear\n", x);
}

// Pop front
void pop_front() {
    if (isEmpty()) {
        printf("-1 (Deque is empty)\n");
        return;
    }

    printf("Removed from front: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Pop back
void pop_back() {
    if (isEmpty()) {
        printf("-1 (Deque is empty)\n");
        return;
    }

    printf("Removed from rear: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// Get front
void getFront() {
    if (isEmpty()) {
        printf("-1\n");
    } else {
        printf("Front element: %d\n", deque[front]);
    }
}

// Get rear
void getRear() {
    if (isEmpty()) {
        printf("-1\n");
    } else {
        printf("Rear element: %d\n", deque[rear]);
    }
}

// Size
void size() {
    if (isEmpty()) {
        printf("Size: 0\n");
        return;
    }

    if (rear >= front) {
        printf("Size: %d\n", rear - front + 1);
    } else {
        printf("Size: %d\n", MAX - front + rear + 1);
    }
}

// Display
void display() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;

    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main menu
int main() {
    int choice, x;

    while (1) {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Push Front\n");
        printf("2. Push Back\n");
        printf("3. Pop Front\n");
        printf("4. Pop Back\n");
        printf("5. Get Front\n");
        printf("6. Get Rear\n");
        printf("7. Size\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                push_front(x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                push_back(x);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                getFront();
                break;

            case 6:
                getRear();
                break;

            case 7:
                size();
                break;

            case 8:
                display();
                break;

            case 9:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}