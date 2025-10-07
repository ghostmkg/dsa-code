# Breadth First Search (BFS) Traversal in Python

def bfs(graph, start):
    visited = []           
    queue = [start]        

    while queue:
        node = queue.pop(0) 

        if node not in visited:
            visited.append(node)           
            queue.extend(graph[node])      

    return visited


# Example usage:
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

print("BFS Traversal:", bfs(graph, 'A'))
