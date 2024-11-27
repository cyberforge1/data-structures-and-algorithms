// algorithms/binary_search/c/main.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binary_search.h"

#define MAX_SIZE 1000

// Function to load dataset from a CSV file
int load_dataset(const char *file_path, int *arr) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Failed to open dataset file");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    while (fscanf(file, "%d,", &arr[count]) != EOF && count < MAX_SIZE) {
        count++;
    }

    fclose(file);
    return count;  // Return the number of elements loaded
}

int main() {
    const char *dataset_path = "datasets/integer_datasets/gigantic_integer_dataset.csv";
    int data[MAX_SIZE];
    int size = load_dataset(dataset_path, data);

    int target = 1;  // Search target is now 1
    printf("Searching for %d in the dataset...\n", target);

    // Measure runtime
    clock_t start_time = clock();

    // Perform binary search
    int result = binary_search(data, size, target);

    clock_t end_time = clock();
    double runtime = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print results
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the dataset.\n", target);
    }

    // Log runtime
    printf("Runtime: %.6f seconds\n", runtime);

    return 0;
}