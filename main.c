#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int linear_search(int arr[], int size, int x);
int binary_search(int arr[], int size, int x);

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Dataset loading function
int* load_dataset(const char* filename, int* size) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return NULL;
    }

    int* data = NULL;
    int number, count = 0;
    while (fscanf(file, "%d", &number) != EOF) {
        data = realloc(data, (count + 1) * sizeof(int));
        data[count++] = number;
    }

    fclose(file);
    *size = count;
    return data;
}

int main() {
    const char* dataset_path = "datasets/integer_datasets/gigantic_integer_dataset.csv";
    int value_to_search = 40004;
    int dataset_size;

    // Load dataset
    int* dataset = load_dataset(dataset_path, &dataset_size);
    if (!dataset) {
        return 1; // Exit if dataset loading failed
    }

    // Select the search function
    int (*search_function)(int[], int, int);

    // Uncomment the desired search algorithm
    // search_function = linear_search;
    search_function = binary_search;

    // Sort dataset if using binary search
    if (search_function == binary_search) {
        qsort(dataset, dataset_size, sizeof(int), compare);
    }

    // Start timing
    clock_t start = clock();

    // Execute search
    int result = search_function(dataset, dataset_size, value_to_search);

    // End timing
    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;

    // Output result
    if (result != -1) {
        printf("Value %d found at index %d\n", value_to_search, result);
    } else {
        printf("Value %d not found\n", value_to_search);
    }
    printf("Time taken: %.6f seconds\n", duration);

    // Free allocated memory
    free(dataset);
    return 0;
}
