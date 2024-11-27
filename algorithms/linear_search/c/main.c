// algorithms/linear_search/c/main.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linear_search.h"

int main() {
    // Correct dataset path
    const char *dataset_path = "datasets/integer_datasets/non-sorted/gigantic_integer_dataset.csv";
    FILE *file = fopen(dataset_path, "r");
    if (file == NULL) {
        perror("Failed to open dataset file");
        return EXIT_FAILURE;
    }

    int target = 15392;  // Search target
    printf("Searching for %d in the dataset...\n", target);

    // Measure runtime
    clock_t start_time = clock();

    // Perform linear search directly from the file
    int index = 0;
    int temp;
    int result = -1;
    while (fscanf(file, "%d,", &temp) == 1) {
        if (temp == target) {
            result = index;
            break;  // Element found
        }
        index++;
    }
    if (ferror(file)) {
        perror("Error reading the dataset file during search");
        fclose(file);
        return EXIT_FAILURE;
    }

    fclose(file);

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
