// algorithms/binary_search/c/binary_search.c

#include "binary_search.h"

int binary_search(int arr[], int size, int x) {
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = (high + low) / 2;

        if (arr[mid] < x) {
            low = mid + 1;
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            return mid;  // Element found at mid
        }
    }

    return -1;  // Element not found
}
