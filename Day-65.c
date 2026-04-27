#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// DFS function
bool dfs(int node, int parent, int visited[], int **adj, int *size) {
    visited[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, adj, size))
                return true;
        }
        else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

// Function required by GFG
bool isCycle(int edges[][2], int E, int V) {
    
    int **adj = (int **)malloc(V * sizeof(int *));
    int *size = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int *)malloc(E * sizeof(int));
    }

    // Build adjacency list
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, size))
                return true;
        }
    }

    return false;
}

// Example main (for local testing)
int main() {
    int V = 3;
    int E = 3;
    int edges[3][2] = {{0,1}, {1,2}, {2,0}};

    if (isCycle(edges, E, V))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}