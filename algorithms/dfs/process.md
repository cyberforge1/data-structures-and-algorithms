# Depth First Search (DFS)

1. Start at the specified starting node.
2. Mark the current node as visited.
3. Explore each unvisited neighbor of the current node:
   - For each neighbor, recursively apply DFS.
4. Continue until all nodes reachable from the starting node are visited.

## Characteristics
- DFS uses a stack data structure (implicitly with recursion or explicitly with an iterative approach).
- It explores as far as possible along a branch before backtracking.

## Time Complexity
- **O(V + E)** — Where V is the number of vertices (nodes) and E is the number of edges. Each node is visited once, and each edge is traversed once.

## Space Complexity
- **O(V)** — For the recursion stack or an explicit stack to keep track of visited nodes.

## Use Cases
- Pathfinding in mazes or graphs.
- Detecting cycles in a graph.
- Topological sorting of a directed graph.
- Finding connected components in an undirected graph. 