class Dijkstra {
  // Function to find the shortest path from the source node to all other nodes
  static dijkstra(graph: number[][], start: number): number[] {
    const n = graph.length; // Number of nodes in the graph
    const distances = new Array(n).fill(Infinity); // Array to store shortest distance from start to each node
    const visited = new Array(n).fill(false); // Array to track visited nodes
    distances[start] = 0; // Distance from start node to itself is 0

    for (let count = 0; count < n - 1; count++) {
      // Find the node with the smallest distance from the start node
      let minDistance = Infinity;
      let minNode = -1;

      for (let i = 0; i < n; i++) {
        if (!visited[i] && distances[i] < minDistance) {
          minDistance = distances[i];
          minNode = i;
        }
      }

      // Mark the node as visited
      visited[minNode] = true;

      // Update the distance to its neighbors
      for (let i = 0; i < n; i++) {
        if (!visited[i] && graph[minNode][i] !== 0 && distances[minNode] !== Infinity) {
          const newDist = distances[minNode] + graph[minNode][i];
          if (newDist < distances[i]) {
            distances[i] = newDist;
          }
        }
      }
    }

    return distances;
  }
}

// Example Usage:

// Graph represented as an adjacency matrix
// 0 means no direct edge between nodes
const graph = [
  [0, 10, 0, 0, 0, 0],
  [10, 0, 5, 0, 0, 0],
  [0, 5, 0, 20, 0, 0],
  [0, 0, 20, 0, 5, 2],
  [0, 0, 0, 5, 0, 1],
  [0, 0, 0, 2, 1, 0]
];

// Find the shortest path from node 0 (source)
const startNode = 0;
const shortestPaths = Dijkstra.dijkstra(graph, startNode);

console.log(`Shortest distances from node ${startNode}:`);
for (let i = 0; i < shortestPaths.length; i++) {
  console.log(`Node ${i}: ${shortestPaths[i]}`);
}
