#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dfs.h"  // Include dfs.h from the same folder


#define MAX_LINE_LENGTH 1024
#define MAX_NODES 100

// Function to load a graph from a dataset file
Graph loadGraphFromDataset(const char *datasetPath) {
    FILE *file = fopen(datasetPath, "r");
    if (file == NULL) {
        perror("Failed to open dataset file");
        exit(EXIT_FAILURE);
    }

    Graph graph;
    initGraph(&graph, MAX_NODES);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        int from;
        char neighbors[MAX_LINE_LENGTH];
        if (sscanf(line, "%d,%s", &from, neighbors) == 2) {
            char *neighbor = strtok(neighbors, ",");
            while (neighbor != NULL) {
                int to = atoi(neighbor);
                addEdge(&graph, from, to);
                neighbor = strtok(NULL, ",");
            }
        }
    }

    fclose(file);
    return graph;
}

// Main function
int main() {
    const char *datasetPath = "datasets/graph_datasets/gigantic_graph_dataset.csv";
    int startNode = 0;  // Starting node for DFS
    int visited[MAX_NODES] = {0};

    // Load the graph dataset
    printf("Loading graph dataset from: %s\n", datasetPath);
    Graph graph = loadGraphFromDataset(datasetPath);

    // Log start time
    clock_t startTime = clock();

    // Perform DFS traversal
    printf("DFS Traversal starting from node %d:\n", startNode);
    dfs(&graph, startNode, visited);

    // Log end time and calculate elapsed time
    clock_t endTime = clock();
    double timeElapsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("\nTime taken for DFS: %.6f seconds\n", timeElapsed);

    return 0;
}
