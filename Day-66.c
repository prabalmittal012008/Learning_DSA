#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
bool dfs(int node, int** adj, int* adjSize, bool* visited, bool* recStack) {
    
    printf("Visiting node: %d\n", node);

    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        printf("  Checking neighbor %d of node %d\n", neighbor, node);

        if (!visited[neighbor]) {
            printf("  Neighbor %d not visited, going deeper...\n", neighbor);

            if (dfs(neighbor, adj, adjSize, visited, recStack)) {
                return true;
            }
        }
        else if (recStack[neighbor]) {
            printf("  Cycle detected! Node %d is already in recursion stack\n", neighbor);
            return true;
        }
    }

    recStack[node] = false;
    printf("Backtracking from node: %d\n", node);

    return false;
}

// Function to check cycle
bool isCycle(int V, int** edges, int E) {
    
    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(E * sizeof(int));
    }

    // Build graph
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][adjSize[u]++] = v;
    }

    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool* recStack = (bool*)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            printf("\nStarting DFS from node %d\n", i);

            if (dfs(i, adj, adjSize, visited, recStack)) {
                return true;
            }
        }
    }

    return false;
}

// MAIN FUNCTION
int main() {
    int V = 3;  // number of vertices
    int E = 3;  // number of edges

    // Allocate edges
    int** edges = (int**)malloc(E * sizeof(int*));
    for (int i = 0; i < E; i++) {
        edges[i] = (int*)malloc(2 * sizeof(int));
    }

    // Example graph:
    // 0 -> 1
    // 1 -> 2
    // 2 -> 0  (cycle)
    edges[0][0] = 0; edges[0][1] = 1;
    edges[1][0] = 1; edges[1][1] = 2;
    edges[2][0] = 2; edges[2][1] = 0;

    if (isCycle(V, edges, E)) {
        printf("\nYES - Cycle exists\n");
    } else {
        printf("\nNO - No cycle\n");
    }

    return 0;
}