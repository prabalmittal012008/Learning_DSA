#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top < MAX - 1) {
        stack[++top] = val;
    } else {
        printf("Stack Overflow\n");
    }
}

void pop() {
    if (top >= 0) {
        top--;
    } else {
        printf("Stack Underflow\n");
    }
}

int main() {
    int n, m;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    printf("Enter number of elements to pop: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    printf("Remaining stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}