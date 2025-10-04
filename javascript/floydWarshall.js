/**
 * Floyd-Warshall All-Pairs Shortest Path Algorithm
 * 
 * Description: Computes shortest paths between all pairs of vertices in a weighted graph.
 * Uses dynamic programming to find optimal paths through intermediate vertices.
 * 
 * Time Complexity: O(V³)
 * Space Complexity: O(V²)
 * 
 * Use Cases:
 * - Finding shortest paths between all city pairs
 * - Transitive closure of directed graphs
 * - Network optimization and analysis
 * - Computing graph diameter
 * 
 * Example:
 * Input: graph = [[0,3,∞,7], [8,0,2,∞], [5,∞,0,1], [2,∞,∞,0]]
 * Output: All-pairs shortest path matrix
 */

function floydWarshall(graph) {
    // Input validation
    if (!Array.isArray(graph) || graph.length === 0) {
        throw new Error('Invalid input: graph must be a non-empty 2D array');
    }

    const V = graph.length;
    const INF = Infinity;
    
    // Initialize distance matrix
    const dist = Array.from({ length: V }, (_, i) => 
        Array.from({ length: V }, (_, j) => graph[i][j])
    );
    
    // Initialize path reconstruction matrix
    const next = Array.from({ length: V }, () => Array(V).fill(null));
    
    for (let i = 0; i < V; i++) {
        for (let j = 0; j < V; j++) {
            if (i !== j && graph[i][j] !== INF) {
                next[i][j] = j;
            }
        }
    }

    // Floyd-Warshall algorithm
    for (let k = 0; k < V; k++) {
        for (let i = 0; i < V; i++) {
            for (let j = 0; j < V; j++) {
                if (dist[i][k] !== INF && dist[k][j] !== INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }

    // Check for negative cycles
    let hasNegativeCycle = false;
    for (let i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            hasNegativeCycle = true;
            break;
        }
    }

    return {
        distances: dist,
        next,
        hasNegativeCycle
    };
}

// Reconstruct path between two vertices
function getPath(next, u, v) {
    if (next[u][v] === null) return null;
    
    const path = [u];
    while (u !== v) {
        u = next[u][v];
        path.push(u);
    }
    return path;
}

// Get graph diameter (longest shortest path)
function getGraphDiameter(distances) {
    let diameter = 0;
    const INF = Infinity;
    
    for (let i = 0; i < distances.length; i++) {
        for (let j = 0; j < distances[i].length; j++) {
            if (i !== j && distances[i][j] !== INF) {
                diameter = Math.max(diameter, distances[i][j]);
            }
        }
    }
    
    return diameter === 0 ? INF : diameter;
}

// Test cases
const INF = Infinity;
const graph = [
    [0, 3, INF, 7],
    [8, 0, 2, INF],
    [5, INF, 0, 1],
    [2, INF, INF, 0]
];

const result = floydWarshall(graph);
console.log('Shortest distances:');
result.distances.forEach((row, i) => {
    console.log(`From vertex ${i}:`, row);
});

console.log('Path from 0 to 3:', getPath(result.next, 0, 3)); // [0, 1, 2, 3]
console.log('Graph diameter:', getGraphDiameter(result.distances)); // 10

module.exports = { floydWarshall, getPath, getGraphDiameter };
