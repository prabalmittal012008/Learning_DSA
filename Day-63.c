#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS function
void dfs(struct Node* adj[], bool visited[], int v) {
    printf("Visited %d\n", v);
    visited[v] = true;

    struct Node* temp = adj[v];

    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            printf("  Exploring edge %d -> %d\n", v, temp->vertex);
            dfs(adj, visited, temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;

    printf("Enter number of vertices (n): ");
    scanf("%d", &n);

    printf("Enter number of edges (m): ");
    scanf("%d", &m);

    struct Node* adj[n];
    bool visited[n];

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = false;
    }

    printf("\nEnter edges (u v):\n");

    int u, v;
    for (int i = 0; i < m; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        // Undirected graph
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int start;
    printf("\nEnter starting vertex (s): ");
    scanf("%d", &start);

    printf("\nStarting DFS traversal from vertex %d...\n\n", start);

    dfs(adj, visited, start);

    printf("\nDFS traversal completed.\n");

    return 0;
}