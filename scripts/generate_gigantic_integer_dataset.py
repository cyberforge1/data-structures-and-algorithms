# scripts/generate_gigantic_integer_dataset.py

# Writes to: datasets/integer_datasets/gigantic_integer_dataset.csv

import random
import csv
import os

def generate_gigantic_dataset(filename="../datasets/integer_datasets/gigantic_integer_dataset.csv", num_elements=1000000, min_value=1, max_value=100000):
    # Ensure the directory exists
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    
    with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file)
        for _ in range(num_elements):
            writer.writerow([random.randint(min_value, max_value)])
    print(f"Dataset with {num_elements} elements saved to {filename}")

# Generate the dataset
generate_gigantic_dataset()
