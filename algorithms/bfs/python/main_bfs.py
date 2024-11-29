# algorithms/bfs/python/main_bfs.py

import importlib
import pandas as pd
import time

def load_algorithm(algorithm_path, algorithm_name, function_name):
    module = importlib.import_module(f"{algorithm_path}.{algorithm_name}")
    return getattr(module, function_name)

def load_graph_dataset(dataset_path):
    df = pd.read_csv(dataset_path, header=None, names=["Node", "Neighbors"], quotechar='"')
    graph = {}
    node_map = {}
    reverse_map = {}
    current_index = 0

    for _, row in df.iterrows():
        node_label = row["Node"]
        if node_label not in node_map:
            node_map[node_label] = current_index
            reverse_map[current_index] = node_label
            current_index += 1

        neighbors = row["Neighbors"].split(",") if pd.notna(row["Neighbors"]) else []
        graph[node_map[node_label]] = [
            node_map[neighbor] if neighbor in node_map else node_map.setdefault(neighbor, current_index) or current_index for neighbor in neighbors
        ]
        current_index += len([n for n in neighbors if n not in node_map])

    return graph, node_map, reverse_map

def main():
    """
    Main function to run BFS on a loaded graph dataset.
    """
    algorithm_path = 'algorithms.bfs.python'
    algorithm_name = 'bfs'
    function_name = 'bfs'
    dataset_path = 'datasets/graph_datasets/gigantic_graph_dataset.csv'
    target_node_label = 'N49993'

    bfs_function = load_algorithm(algorithm_path, algorithm_name, function_name)
    graph, node_map, reverse_map = load_graph_dataset(dataset_path)

    if target_node_label not in node_map:
        print(f"Node {target_node_label} not found in the graph.")
        return

    start_node = node_map[target_node_label]

    start_time = time.time()
    traversal_order = bfs_function(graph, start_node)
    end_time = time.time()

    traversal_labels = [reverse_map[node] for node in traversal_order]

    print(f"BFS traversal starting from {target_node_label}: {traversal_labels}")
    print(f"Time taken: {end_time - start_time:.6f} seconds")

if __name__ == "__main__":
    main()