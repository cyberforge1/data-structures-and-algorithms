// algorithms/binary_search/c/main.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binary_search.h"

// Function to load dataset from a CSV file without manual memory management
int load_dataset(const char *file_path, int **arr) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Failed to open dataset file");
        return -1;
    }

    // First pass: count the number of integers
    int count = 0;
    int temp;
    while (fscanf(file, "%d", &temp) == 1) {
        count++;
    }
    if (ferror(file)) {
        perror("Error reading the dataset file during counting");
        fclose(file);
        return -1;
    }
    fclose(file);

    // Allocate memory for the exact number of integers
    *arr = malloc(count * sizeof(int));
    if (*arr == NULL) {
        perror("Memory allocation failed");
        return -1;
    }

    // Second pass: read the integers into the array
    file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Failed to reopen dataset file");
        free(*arr);
        return -1;
    }

    int index = 0;
    while (index < count && fscanf(file, "%d", &(*arr)[index]) == 1) {
        index++;
    }
    if (index != count) {
        perror("Error reading the dataset file during data loading");
        free(*arr);
        fclose(file);
        return -1;
    }
    fclose(file);

    return count;
}

int main() {
    // Correct dataset path
    const char *dataset_path = "datasets/integer_datasets/sorted/gigantic_integer_dataset.csv";
    int *data = NULL;
    int size = load_dataset(dataset_path, &data);
    if (size == -1) {
        // Handle error appropriately
        return EXIT_FAILURE;
    }

    int target = 100000;  // Search target
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

    // Free allocated memory
    free(data);

    return 0;
}
