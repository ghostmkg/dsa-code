// Graph class using adjacency list
class Graph {
    constructor() {
        this.adjList = new Map();
    }

    // Add a vertex to the graph
    addVertex(vertex) {
        if (!this.adjList.has(vertex)) {
            this.adjList.set(vertex, []);
        }
    }

    // Add an edge between two vertices (undirected graph)
    addEdge(v, w) {
        if (this.adjList.has(v)) this.adjList.get(v).push(w);
        if (this.adjList.has(w)) this.adjList.get(w).push(v);
    }

    // Breadth-First Search
    bfs(startingVertex) {
        const visited = new Set();          // Track visited vertices
        const queue = [];                   // Queue for BFS
        const result = [];                  // Store the order of traversal

        visited.add(startingVertex);
        queue.push(startingVertex);

        while (queue.length > 0) {
            const vertex = queue.shift();   // Dequeue vertex
            result.push(vertex);

            const neighbors = this.adjList.get(vertex);
            for (const neighbor of neighbors) {
                if (!visited.has(neighbor)) {
                    visited.add(neighbor);
                    queue.push(neighbor);
                }
            }
        }

        return result;
    }
}

// Example usage
const g = new Graph();

// Add vertices
['A', 'B', 'C', 'D', 'E', 'F'].forEach(v => g.addVertex(v));

// Add edges
g.addEdge('A', 'B');
g.addEdge('A', 'C');
g.addEdge('B', 'D');
g.addEdge('B', 'E');
g.addEdge('C', 'F');

// Perform BFS starting from vertex 'A'
const bfsResult = g.bfs('A');
console.log("BFS Traversal Order:", bfsResult.join(' -> '));
// Output: BFS Traversal Order: A -> B -> C -> D -> E -> F