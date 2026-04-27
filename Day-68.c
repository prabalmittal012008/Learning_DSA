#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int to;
	struct Node *next;
} Node;

static void addEdge(Node **adj, int u, int v) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL) {
		exit(1);
	}
	newNode->to = v;
	newNode->next = adj[u];
	adj[u] = newNode;
}

static int *topoSort(int V, Node **adj, int *outSize) {
	int i;
	int *indegree = (int *)calloc((size_t)V, sizeof(int));
	int *queue = (int *)malloc((size_t)V * sizeof(int));
	int *topo = (int *)malloc((size_t)V * sizeof(int));
	int front = 0, rear = 0, topoSize = 0;

	if (indegree == NULL || queue == NULL || topo == NULL) {
		free(indegree);
		free(queue);
		free(topo);
		exit(1);
	}

	for (i = 0; i < V; i++) {
		Node *curr = adj[i];
		while (curr != NULL) {
			indegree[curr->to]++;
			curr = curr->next;
		}
	}

	for (i = 0; i < V; i++) {
		if (indegree[i] == 0) {
			queue[rear++] = i;
		}
	}

	while (front < rear) {
		int node = queue[front++];
		Node *curr;
		topo[topoSize++] = node;

		curr = adj[node];
		while (curr != NULL) {
			indegree[curr->to]--;
			if (indegree[curr->to] == 0) {
				queue[rear++] = curr->to;
			}
			curr = curr->next;
		}
	}

	free(indegree);
	free(queue);
	*outSize = topoSize;
	return topo;
}

static void freeGraph(Node **adj, int V) {
	int i;
	for (i = 0; i < V; i++) {
		Node *curr = adj[i];
		while (curr != NULL) {
			Node *next = curr->next;
			free(curr);
			curr = next;
		}
	}
	free(adj);
}

int main(void) {
	int V, E;
	int i;
	Node **adj;
	int topoSize;
	int *res;

	if (scanf("%d %d", &V, &E) != 2) {
		return 0;
	}

	adj = (Node **)calloc((size_t)V, sizeof(Node *));
	if (adj == NULL) {
		return 0;
	}

	for (i = 0; i < E; i++) {
		int u, v;
		if (scanf("%d %d", &u, &v) != 2) {
			freeGraph(adj, V);
			return 0;
		}
		if (u >= 0 && u < V && v >= 0 && v < V) {
			addEdge(adj, u, v);
		}
	}

	res = topoSort(V, adj, &topoSize);

	for (i = 0; i < topoSize; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", res[i]);
	}

	free(res);
	freeGraph(adj, V);
	return 0;
}
