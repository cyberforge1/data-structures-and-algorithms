import os
from algorithms.linear_search import linear_search

# Function to read integers from a file
def read_integers_from_file(file_path):
    """
    Reads a list of integers from a file, with each integer on a new line.
    
    Parameters:
    - file_path: Path to the file.

    Returns:
    - List of integers.
    """
    integers = []
    with open(file_path, 'r') as file:
        for line in file:
            integers.append(int(line.strip()))
    return integers

# Generic function to apply linear search to datasets
def apply_linear_search_to_datasets(target):
    """
    Applies the linear search function to each dataset in the datasets folder.
    
    Parameters:
    - target: The integer to search for in each dataset.
    """
    # Define the datasets directory
    datasets_dir = "datasets/integer-datasets/"
    
    # Loop through each file in the datasets directory
    for filename in os.listdir(datasets_dir):
        if filename.endswith(".csv"):
            # Construct the full path to the file
            file_path = os.path.join(datasets_dir, filename)
            # Load the dataset
            integer_list = read_integers_from_file(file_path)
            # Run linear search
            result = linear_search(integer_list, target)
            # Print the result
            if result != -1:
                print(f"Target {target} found in {filename} at index {result}.")
            else:
                print(f"Target {target} not found in {filename}.")

# Example usage
target_value = 123  # Replace with any integer you want to search for
apply_linear_search_to_datasets(target_value)
