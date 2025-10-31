import heapq

def dijkstra(graph, start):
    """
    Dijkstra's algorithm to find shortest paths from start node to all other nodes.

    Parameters:
    graph : dict - adjacency list {node: [(neighbor, weight), ...]}
    start : starting node

    Returns:
    distances : dict - shortest distance from start to each node
    """

    distances = {node: float('inf') for node in graph}
    distances[start] = 0

    priority_queue = [(0, start)]  # (distance, node)

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances

# Example usage:
if __name__ == "__main__":
    graph = {
        'A': [('B', 1), ('C', 4)],
        'B': [('A', 1), ('C', 2), ('D', 5)],
        'C': [('A', 4), ('B', 2), ('D', 1)],
        'D': [('B', 5), ('C', 1)]
    }
    start_node = 'A'
    print("Shortest distances:", dijkstra(graph, start_node))
