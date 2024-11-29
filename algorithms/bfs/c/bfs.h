// algorithms/bfs/c/bfs.h

#ifndef BFS_H
#define BFS_H

#define MAX_NODES 100

// Structure to represent the graph
typedef struct {
    int numNodes;
    int adjMatrix[MAX_NODES][MAX_NODES];
} Graph;

// Function prototypes
void initGraph(Graph *graph, int numNodes);
void addEdge(Graph *graph, int from, int to);
void bfs(Graph *graph, int start);

#endif
