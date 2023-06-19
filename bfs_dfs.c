#include <stdio.h>
#include <stdlib.h>
int i,j,v;
#define MAX_VERTEX 100

struct Graph {
    int V; // number of vertices
    int E; // number of edges
    int adjMatrix[MAX_VERTEX][MAX_VERTEX]; // adjacency matrix representation of the graph
};

// initialize the graph
void initGraph(struct Graph* G, int V) {
    G->V = V;
    G->E = 0;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            G->adjMatrix[i][j] = 0;
        }
    }
}

// add an edge to the graph
void addEdge(struct Graph* G, int u, int v) {
    G->adjMatrix[u][v] = 1;
    G->adjMatrix[v][u] = 1;
    G->E++;
}

// BFS traversal of the graph
void BFS(struct Graph* G, int s) {
    int visited[MAX_VERTEX] = {0}; // mark all vertices as not visited
    int queue[MAX_VERTEX];
    int front = 0, rear = -1;
    visited[s] = 1; // mark the starting vertex as visited
    queue[++rear] = s; // insert the starting vertex into the queue
    printf("BFS traversal: ");
    while (front <= rear) {
        int u = queue[front++]; // dequeue a vertex from the queue
        printf("%d ", u);
        for (v = 0; v < G->V; v++) {
            if (G->adjMatrix[u][v] == 1 && visited[v] == 0) { // if vertex v is adjacent to u and not visited
                visited[v] = 1; // mark vertex v as visited
                queue[++rear] = v; // insert vertex v into the queue
            }
        }
    }
    printf("\n");
}

// DFS traversal of the graph
void DFS(struct Graph* G, int u, int visited[MAX_VERTEX]) {
    visited[u] = 1; // mark the vertex as visited
    printf("%d ", u);
    for (v = 0; v < G->V; v++) {
        if (G->adjMatrix[u][v] == 1 && visited[v] == 0) { // if vertex v is adjacent to u and not visited
            DFS(G, v, visited); // recursively call DFS for vertex v
        }
    }
}

// driver program to test above functions
int main() {
    struct Graph G;
    initGraph(&G, 6);
    addEdge(&G, 0, 1);
    addEdge(&G, 0, 2);
    addEdge(&G, 1, 3);
    addEdge(&G, 2, 3);
    addEdge(&G, 3, 4);
    addEdge(&G, 3, 5);
    BFS(&G, 0);
    int visited[MAX_VERTEX] = {0};
    printf("DFS traversal: ");
    DFS(&G, 0, visited);
    printf("\n");
    return 0;
}

