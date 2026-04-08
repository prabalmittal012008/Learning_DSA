#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void display() {
    if (top == -1)
        printf("Stack is Empty\n");
    else {
        printf("Stack (top to bottom): ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int n, op, val;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    while (n--) {
        printf("\nChoose operation:\n");
        printf("  1 <value> : Push\n");
        printf("  2         : Pop\n");
        printf("  3         : Display\n");
        printf("Enter choice: ");
        scanf("%d", &op);

        if (op == 1) {
            printf("Enter value to push: ");
            scanf("%d", &val);
            push(val);
            printf("Pushed: %d\n", val);
        } else if (op == 2) {
            pop();
        } else if (op == 3) {
            display();
        } else {
            printf("Invalid operation! Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}