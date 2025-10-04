/**
 * Bellman-Ford Shortest Path Algorithm
 * 
 * Description: Computes shortest paths from a source vertex to all other vertices
 * in a weighted graph. Unlike Dijkstra, it handles negative edge weights and detects
 * negative cycles.
 * 
 * Time Complexity: O(V × E)
 * Space Complexity: O(V)
 * 
 * Use Cases:
 * - Currency arbitrage detection
 * - Network routing with negative weights
 * - Detecting negative cycles in financial systems
 * - Distance vector routing protocols
 * 
 * Example:
 * Input: edges = [[0,1,4], [0,2,1], [2,1,2], [1,3,1], [2,3,5]], vertices = 4, source = 0
 * Output: {distances: [0, 3, 1, 4], hasNegativeCycle: false}
 */

function bellmanFord(vertices, edges, source) {
    // Input validation
    if (!Number.isInteger(vertices) || !Array.isArray(edges) || typeof source !== 'number') {
        throw new Error('Invalid input parameters');
    }

    const distances = new Array(vertices).fill(Infinity);
    const previous = new Array(vertices).fill(null);
    distances[source] = 0;

    // Relax edges V-1 times
    for (let i = 0; i < vertices - 1; i++) {
        let updated = false;
        
        for (let [u, v, weight] of edges) {
            if (distances[u] !== Infinity && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                updated = true;
            }
        }

        // Early termination if no updates
        if (!updated) break;
    }

    // Check for negative cycles
    let hasNegativeCycle = false;
    for (let [u, v, weight] of edges) {
        if (distances[u] !== Infinity && distances[u] + weight < distances[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    return {
        distances,
        previous,
        hasNegativeCycle
    };
}

// Helper function to get negative cycle
function detectNegativeCycle(vertices, edges, source) {
    const result = bellmanFord(vertices, edges, source);
    
    if (result.hasNegativeCycle) {
        // Find vertices affected by negative cycle
        const affected = [];
        const distances = [...result.distances];
        
        for (let i = 0; i < vertices; i++) {
            for (let [u, v, weight] of edges) {
                if (distances[u] !== Infinity && distances[u] + weight < distances[v]) {
                    distances[v] = -Infinity;
                    affected.push(v);
                }
            }
        }
        
        return { hasNegativeCycle: true, affectedVertices: affected };
    }
    
    return { hasNegativeCycle: false };
}

// Test cases
const edges = [
    [0, 1, 4],
    [0, 2, 1],
    [2, 1, 2],
    [1, 3, 1],
    [2, 3, 5]
];

const result = bellmanFord(4, edges, 0);
console.log('Distances:', result.distances); // [0, 3, 1, 4]
console.log('Has negative cycle:', result.hasNegativeCycle); // false

// Test with negative cycle
const negativeEdges = [[0, 1, 1], [1, 2, -3], [2, 0, 1]];
const negResult = bellmanFord(3, negativeEdges, 0);
console.log('Negative cycle detected:', negResult.hasNegativeCycle); // true

module.exports = { bellmanFord, detectNegativeCycle };
