source venv/bin/activate

# Binary Search

python algorithms/binary_search/python/main.py

gcc -o algorithms/binary_search/c/main algorithms/binary_search/c/main.c algorithms/binary_search/c/binary_search.c
./algorithms/binary_search/c/main

# Linear Search

python algorithms/linear_search/python/main.py

gcc -o algorithms/linear_search/c/main algorithms/linear_search/c/main.c algorithms/linear_search/c/linear_search.c
./algorithms/linear_search/c/main



# DFS

python -m algorithms.dfs.python.main_dfs

gcc -o algorithms/dfs/c/main_dfs algorithms/dfs/c/main_dfs.c algorithms/dfs/c/dfs.c
./algorithms/dfs/c/main_dfs

