# algorithms/dfs/python/dfs.py

def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    for next_node in graph.get(start, []):  # Use .get() to avoid KeyError
        if next_node not in visited:
            dfs(graph, next_node, visited)
    return visited
