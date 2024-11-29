# Breadth First Search (BFS)

1. Start at the specified starting node.
2. Mark the current node as visited and enqueue it.
3. While the queue is not empty:
   - Dequeue a node from the front of the queue.
   - Explore each unvisited neighbor of the dequeued node:
     - Mark the neighbor as visited and enqueue it.
4. Continue until all nodes reachable from the starting node are visited.

## Characteristics
- BFS uses a queue data structure.
- It explores all neighbors of a node before moving to the next level (breadth-first traversal).

## Time Complexity
- **O(V + E)** — Where V is the number of vertices (nodes) and E is the number of edges. Each node is visited once, and each edge is traversed once.

## Space Complexity
- **O(V)** — For the queue used to track the nodes to visit.

## Use Cases
- Finding the shortest path in an unweighted graph.
- Level-order traversal of trees.
- Detecting connected components in a graph.
- Solving puzzles like finding the shortest path in a maze.
