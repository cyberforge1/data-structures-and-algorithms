// algorithms/bfs/c/main_bfs.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bfs.h"  // Include bfs.h from the same folder

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
    int startNode = 0;  // Starting node for BFS

    // Load the graph dataset
    printf("Loading graph dataset from: %s\n", datasetPath);
    Graph graph = loadGraphFromDataset(datasetPath);

    // Log start time
    clock_t startTime = clock();

    // Perform BFS traversal
    bfs(&graph, startNode);

    // Log end time and calculate elapsed time
    clock_t endTime = clock();
    double timeElapsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("Time taken for BFS: %.6f seconds\n", timeElapsed);

    return 0;
}
