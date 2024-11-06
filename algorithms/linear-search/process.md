# Linear Search

1. Start at the beginning of the list.
2. Check each item one by one to see if it matches the target value you're looking for.
3. If you find the target, stop the search and return the position of that item.
4. If you reach the end of the list without finding the target, it means the item isn’t in the list.

## Time Complexity
- **Best Case**: O(1) — The target is at the beginning of the list.
- **Worst Case**: O(n) — The target is at the end of the list, or it isn’t in the list at all, requiring a check of every item.
- **Average Case**: O(n) — On average, you will search through about half of the list before finding the target.

## Space Complexity
- **O(1)** — Linear search only requires a constant amount of extra space for variables, regardless of the list size, as it doesn't use any additional data structures.
