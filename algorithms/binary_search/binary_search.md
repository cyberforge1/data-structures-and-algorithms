# Binary Search

1. Start with the list already sorted in ascending order.
2. Set two markers: one at the beginning (low) and one at the end (high) of the list.
3. Calculate the middle point between the low and high markers.
4. Check if the item at the middle point matches the target:
   - If it does, stop the search and return the position of the item.
   - If the target is smaller than the middle item, move the high marker just before the middle, narrowing the search to the left half.
   - If the target is larger than the middle item, move the low marker just after the middle, narrowing the search to the right half.
5. Repeat steps 3 and 4, recalculating the middle point each time, until you find the target or the low and high markers cross, indicating that the target is not in the list.

## Time Complexity
- **Best Case**: O(1) — The target is found at the middle point on the first check.
- **Worst Case**: O(log n) — Each step halves the number of items to search through, resulting in logarithmic time complexity.
- **Average Case**: O(log n) — On average, binary search will find the target in logarithmic time as the list is repeatedly divided.

## Space Complexity
- **O(1)** — Binary search requires a constant amount of extra space for variables, as it doesn't use additional data structures beyond the markers and middle pointer.
