// algorithms/dfs/dfs.c

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100  // Maximum number of nodes in the graph

// Structure to represent the graph
typedef struct {
    int numNodes;
    int adjMatrix[MAX_NODES][MAX_NODES];  // Adjacency matrix
} Graph;

// Function to initialize the graph
void initGraph(Graph *graph, int numNodes) {
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph->adjMatrix[i][j] = 0;  // No edges initially
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int from, int to) {
    graph->adjMatrix[from][to] = 1;
}

// Depth First Search (DFS) function
void dfs(Graph *graph, int start, int visited[]) {
    visited[start] = 1;  // Mark the node as visited
    printf("%d ", start);  // Print the current node

    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->adjMatrix[start][i] && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

int main() {
    Graph graph;
    int numNodes = 7;  // Number of nodes in the graph
    int visited[MAX_NODES] = {0};  // Initialize visited array

    // Initialize the graph
    initGraph(&graph, numNodes);

    // Add edges to the graph
    addEdge(&graph, 0, 1); // A -> B
    addEdge(&graph, 0, 2); // A -> C
    addEdge(&graph, 1, 3); // B -> D
    addEdge(&graph, 1, 4); // B -> E
    addEdge(&graph, 2, 5); // C -> F
    addEdge(&graph, 4, 5); // E -> F
    addEdge(&graph, 5, 6); // F -> G

    printf("DFS Traversal:\n");
    dfs(&graph, 0, visited);  // Start DFS from node A (index 0)

    return 0;
}
