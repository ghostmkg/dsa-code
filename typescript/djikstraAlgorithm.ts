type Graph = Map<string, [string, number][]>;

function dijkstra(graph: Graph, start: string): Map<string, number> {
  const distances = new Map<string, number>();
  const visited = new Set<string>();

  // Initialize distances to Infinity
  for (const node of graph.keys()) {
    distances.set(node, Infinity);
  }

  distances.set(start, 0);

  while (visited.size < graph.size) {
    // Find unvisited node with the smallest distance
    let currentNode: string | null = null;
    let smallestDistance = Infinity;

    for (const [node, distance] of distances) {
      if (!visited.has(node) && distance < smallestDistance) {
        smallestDistance = distance;
        currentNode = node;
      }
    }

    if (currentNode === null) break;

    visited.add(currentNode);

    const neighbors = graph.get(currentNode) || [];
    for (const [neighbor, weight] of neighbors) {
      const currentDistance = distances.get(currentNode)! + weight;
      if (currentDistance < distances.get(neighbor)!) {
        distances.set(neighbor, currentDistance);
      }
    }
  }

  return distances;
}
