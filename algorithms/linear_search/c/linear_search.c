// algorithms/linear_search/c/linear_search.c

#include "linear_search.h"

int linear_search(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}
