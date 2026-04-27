#include <stdio.h>
#include <stdlib.h>

#define INF 100000000

typedef struct Edge {
    int u;
    int v;
    int w;
} Edge;

int bellman_ford(int V, Edge *edges, int E, int S, int *dist) {
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }

    dist[S] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int wt = edges[j].w;

            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int wt = edges[j].w;

        if (dist[u] != INF && dist[u] + wt < dist[v]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int V, E, S;
    if (scanf("%d %d %d", &V, &E, &S) != 3) {
        return 0;
    }

    Edge *edges = (Edge *)malloc(E * sizeof(Edge));
    int *dist = (int *)malloc(V * sizeof(int));

    if (edges == NULL || dist == NULL) {
        free(edges);
        free(dist);
        return 0;
    }

    for (int i = 0; i < E; i++) {
        if (scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w) != 3) {
            free(edges);
            free(dist);
            return 0;
        }
    }

    if (!bellman_ford(V, edges, E, S, dist)) {
        printf("-1 ");
    } else {
        for (int i = 0; i < V; i++) {
            printf("%d ", dist[i]);
        }
    }

    free(edges);
    free(dist);
    return 0;
}