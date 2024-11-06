#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000  // Adjust as necessary for dataset size

// Include the linear search function
#include "algorithms/linear_search.c"

// Function to load integers from a file into an array
int read_integers_from_file(const char *file_path, int arr[]) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", file_path);
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%d", &arr[count]) != EOF && count < MAX_SIZE) {
        count++;
    }

    fclose(file);
    return count;  // Return the number of integers read
}

// Function to apply linear search on each dataset file in the folder
void apply_linear_search_to_datasets(int target) {
    const char *datasets[] = {
        "datasets/integer-datasets/small_integer_dataset.csv",
        "datasets/integer-datasets/large_integer_dataset.csv"
    };

    int arr[MAX_SIZE];  // Array to hold integers from file

    // Loop through each dataset file
    for (int i = 0; i < 2; i++) {
        const char *file_path = datasets[i];
        int size = read_integers_from_file(file_path, arr);
        
        if (size == -1) {
            continue;  // Skip file if it couldn't be read
        }

        // Perform linear search
        int result = linear_search(arr, size, target);

        // Print result
        if (result != -1) {
            printf("Target %d found in %s at index %d.\n", target, file_path, result);
        } else {
            printf("Target %d not found in %s.\n", target, file_path);
        }
    }
}

// Main function to execute the search
int main() {
    int target_value = 123;  // Replace with the target value to search for

    // Run linear search on all datasets
    apply_linear_search_to_datasets(target_value);

    return 0;
}
