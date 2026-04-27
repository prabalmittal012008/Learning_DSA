#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list
int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

// DFS function
void dfs(int node, int V) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, V);
        }
    }

    // Push to stack after visiting all neighbors
    stack[++top] = node;
}

// Topological sort function
void topoSort(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, V);
        }
    }

    // Print result
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize graph and visited
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topoSort(V);

    return 0;
}