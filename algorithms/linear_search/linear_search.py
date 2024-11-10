# LINEAR SEARCH IN PYTHON

# algorithms/linear_search/linear_search.py

def linear_search(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1
