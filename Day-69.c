#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1000000000

typedef struct Edge {
    int to;
    int weight;
    struct Edge *next;
} Edge;

typedef struct HeapNode {
    int dist;
    int vertex;
} HeapNode;

typedef struct MinHeap {
    HeapNode *arr;
    int size;
    int capacity;
} MinHeap;

void swapNodes(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

MinHeap *createHeap(int capacity) {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->arr = (HeapNode *)malloc(sizeof(HeapNode) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void heapifyUp(MinHeap *heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap->arr[parent].dist <= heap->arr[idx].dist) {
            break;
        }
        swapNodes(&heap->arr[parent], &heap->arr[idx]);
        idx = parent;
    }
}

void heapifyDown(MinHeap *heap, int idx) {
    while (1) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        if (left < heap->size && heap->arr[left].dist < heap->arr[smallest].dist) {
            smallest = left;
        }
        if (right < heap->size && heap->arr[right].dist < heap->arr[smallest].dist) {
            smallest = right;
        }

        if (smallest == idx) {
            break;
        }

        swapNodes(&heap->arr[idx], &heap->arr[smallest]);
        idx = smallest;
    }
}

void pushHeap(MinHeap *heap, int dist, int vertex) {
    if (heap->size >= heap->capacity) {
        return;
    }
    heap->arr[heap->size].dist = dist;
    heap->arr[heap->size].vertex = vertex;
    heapifyUp(heap, heap->size);
    heap->size++;
}

HeapNode popHeap(MinHeap *heap) {
    HeapNode minNode = {INF, -1};
    if (heap->size == 0) {
        return minNode;
    }

    minNode = heap->arr[0];
    heap->size--;
    heap->arr[0] = heap->arr[heap->size];
    heapifyDown(heap, 0);
    return minNode;
}

void addEdge(Edge **adj, int u, int v, int w) {
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->to = v;
    newEdge->weight = w;
    newEdge->next = adj[u];
    adj[u] = newEdge;
}

void dijkstra(int V, Edge **adj, int S, int *dist) {
    MinHeap *heap = createHeap(2 * V * V + 5);

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }

    dist[S] = 0;
    pushHeap(heap, 0, S);

    while (heap->size > 0) {
        HeapNode cur = popHeap(heap);
        int dis = cur.dist;
        int node = cur.vertex;

        if (dis > dist[node]) {
            continue;
        }

        Edge *it = adj[node];
        while (it != NULL) {
            int adjNode = it->to;
            int edgeWeight = it->weight;

            if (dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pushHeap(heap, dist[adjNode], adjNode);
            }
            it = it->next;
        }
    }

    free(heap->arr);
    free(heap);
}

void freeGraph(Edge **adj, int V) {
    for (int i = 0; i < V; i++) {
        Edge *cur = adj[i];
        while (cur != NULL) {
            Edge *next = cur->next;
            free(cur);
            cur = next;
        }
    }
}

int main() {
    int V, E, S;
    scanf("%d %d %d", &V, &E, &S);

    Edge **adj = (Edge **)calloc(V, sizeof(Edge *));
    int *dist = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        addEdge(adj, v, u, w);
    }

    dijkstra(V, adj, S, dist);

    for (int i = 0; i < V; i++) {
        printf("%d ", dist[i]);
    }

    free(dist);
    freeGraph(adj, V);
    free(adj);

    return 0;
}