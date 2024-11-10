/* BINARY SEARCH IN C */

/* algorithms/binary_search/binary_search.c */

#include <stdio.h>

int binary_search(int arr[], int size, int x) {
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = (high + low) / 2;

        // If x is greater, ignore left half
        if (arr[mid] < x) {
            low = mid + 1;
        }

        // If x is smaller, ignore right half
        else if (arr[mid] > x) {
            high = mid - 1;
        }

        // x is present at mid
        else {
            return mid;
        }
    }

    // If we reach here, then the element was not present
    return -1;
}
