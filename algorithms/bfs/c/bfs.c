// algorithms/bfs/c/bfs.c

#include "bfs.h"  // Include bfs.h from the same folder
#include <stdio.h>

// Initialize the graph with a given number of nodes
void initGraph(Graph *graph, int numNodes) {
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

// Add an edge to the graph
void addEdge(Graph *graph, int from, int to) {
    graph->adjMatrix[from][to] = 1;
    graph->adjMatrix[to][from] = 1; // For undirected graphs, remove this line for directed graphs
}

// Perform BFS on the graph
void bfs(Graph *graph, int start) {
    int visited[MAX_NODES] = {0};  // To track visited nodes
    int queue[MAX_NODES];          // Queue to manage BFS
    int front = 0, rear = 0;       // Queue pointers

    // Enqueue the starting node
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal starting from node %d:\n", start);

    while (front < rear) {
        // Dequeue a node
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        // Enqueue all unvisited neighbors
        for (int i = 0; i < graph->numNodes; i++) {
            if (graph->adjMatrix[currentNode][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
