#include <stdio.h>

// Define the linear search function
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the position if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}
