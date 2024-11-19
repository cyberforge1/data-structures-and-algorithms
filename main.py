# main.py

import importlib
import pandas as pd
import time

def load_algorithm(algorithm_path, algorithm_name, function_name):
    """
    Dynamically loads a function from a specified module.
    
    :param algorithm_path: Path to the module, e.g., 'algorithms.linear_search'
    :param algorithm_name: The module name, e.g., 'linear_search'
    :param function_name: The function name within the module, e.g., 'linear_search'
    :return: The loaded function
    """
    module = importlib.import_module(f"{algorithm_path}.{algorithm_name}")
    return getattr(module, function_name)

def load_dataset(dataset_path):
    """
    Loads a dataset from a specified path.
    
    :param dataset_path: Path to the CSV file.
    :return: List of integers in the dataset.
    """
    df = pd.read_csv(dataset_path, header=None)
    data = df[0].tolist()  # Assumes the integers are in a single column
    print(f"Dataset loaded from {dataset_path}. Sample data: {data[:3]}")
    return data

def load_graph_dataset(dataset_path):
    """
    Loads a graph dataset from a specified path in adjacency list format.
    
    :param dataset_path: Path to the graph dataset CSV file.
    :return: Dictionary representing the graph.
    """
    df = pd.read_csv(dataset_path, header=None, names=["Node", "Neighbors"])
    graph = {}
    for _, row in df.iterrows():
        node = row["Node"]
        neighbors = row["Neighbors"].split(",") if pd.notna(row["Neighbors"]) else []
        graph[node] = neighbors
    print(f"Graph dataset loaded from {dataset_path}. Sample graph: {list(graph.items())[:3]}")
    return graph

def main():
    # Uncomment this section for linear or binary search:
    # algorithm_path = 'algorithms.linear_search'
    # algorithm_name = 'linear_search'
    # function_name = 'linear_search'

    # algorithm_path = 'algorithms.binary_search'
    # algorithm_name = 'binary_search'
    # function_name = 'binary_search'

    # dataset_path = 'datasets/integer_datasets/gigantic_integer_dataset.csv'
    
    # # Load algorithm and dataset
    # search_function = load_algorithm(algorithm_path, algorithm_name, function_name)
    # dataset = load_dataset(dataset_path)
    
    # # Define the value to search for
    # value_to_search = 40004
    
    # # If using binary search, ensure the dataset is sorted
    # if function_name == 'binary_search':
    #     dataset.sort()
    
    # # Measure start time
    # start_time = time.time()
    
    # # Apply algorithm
    # result = search_function(dataset, value_to_search)
    
    # # Measure end time
    # end_time = time.time()
    # duration = end_time - start_time
    
    # # Output result
    # if result != -1:
    #     print(f"Value {value_to_search} found at index {result}")
    # else:
    #     print(f"Value {value_to_search} not found")
    # print(f"Time taken: {duration:.6f} seconds")

    # For DFS:
    algorithm_path = 'algorithms.dfs'
    algorithm_name = 'dfs'
    function_name = 'dfs'

    dataset_path = 'datasets/graph_datasets/large_graph_dataset.csv'

    # Load algorithm and graph dataset
    dfs_function = load_algorithm(algorithm_path, algorithm_name, function_name)
    graph = load_graph_dataset(dataset_path)

    # Define the starting node for DFS
    start_node = 'A'

    # Measure start time
    start_time = time.time()

    # Apply DFS algorithm
    visited_nodes = dfs_function(graph, start_node)

    # Measure end time
    end_time = time.time()
    duration = end_time - start_time

    # Output result
    print(f"DFS traversal starting from {start_node}: {visited_nodes}")
    print(f"Time taken: {duration:.6f} seconds")

if __name__ == "__main__":
    main()
