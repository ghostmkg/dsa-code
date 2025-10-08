class Graph {
  constructor() {
    this.adjList = new Map(); // Adjacency list to store the graph
  }

  // Add a vertex to the graph
  addVertex(vertex) {
    if (!this.adjList.has(vertex)) {
      this.adjList.set(vertex, []);
    }
  }

  // Add an edge [neighbor, weight]
  addEdge(vertex1, vertex2, weight) {
    this.addVertex(vertex1);
    this.addVertex(vertex2);

    this.adjList.get(vertex1).push([vertex2, weight]);
    this.adjList.get(vertex2).push([vertex1, weight]); // Undirected graph
  }

  // Dijkstra's algorithm to find the shortest paths from source
  dijkstra(source) {
    const distances = {};
    const prev = {};
    const pq = new PriorityQueue();
    const visited = new Set();

    for (let vertex of this.adjList.keys()) {
      distances[vertex] = Infinity;
      prev[vertex] = null;
    }
    distances[source] = 0;
    pq.enqueue(source, 0);

    while (!pq.isEmpty()) {
      let { element: currentVertex } = pq.dequeue();
      if (visited.has(currentVertex)) continue;
      visited.add(currentVertex);

      for (let [neighbor, weight] of this.adjList.get(currentVertex)) {
        let alt = distances[currentVertex] + weight;
        if (alt < distances[neighbor]) {
          distances[neighbor] = alt;
          prev[neighbor] = currentVertex;
          pq.enqueue(neighbor, alt);
        }
      }
    }

    return { distances, prev };
  }

  // Helper function to reconstruct the shortest path
  getPath(prev, target) {
    let path = [];
    let currentNode = target;

    while (currentNode !== null) {
      path.unshift(currentNode);
      currentNode = prev[currentNode];
    }

    return path.length === 1 ? [] : path; // If no path found, return an empty array
  }
}

// Priority Queue for Dijkstra's Algorithm (Min-Heap)
class PriorityQueue {
  constructor() {
    this.queue = [];
  }

  enqueue(element, priority) {
    this.queue.push({ element, priority });
    this.sort();
  }

  dequeue() {
    return this.queue.shift(); // Removes the element with the highest priority (lowest value)
  }

  isEmpty() {
    return this.queue.length === 0;
  }

  sort() {
    this.queue.sort((a, b) => a.priority - b.priority);
  }
}

// Example usage:
const graph = new Graph();

// Add edges (Undirected graph)
graph.addEdge("A", "B", 4);
graph.addEdge("A", "C", 2);
graph.addEdge("B", "C", 5);
graph.addEdge("B", "D", 10);
graph.addEdge("C", "D", 3);
graph.addEdge("D", "E", 7);
graph.addEdge("C", "E", 1);

// Run Dijkstra's algorithm from source node 'A'
const { distances, prev } = graph.dijkstra("A");

// Output the shortest distances from A to all nodes
console.log("Shortest Distances from A:", distances);

// Output the shortest path from A to D
const path = graph.getPath(prev, "D");
console.log("Shortest Path from A to D:", path);

// To check:
// Navigate to the javascript directory and run the file using Node.js:
// Terminal: node dijkstra.js

// Expected Output:
// Shortest Distances from A: { A: 0, B: 4, C: 2, D: 5, E: 3 }
// Shortest Path from A to D: [ 'A', 'C', 'D' ]
