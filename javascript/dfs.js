// Graph class using adjacency list
class Graph {
    constructor() {
        this.adjList = new Map();
    }

    // Add a vertex
    addVertex(vertex) {
        if (!this.adjList.has(vertex)) {
            this.adjList.set(vertex, []);
        }
    }

    // Add an edge (undirected graph)
    addEdge(v, w) {
        if (this.adjList.has(v)) this.adjList.get(v).push(w);
        if (this.adjList.has(w)) this.adjList.get(w).push(v);
    }

    // Depth-First Search
    dfs(startingVertex) {
        const visited = new Set();
        const result = [];

        const dfsRecursive = (vertex) => {
            visited.add(vertex);
            result.push(vertex);

            const neighbors = this.adjList.get(vertex);
            for (const neighbor of neighbors) {
                if (!visited.has(neighbor)) {
                    dfsRecursive(neighbor);
                }
            }
        };

        dfsRecursive(startingVertex);
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

// Perform DFS starting from vertex 'A'
const dfsResult = g.dfs('A');
console.log("DFS Traversal Order:", dfsResult.join(' -> '));
// Output: DFS Traversal Order: A -> B -> D -> E -> C -> F
