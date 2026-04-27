#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;

    // Input vertices
    printf("Enter number of vertices (n): ");
    scanf("%d", &n);

    // Input edges
    printf("Enter number of edges (m): ");
    scanf("%d", &m);

    // Create adjacency list (array of pointers)
    struct Node* adj[n];

    // Initialize all lists to NULL
    printf("\nInitializing adjacency list...\n");
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    int u, v;
    printf("\nEnter %d edges (u v):\n", m);

    // Input edges
    for (int i = 0; i < m; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        // Add edge u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // Add edge v -> u (for undirected graph)
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    // Print adjacency list
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);
        struct Node* temp = adj[i];

        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}