// Define the graph structure using an adjacency list.
// Key is the vertex index (number), value is an array of neighbors.
type AdjacencyList = { [key: number]: number[] };

/**
 * Performs a Breadth-First Search (BFS) traversal starting from a source node.
 * @param graph The graph represented as an adjacency list.
 * @param startNode The starting vertex for the traversal.
 * @returns An array of nodes in the order they were visited.
 */
function breadthFirstSearch(graph: AdjacencyList, startNode: number): number[] {
  // Check if the start node exists
  if (!graph[startNode]) {
    return [];
  }

  const visited: Set<number> = new Set();
  const queue: number[] = [startNode];
  const result: number[] = [];

  visited.add(startNode);

  // Continue as long as there are nodes to process
  while (queue.length > 0) {
    // Dequeue the first node
    const node = queue.shift()!;
    result.push(node);

    // Get all neighbors of the current node
    const neighbors = graph[node];

    // Process each neighbor
    for (const neighbor of neighbors) {
      if (!visited.has(neighbor)) {
        visited.add(neighbor);
        queue.push(neighbor); // Enqueue the unvisited neighbor
      }
    }
  }

  return result;
}

// --- Usage Example ---
const V_BFS = 6; // Vertices 0 to 5
const graphBFS: AdjacencyList = {
  0: [1, 2],
  1: [3],
  2: [4, 5],
  3: [0],
  4: [],
  5: [2],
};

const traversalOrder = breadthFirstSearch(graphBFS, 0);
console.log("\n--- Breadth-First Search (BFS) Traversal ---");
console.log(
  `Traversal Order (starting from 0): [${traversalOrder.join(", ")}]`,
);
// Expected Output: [0, 1, 2, 3, 4, 5]
