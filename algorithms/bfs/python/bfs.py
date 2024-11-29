# algorithms/bfs/python/bfs.py

from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    traversal_order = []

    while queue:
        node = queue.popleft()

        if node not in visited:
            visited.add(node)
            traversal_order.append(node)
            for neighbor in graph.get(node, []):  # Use .get() to avoid KeyError
                if neighbor not in visited:
                    queue.append(neighbor)

    return traversal_order