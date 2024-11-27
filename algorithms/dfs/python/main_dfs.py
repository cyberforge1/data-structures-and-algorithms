# algorithms/dfs/python/main_dfs.py

import importlib
import pandas as pd
import time

def load_algorithm(algorithm_path, algorithm_name, function_name):
    module = importlib.import_module(f"{algorithm_path}.{algorithm_name}")
    return getattr(module, function_name)

def load_graph_dataset(dataset_path):
    df = pd.read_csv(dataset_path, header=None, names=["Node", "Neighbors"], quotechar='"')
    graph = {}
    
    # Step 1: Populate the graph from the dataset
    for _, row in df.iterrows():
        node = row["Node"]
        neighbors = row["Neighbors"].split(",") if pd.notna(row["Neighbors"]) else []
        graph[node] = neighbors

    # Step 2: Collect all missing nodes
    missing_nodes = set()
    for neighbors in graph.values():
        for neighbor in neighbors:
            if neighbor not in graph:
                missing_nodes.add(neighbor)

    # Step 3: Add missing nodes to the graph with empty neighbors
    for missing_node in missing_nodes:
        graph[missing_node] = []

    return graph


def main():
    algorithm_path = 'algorithms.dfs.python'
    algorithm_name = 'dfs'
    function_name = 'dfs'
    dataset_path = 'datasets/graph_datasets/gigantic_graph_dataset.csv'

    dfs_function = load_algorithm(algorithm_path, algorithm_name, function_name)
    graph = load_graph_dataset(dataset_path)
    start_node = 'N1'

    start_time = time.time()
    visited_nodes = dfs_function(graph, start_node)
    end_time = time.time()

    print(f"DFS traversal starting from {start_node}: {visited_nodes}")
    print(f"Time taken: {end_time - start_time:.6f} seconds")

if __name__ == "__main__":
    main()

# python -m algorithms.dfs.main_dfs
