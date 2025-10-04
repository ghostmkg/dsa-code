/**
 * Union-Find (Disjoint Set Union) Data Structure
 * 
 * Description: Keeps track of elements partitioned into disjoint (non-overlapping)
 * sets. Supports union and find operations efficiently using path compression
 * and union by rank.
 * 
 * Time Complexity:
 * - Find: O(α(n)) ≈ O(1) amortized (with path compression)
 * - Union: O(α(n)) ≈ O(1) amortized (with union by rank)
 * - Connected: O(α(n)) ≈ O(1)
 * 
 * Space Complexity: O(n)
 * 
 * Use Cases:
 * - Kruskal's MST algorithm
 * - Cycle detection in undirected graphs
 * - Network connectivity
 * - Image processing (connected components)
 * 
 * Example:
 * uf.union(1, 2);
 * uf.union(2, 3);
 * uf.connected(1, 3);  // true
 */

class UnionFind {
    constructor(size) {
        if (!Number.isInteger(size) || size < 0) {
            throw new Error('Size must be a non-negative integer');
        }

        this.parent = Array.from({ length: size }, (_, i) => i);
        this.rank = new Array(size).fill(0);
        this.size = new Array(size).fill(1);
        this.componentCount = size;
    }

    /**
     * Find root of element with path compression
     * @param {number} x - Element
     * @returns {number} Root of element
     */
    find(x) {
        if (x < 0 || x >= this.parent.length) {
            throw new Error('Element out of bounds');
        }

        if (this.parent[x] !== x) {
            this.parent[x] = this.find(this.parent[x]); // Path compression
        }
        return this.parent[x];
    }

    /**
     * Union two elements by rank
     * @param {number} x - First element
     * @param {number} y - Second element
     * @returns {boolean} True if union performed (elements were in different sets)
     */
    union(x, y) {
        const rootX = this.find(x);
        const rootY = this.find(y);

        if (rootX === rootY) return false;

        // Union by rank
        if (this.rank[rootX] < this.rank[rootY]) {
            this.parent[rootX] = rootY;
            this.size[rootY] += this.size[rootX];
        } else if (this.rank[rootX] > this.rank[rootY]) {
            this.parent[rootY] = rootX;
            this.size[rootX] += this.size[rootY];
        } else {
            this.parent[rootY] = rootX;
            this.size[rootX] += this.size[rootY];
            this.rank[rootX]++;
        }

        this.componentCount--;
        return true;
    }

    /**
     * Check if two elements are in the same set
     * @param {number} x - First element
     * @param {number} y - Second element
     * @returns {boolean}
     */
    connected(x, y) {
        return this.find(x) === this.find(y);
    }

    /**
     * Get number of disjoint sets
     * @returns {number}
     */
    getComponentCount() {
        return this.componentCount;
    }

    /**
     * Get size of component containing element
     * @param {number} x - Element
     * @returns {number}
     */
    getComponentSize(x) {
        return this.size[this.find(x)];
    }

    /**
     * Get all elements in the same component as x
     * @param {number} x - Element
     * @returns {number[]}
     */
    getComponent(x) {
        const root = this.find(x);
        const component = [];

        for (let i = 0; i < this.parent.length; i++) {
            if (this.find(i) === root) {
                component.push(i);
            }
        }

        return component;
    }

    /**
     * Get all components as arrays
     * @returns {number[][]}
     */
    getAllComponents() {
        const components = new Map();

        for (let i = 0; i < this.parent.length; i++) {
            const root = this.find(i);
            if (!components.has(root)) {
                components.set(root, []);
            }
            components.get(root).push(i);
        }

        return Array.from(components.values());
    }

    /**
     * Reset to initial state (all elements separate)
     */
    reset() {
        for (let i = 0; i < this.parent.length; i++) {
            this.parent[i] = i;
            this.rank[i] = 0;
            this.size[i] = 1;
        }
        this.componentCount = this.parent.length;
    }

    /**
     * Check if all elements are in one component
     * @returns {boolean}
     */
    isFullyConnected() {
        return this.componentCount === 1;
    }

    /**
     * Get string representation
     * @returns {string}
     */
    toString() {
        const components = this.getAllComponents();
        return `UnionFind(${this.componentCount} components): ${
            components.map(c => `[${c.join(',')}]`).join(' ')
        }`;
    }

    /**
     * Visualize structure
     * @returns {string}
     */
    visualize() {
        const lines = ['Union-Find Structure:'];
        const components = this.getAllComponents();

        components.forEach((component, idx) => {
            const root = this.find(component[0]);
            lines.push(`\nComponent ${idx + 1} (root: ${root}, size: ${this.size[root]}):`);
            lines.push(`  Elements: ${component.join(', ')}`);
        });

        return lines.join('\n');
    }
}

// Weighted Union-Find (tracks edge weights)
class WeightedUnionFind extends UnionFind {
    constructor(size) {
        super(size);
        this.weight = new Array(size).fill(0);
    }

    find(x) {
        if (this.parent[x] !== x) {
            const originalParent = this.parent[x];
            this.parent[x] = this.find(this.parent[x]);
            this.weight[x] += this.weight[originalParent];
        }
        return this.parent[x];
    }

    union(x, y, w) {
        const rootX = this.find(x);
        const rootY = this.find(y);

        if (rootX === rootY) return false;

        this.parent[rootX] = rootY;
        this.weight[rootX] = this.weight[y] - this.weight[x] + w;
        this.componentCount--;
        return true;
    }

    diff(x, y) {
        if (!this.connected(x, y)) {
            throw new Error('Elements are not connected');
        }
        return this.weight[x] - this.weight[y];
    }
}

// Test cases
console.log('=== Basic Union-Find ===');
const uf = new UnionFind(10);

console.log('Initial state:', uf.toString());
console.log('Component count:', uf.getComponentCount()); // 10

console.log('\nPerforming unions:');
uf.union(0, 1);
uf.union(1, 2);
uf.union(3, 4);
uf.union(5, 6);
uf.union(6, 7);

console.log(uf.toString());

console.log('\nConnectivity checks:');
console.log('0 and 2 connected:', uf.connected(0, 2)); // true
console.log('0 and 3 connected:', uf.connected(0, 3)); // false
console.log('5 and 7 connected:', uf.connected(5, 7)); // true

console.log('\nComponent information:');
console.log('Component containing 0:', uf.getComponent(0)); // [0, 1, 2]
console.log('Size of component with 0:', uf.getComponentSize(0)); // 3

console.log('\nAll components:');
console.log(uf.getAllComponents());

console.log('\n' + uf.visualize());

// Cycle detection example
console.log('\n=== Cycle Detection in Graph ===');
const graphUF = new UnionFind(5);
const edges = [[0, 1], [1, 2], [2, 3], [3, 4], [4, 1]]; // Last edge creates cycle

for (let [u, v] of edges) {
    if (graphUF.connected(u, v)) {
        console.log(`Cycle detected at edge [${u}, ${v}]`);
        break;
    }
    graphUF.union(u, v);
    console.log(`Added edge [${u}, ${v}]`);
}

// Network connectivity example
console.log('\n=== Network Connectivity ===');
const network = new UnionFind(6);
console.log('Initial networks:', network.getComponentCount());

network.union(0, 1); // Connect computer 0 and 1
network.union(2, 3); // Connect computer 2 and 3
console.log('After 2 connections:', network.getComponentCount()); // 4 networks

network.union(1, 2); // Bridge the two networks
console.log('After bridging:', network.getComponentCount()); // 3 networks
console.log('Largest network size:', network.getComponentSize(0)); // 4

console.log('\n=== Weighted Union-Find ===');
const wuf = new WeightedUnionFind(5);
wuf.union(0, 1, 3);
wuf.union(1, 2, 2);
console.log('Difference between 0 and 2:', wuf.diff(0, 2)); // Should be 5

module.exports = { UnionFind, WeightedUnionFind };
