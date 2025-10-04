/**
 * Topological Sorting (DFS-based)
 * 
 * Description: Linear ordering of vertices in a Directed Acyclic Graph (DAG) such that
 * for every directed edge u→v, vertex u comes before v in the ordering.
 * 
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 * 
 * Use Cases:
 * - Task scheduling with dependencies
 * - Build systems and compilation order
 * - Course prerequisite planning
 * - Package dependency resolution
 * 
 * Example:
 * Input: graph = {5: [2,0], 4: [0,1], 2: [3], 3: [1], 1: [], 0: []}
 * Output: [5, 4, 2, 3, 1, 0] (one valid ordering)
 */

function topologicalSort(graph) {
    // Input validation
    if (!graph || typeof graph !== 'object') {
        throw new Error('Invalid input: graph must be an adjacency list');
    }

    const visited = new Set();
    const stack = [];
    const recursionStack = new Set();

    function dfsVisit(vertex) {
        // Cycle detection
        if (recursionStack.has(vertex)) {
            throw new Error('Graph contains a cycle - topological sort not possible');
        }
        
        if (visited.has(vertex)) return;

        visited.add(vertex);
        recursionStack.add(vertex);

        // Visit all neighbors
        const neighbors = graph[vertex] || [];
        for (let neighbor of neighbors) {
            dfsVisit(neighbor);
        }

        recursionStack.delete(vertex);
        stack.push(vertex);
    }

    // Process all vertices
    for (let vertex in graph) {
        if (!visited.has(vertex)) {
            dfsVisit(vertex);
        }
    }

    return stack.reverse();
}

// Kahn's Algorithm (BFS-based alternative)
function topologicalSortBFS(graph) {
    const inDegree = {};
    const result = [];
    const queue = [];

    // Initialize in-degrees
    for (let vertex in graph) {
        if (!(vertex in inDegree)) inDegree[vertex] = 0;
        for (let neighbor of graph[vertex]) {
            inDegree[neighbor] = (inDegree[neighbor] || 0) + 1;
        }
    }

    // Add vertices with 0 in-degree to queue
    for (let vertex in inDegree) {
        if (inDegree[vertex] === 0) {
            queue.push(vertex);
        }
    }

    while (queue.length > 0) {
        const current = queue.shift();
        result.push(current);

        // Reduce in-degree of neighbors
        for (let neighbor of (graph[current] || [])) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] === 0) {
                queue.push(neighbor);
            }
        }
    }

    // Check if all vertices were processed (no cycle)
    if (result.length !== Object.keys(graph).length) {
        throw new Error('Graph contains a cycle');
    }

    return result;
}

// Find all possible topological orderings
function allTopologicalSorts(graph) {
    const visited = new Set();
    const results = [];
    const path = [];

    function backtrack() {
        if (path.length === Object.keys(graph).length) {
            results.push([...path]);
            return;
        }

        for (let vertex in graph) {
            if (visited.has(vertex)) continue;

            // Check if all prerequisites are satisfied
            let canAdd = true;
            for (let v in graph) {
                if (!visited.has(v) && graph[v].includes(vertex)) {
                    canAdd = false;
                    break;
                }
            }

            if (canAdd) {
                visited.add(vertex);
                path.push(vertex);
                backtrack();
                path.pop();
                visited.delete(vertex);
            }
        }
    }

    backtrack();
    return results;
}

// Test cases
const graph = {
    '5': ['2', '0'],
    '4': ['0', '1'],
    '2': ['3'],
    '3': ['1'],
    '1': [],
    '0': []
};

console.log('DFS-based:', topologicalSort(graph)); // ['5', '4', '2', '3', '1', '0']
console.log('BFS-based:', topologicalSortBFS(graph)); // ['4', '5', '0', '2', '3', '1']

// Course scheduling example
const courses = {
    'CS101': [],
    'CS102': ['CS101'],
    'CS201': ['CS102'],
    'CS202': ['CS102'],
    'CS301': ['CS201', 'CS202']
};
console.log('Course order:', topologicalSort(courses));

module.exports = { topologicalSort, topologicalSortBFS, allTopologicalSorts };
