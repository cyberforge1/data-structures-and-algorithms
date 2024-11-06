import time  # Import the time module

def linear_search(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1

# Sample local dataset
local_dataset = [324, 123, 560, 453, 231, 876, 987, 1023, 657, 456, 234, 345]

# Target value to search for
target_value = 123  # Adjust this value to test different numbers

# Run the linear search and measure time taken
if __name__ == "__main__":
    start_time = time.time()  # Capture start time
    result = linear_search(local_dataset, target_value)
    end_time = time.time()  # Capture end time
    
    # Calculate elapsed time
    elapsed_time = end_time - start_time

    # Print the result and the time taken
    if result != -1:
        print(f"Target {target_value} found at index {result}.")
    else:
        print(f"Target {target_value} not found in the dataset.")
    
    print(f"Time taken: {elapsed_time:.6f} seconds")
