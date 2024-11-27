# algorithms/linear_search/python/main.py

import csv
import os
from linear_search import linear_search

def load_dataset(file_path):
    """Load a dataset from a CSV file."""
    with open(file_path, 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            # Flatten the dataset into a list of integers
            return [int(item) for item in row]

def main():
    # Dynamically construct the absolute path to the dataset
    current_dir = os.path.dirname(os.path.abspath(__file__))
    dataset_path = os.path.join(current_dir, "../../../datasets/integer_datasets/gigantic_integer_dataset.csv")

    # Load the dataset
    print(f"Loading dataset from: {dataset_path}")
    data = load_dataset(dataset_path)

    # Element to search for
    target = 1  # Example target value
    print(f"Searching for {target} in the dataset...")

    # Perform linear search
    result = linear_search(data, target)

    # Print results
    if result != -1:
        print(f"Element {target} found at index {result}.")
    else:
        print(f"Element {target} not found in the dataset.")

if __name__ == "__main__":
    main()
