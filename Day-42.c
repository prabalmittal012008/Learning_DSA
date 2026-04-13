#include <stdio.h>
#include <stdlib.h>

// Stack implementation
struct Stack {
    int arr[100];
    int top;
};

// Initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Push to stack
void push(struct Stack* s, int value) {
    s->arr[++(s->top)] = value;
    printf("Pushed to stack: %d\n", value);
}

// Pop from stack
int pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    int val = s->arr[(s->top)--];
    printf("Popped from stack: %d\n", val);
    return val;
}

// Queue implementation
struct Queue {
    int arr[100];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

// Enqueue
void enqueue(struct Queue* q, int value) {
    q->arr[++(q->rear)] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue
int dequeue(struct Queue* q) {
    if (q->front > q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int val = q->arr[(q->front)++];
    printf("Dequeued: %d\n", val);
    return val;
}

// Display queue
void display(struct Queue* q) {
    if (q->front > q->rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    int n, value;
    struct Queue q;
    struct Stack s;

    initQueue(&q);
    initStack(&s);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&q, value);
    }

    printf("\nOriginal ");
    display(&q);

    // Step 1: Dequeue all elements and push to stack
    while (q.front <= q.rear) {
        int val = dequeue(&q);
        push(&s, val);
    }

    // Step 2: Pop from stack and enqueue back
    while (s.top != -1) {
        int val = pop(&s);
        enqueue(&q, val);
    }

    printf("\nReversed ");
    display(&q);

    return 0;
}