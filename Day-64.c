#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void bfs(int n, int adj[MAX][MAX], int source) {
    int visited[MAX] = {0};

    printf("Starting BFS from node %d\n", source);

    enqueue(source);
    visited[source] = 1;

    printf("Initial Queue: %d\n", source);

    printf("\nBFS Traversal Order:\n");

    while (!isEmpty()) {
        int node = dequeue();
        printf("Visited: %d\n", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
                printf("  -> Enqueued: %d\n", i);
            }
        }
    }
}

int main() {
    int n, source;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int adj[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source node: ");
    scanf("%d", &source);

    bfs(n, adj, source);

    return 0;
}