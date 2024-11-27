// algorithms/dfs/c/dfs.h

#ifndef DFS_H
#define DFS_H

#define MAX_NODES 100

// Structure to represent the graph
typedef struct {
    int numNodes;
    int adjMatrix[MAX_NODES][MAX_NODES];
} Graph;

// Function prototypes
void initGraph(Graph *graph, int numNodes);
void addEdge(Graph *graph, int from, int to);
void dfs(Graph *graph, int start, int visited[]);

#endif
