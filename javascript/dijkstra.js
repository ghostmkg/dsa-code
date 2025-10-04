/**
 * Dijkstra's Shortest Path Algorithm
 * 
 * Description: Finds the shortest paths from a source vertex to all other vertices
 * in a weighted graph with non-negative edge weights using a greedy approach.
 * 
 * Time Complexity: O((V + E) log V) with min-heap, O(V²) with array
 * Space Complexity: O(V)
 * 
 * Use Cases:
 * - GPS navigation and route planning
 * - Network routing protocols (OSPF)
 * - Social network connection strength
 * - Game AI pathfinding
 * 
 * Example:
 * Input: graph = {0: [[1,4], [2,1]], 1: [[3,1]], 2: [[1,2], [3,5]], 3: []}, source = 0
 * Output: {0: 0, 1: 3, 2: 1, 3: 4}
 */

class MinHeap {
    constructor() {
        this.heap = [];
    }

    push(node) {
        this.heap.push(node);
        this.bubbleUp(this.heap.length - 1);
    }

    pop() {
        if (this.heap.length === 0) return null;
        if (this.heap.length === 1) return this.heap.pop();
        
        const min = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbleDown(0);
        return min;
    }

    bubbleUp(index) {
        while (index > 0) {
            const parentIndex = Math.floor((index - 1) / 2);
            if (this.heap[index].distance >= this.heap[parentIndex].distance) break;
            [this.heap[index], this.heap[parentIndex]] = [this.heap[parentIndex], this.heap[index]];
            index = parentIndex;
        }
    }

    bubbleDown(index) {
        while (true) {
            let smallest = index;
            const left = 2 * index + 1;
            const right = 2 * index + 2;

            if (left < this.heap.length && this.heap[left].distance < this.heap[smallest].distance) {
                smallest = left;
            }
            if (right < this.heap.length && this.heap[right].distance < this.heap[smallest].distance) {
                smallest = right;
            }
            if (smallest === index) break;

            [this.heap[index], this.heap[smallest]] = [this.heap[smallest], this.heap[index]];
            index = smallest;
        }
    }

    isEmpty() {
        return this.heap.length === 0;
    }
}

function dijkstra(graph, source) {
    // Input validation
    if (!graph || typeof source !== 'number') {
        throw new Error('Invalid input: graph must be an object and source must be a number');
    }

    const distances = {};
    const previous = {};
    const visited = new Set();
    const minHeap = new MinHeap();

    // Initialize distances
    for (let vertex in graph) {
        distances[vertex] = vertex == source ? 0 : Infinity;
        previous[vertex] = null;
    }

    minHeap.push({ vertex: source, distance: 0 });

    while (!minHeap.isEmpty()) {
        const { vertex: current, distance: currentDist } = minHeap.pop();

        if (visited.has(current)) continue;
        visited.add(current);

        // Process neighbors
        for (let [neighbor, weight] of (graph[current] || [])) {
            if (visited.has(neighbor)) continue;

            const newDist = currentDist + weight;
            if (newDist < distances[neighbor]) {
                distances[neighbor] = newDist;
                previous[neighbor] = current;
                minHeap.push({ vertex: neighbor, distance: newDist });
            }
        }
    }

    return { distances, previous };
}

// Helper function to reconstruct path
function getPath(previous, target) {
    const path = [];
    let current = target;
    
    while (current !== null) {
        path.unshift(current);
        current = previous[current];
    }
    
    return path.length > 1 ? path : null;
}

// Test cases
const graph = {
    0: [[1, 4], [2, 1]],
    1: [[3, 1]],
    2: [[1, 2], [3, 5]],
    3: []
};

const result = dijkstra(graph, 0);
console.log('Distances:', result.distances); // {0: 0, 1: 3, 2: 1, 3: 4}
console.log('Path to 3:', getPath(result.previous, '3')); // [0, 2, 1, 3]

module.exports = { dijkstra, getPath };
