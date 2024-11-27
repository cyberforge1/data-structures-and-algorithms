// algorithms/dfs/dfs.c

#include "dfs.h"  // Include dfs.h from the same folder
#include <stdio.h>

void initGraph(Graph *graph, int numNodes) {
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *graph, int from, int to) {
    graph->adjMatrix[from][to] = 1;
}

void dfs(Graph *graph, int start, int visited[]) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->adjMatrix[start][i] && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}
