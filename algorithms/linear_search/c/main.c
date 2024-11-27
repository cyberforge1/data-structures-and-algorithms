// algorithms/linear_search/c/main.c

#include <stdio.h>
#include <stdlib.h>
#include "linear_search.h"

#define MAX_SIZE 1000  // Maximum dataset size

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
    // Update the dataset path to the absolute or correct relative path
    const char *dataset_path = "datasets/integer_datasets/gigantic_integer_dataset.csv";
    int data[MAX_SIZE];
    int size = load_dataset(dataset_path, data);

    int target = 1;  // Example target value
    printf("Searching for %d in the dataset...\n", target);

    // Perform linear search
    int result = linear_search(data, size, target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the dataset.\n", target);
    }

    return 0;
}
