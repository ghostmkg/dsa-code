def bellman_ford(vertex_count, edges, source):
    dist = [float('inf')] * vertex_count
    pred = [None] * vertex_count
    dist[source] = 0
    for _ in range(vertex_count - 1):
        updated = False
        for u, v, w in edges:
            if dist[u] != float('inf') and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                pred[v] = u
                updated = True
        if not updated:
            break
    for u, v, w in edges:
        if dist[u] != float('inf') and dist[u] + w < dist[v]:
            return None, None
    return dist, pred

def reconstruct_path(pred, target):
    path = []
    while target is not None:
        path.append(target)
        target = pred[target]
    return path[::-1]

if __name__ == "__main__":
    vertex_count = 5
    edges = [
        (0, 1, 6),
        (0, 2, 7),
        (1, 2, 8),
        (1, 3, 5),
        (1, 4, -4),
        (2, 3, -3),
        (2, 4, 9),
        (3, 1, -2),
        (4, 3, 7)
    ]
    source = 0
    dist, pred = bellman_ford(vertex_count, edges, source)
    if dist is None:
        print("Graph contains a negative-weight cycle")
    else:
        for v in range(vertex_count):
            if dist[v] == float('inf'):
                print(f"Vertex {v}: unreachable")
            else:
                path = reconstruct_path(pred, v)
                print(f"Vertex {v}: distance = {dist[v]}, path = {path}")
