/* LINEAR SEARCH IN C */

/* algorithms/linear_search/linear_search.c */

#include <stdio.h>

int linear_search(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}
