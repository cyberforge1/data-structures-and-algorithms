import os

def sort_and_save_dataset(input_path, output_path):
    """Sort the integers in the dataset and save to a new file in the specified format."""
    try:
        # Read the dataset
        with open(input_path, 'r') as infile:
            data = [int(line.strip()) for line in infile if line.strip()]  # Read each line and convert to int
        
        # Sort the dataset
        data.sort()

        # Save the sorted dataset
        os.makedirs(os.path.dirname(output_path), exist_ok=True)  # Ensure the output directory exists
        with open(output_path, 'w') as outfile:
            for number in data:
                outfile.write(f"{number}\n")  # Write each number on a new line

        print(f"Sorted dataset saved to: {output_path}")
    except Exception as e:
        print(f"Error processing {input_path}: {e}")

def main():
    # Define file paths
    datasets = [
        "datasets/integer_datasets/non-sorted/gigantic_integer_dataset.csv",
        "datasets/integer_datasets/non-sorted/large_integer_dataset.csv",
        "datasets/integer_datasets/non-sorted/small_integer_dataset.csv",
    ]
    sorted_dir = "datasets/integer_datasets/sorted"

    # Process each dataset
    for dataset in datasets:
        filename = os.path.basename(dataset)  # Extract filename
        sorted_path = os.path.join(sorted_dir, filename)  # Create output path
        sort_and_save_dataset(dataset, sorted_path)

if __name__ == "__main__":
    main()
