/**
 * Kruskal's Minimum Spanning Tree Algorithm
 * 
 * Description: Finds a minimum spanning tree for a weighted undirected graph using
 * a greedy approach with Union-Find data structure to detect cycles.
 * 
 * Time Complexity: O(E log E) or O(E log V)
 * Space Complexity: O(V)
 * 
 * Use Cases:
 * - Network design (laying cables, pipes)
 * - Approximation algorithms for NP-hard problems
 * - Cluster analysis
 * - Image segmentation
 * 
 * Example:
 * Input: edges = [[0,1,4], [0,2,3], [1,2,1], [1,3,2], [2,3,4]], vertices = 4
 * Output: {mst: [[1,2,1], [1,3,2], [0,2,3]], totalCost: 6}
 */

class UnionFind {
    constructor(size) {
        this.parent = Array.from({ length: size }, (_, i) => i);
        this.rank = new Array(size).fill(0);
        this.components = size;
    }

    find(x) {
        if (this.parent[x] !== x) {
            this.parent[x] = this.find(this.parent[x]); // Path compression
        }
        return this.parent[x];
    }

    union(x, y) {
        const rootX = this.find(x);
        const rootY = this.find(y);

        if (rootX === rootY) return false;

        // Union by rank
        if (this.rank[rootX] < this.rank[rootY]) {
            this.parent[rootX] = rootY;
        } else if (this.rank[rootX] > this.rank[rootY]) {
            this.parent[rootY] = rootX;
        } else {
            this.parent[rootY] = rootX;
            this.rank[rootX]++;
        }

        this.components--;
        return true;
    }

    isConnected(x, y) {
        return this.find(x) === this.find(y);
    }

    getComponentCount() {
        return this.components;
    }
}

function kruskalMST(vertices, edges) {
    // Input validation
    if (!Number.isInteger(vertices) || !Array.isArray(edges)) {
        throw new Error('Invalid input parameters');
    }

    // Sort edges by weight
    const sortedEdges = edges.slice().sort((a, b) => a[2] - b[2]);
    
    const uf = new UnionFind(vertices);
    const mst = [];
    let totalCost = 0;

    for (let [u, v, weight] of sortedEdges) {
        // Add edge if it doesn't create a cycle
        if (uf.union(u, v)) {
            mst.push([u, v, weight]);
            totalCost += weight;

            // Early termination when MST is complete
            if (mst.length === vertices - 1) break;
        }
    }

    // Check if graph is connected
    const isConnected = uf.getComponentCount() === 1;

    return {
        mst,
        totalCost,
        isConnected,
        edgesUsed: mst.length
    };
}

// Find all spanning trees (for small graphs)
function allSpanningTrees(vertices, edges) {
    const results = [];
    
    function backtrack(index, selected, uf) {
        if (selected.length === vertices - 1) {
            if (uf.getComponentCount() === 1) {
                results.push({
                    edges: [...selected],
                    cost: selected.reduce((sum, [,,w]) => sum + w, 0)
                });
            }
            return;
        }

        if (index >= edges.length) return;

        // Try including current edge
        const [u, v, weight] = edges[index];
        const newUF = Object.create(uf);
        newUF.parent = [...uf.parent];
        newUF.rank = [...uf.rank];
        newUF.components = uf.components;

        if (newUF.union(u, v)) {
            selected.push(edges[index]);
            backtrack(index + 1, selected, newUF);
            selected.pop();
        }

        // Try excluding current edge
        backtrack(index + 1, selected, uf);
    }

    backtrack(0, [], new UnionFind(vertices));
    return results;
}

// Calculate total possible edges for complete graph
function maxEdges(vertices) {
    return (vertices * (vertices - 1)) / 2;
}

// Test cases
const edges = [
    [0, 1, 4],
    [0, 2, 3],
    [1, 2, 1],
    [1, 3, 2],
    [2, 3, 4]
];

const result = kruskalMST(4, edges);
console.log('MST edges:', result.mst); // [[1,2,1], [1,3,2], [0,2,3]]
console.log('Total cost:', result.totalCost); // 6
console.log('Is connected:', result.isConnected); // true

// Test with disconnected graph
const disconnectedEdges = [[0, 1, 1], [2, 3, 1]];
const disconnectedResult = kruskalMST(4, disconnectedEdges);
console.log('Disconnected graph:', disconnectedResult.isConnected); // false

module.exports = { kruskalMST, UnionFind, allSpanningTrees, maxEdges };
