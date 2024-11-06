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

def main():
    # Define paths
    algorithm_path = 'algorithms.linear_search'
    algorithm_name = 'linear_search'
    function_name = 'linear_search'
    dataset_path = 'datasets/integer_datasets/small_integer_dataset.csv'
    
    # Load algorithm and dataset
    search_function = load_algorithm(algorithm_path, algorithm_name, function_name)
    dataset = load_dataset(dataset_path)
    
    # Define the value to search for
    value_to_search = 627
    
    # Measure start time
    start_time = time.time()
    
    # Apply algorithm
    result = search_function(dataset, value_to_search)
    
    # Measure end time
    end_time = time.time()
    duration = end_time - start_time
    
    # Output result
    if result != -1:
        print(f"Value {value_to_search} found at index {result}")
    else:
        print(f"Value {value_to_search} not found")
    print(f"Time taken: {duration:.6f} seconds")

if __name__ == "__main__":
    main()
