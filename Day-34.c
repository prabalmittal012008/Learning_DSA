#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char exp[100];
    int i = 0;

    printf("Enter postfix expression (use spaces between elements): ");
    fgets(exp, sizeof(exp), stdin);

    while (exp[i] != '\0') {

        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
        }
        else if (exp[i] == ' ') {
            i++;
            continue;
        }
        else {
            int b = pop();
            int a = pop();
            int res;

            if (exp[i] == '+') res = a + b;
            else if (exp[i] == '-') res = a - b;
            else if (exp[i] == '*') res = a * b;
            else if (exp[i] == '/') res = a / b;

            push(res);
            i++;
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}