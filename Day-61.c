#include <stdio.h>

int main() {
    int n, m;
    
    // Input number of vertices
    printf("Enter number of vertices (n): ");
    scanf("%d", &n);

    // Input number of edges
    printf("Enter number of edges (m): ");
    scanf("%d", &m);

    int adj[n][n];

    // Initialize matrix with 0
    printf("\nInitializing adjacency matrix with 0...\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int u, v;
    printf("\nEnter %d edges (u v):\n", m);

    // Input edges
    for (int i = 0; i < m; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        // Add edge (undirected graph)
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}