/**
 * @file FloydWarshall.cpp
 * @brief Implementation of Floyd-Warshall All-Pairs Shortest Path Algorithm
 * @author Hacktoberfest Contributor
 * @date October 2025
 *
 * Problem: Find shortest paths between all pairs of vertices in a weighted graph.
 * Works with both positive and negative edge weights (but no negative cycles).
 *
 * Algorithm: Dynamic Programming
 * - Use intermediate vertices to find shortest paths
 * - For each pair (i,j), try all possible intermediate vertices k
 * - dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
 * - Update distance if path through k is shorter
 *
 * Key Insight: If shortest path from i to j goes through vertices {1,2,...,k},
 * it can be split into i->k and k->j, both using vertices {1,2,...,k-1}
 *
 * Time Complexity: O(V³) where V is number of vertices
 * Space Complexity: O(V²) for distance matrix
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
using namespace std;

class FloydWarshall {
private:
    static const int INF = 1e9;  // Represents infinity (unreachable)

public:
    /**
     * @brief Floyd-Warshall algorithm to find all-pairs shortest paths
     * @param graph Adjacency matrix representation of graph (graph[i][j] = weight)
     * @return Matrix of shortest distances between all pairs
     *
     * Algorithm Steps:
     * 1. Initialize distance matrix with direct edge weights
     * 2. For each intermediate vertex k:
     *    - For each pair of vertices (i, j):
     *      - Check if path i -> k -> j is shorter than current i -> j
     *      - Update if shorter path found
     */
    vector<vector<int>> findShortestPaths(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> dist = graph;  // Copy graph to dist matrix

        // Try each vertex as intermediate point
        for (int k = 0; k < n; k++) {
            // Pick all vertices as source one by one
            for (int i = 0; i < n; i++) {
                // Pick all vertices as destination for above source
                for (int j = 0; j < n; j++) {
                    // If vertex k is on the shortest path from i to j,
                    // then update dist[i][j]
                    if (dist[i][k] != INF && dist[k][j] != INF &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        return dist;
    }

    /**
     * @brief Floyd-Warshall with path reconstruction
     * @param graph Adjacency matrix
     * @param next Matrix to store next vertex in shortest path
     * @return Matrix of shortest distances
     */
    vector<vector<int>> findShortestPathsWithReconstruction(
        vector<vector<int>>& graph,
        vector<vector<int>>& next) {

        int n = graph.size();
        vector<vector<int>> dist = graph;

        // Initialize next matrix
        next.assign(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] != INF && i != j) {
                    next[i][j] = j;
                }
            }
        }

        // Floyd-Warshall with path tracking
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k];  // Update path
                    }
                }
            }
        }

        return dist;
    }

    /**
     * @brief Reconstruct path from source to destination
     * @param next Next vertex matrix from findShortestPathsWithReconstruction
     * @param u Source vertex
     * @param v Destination vertex
     * @return Vector containing path from u to v
     */
    vector<int> reconstructPath(vector<vector<int>>& next, int u, int v) {
        if (next[u][v] == -1) {
            return {};  // No path exists
        }

        vector<int> path;
        path.push_back(u);

        while (u != v) {
            u = next[u][v];
            path.push_back(u);
        }

        return path;
    }

    /**
     * @brief Detect negative cycle in graph
     * @param graph Adjacency matrix
     * @return true if negative cycle exists, false otherwise
     *
     * A negative cycle exists if after running Floyd-Warshall,
     * any vertex has negative distance to itself
     */
    bool hasNegativeCycle(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> dist = findShortestPaths(graph);

        // Check diagonal for negative values
        for (int i = 0; i < n; i++) {
            if (dist[i][i] < 0) {
                return true;  // Negative cycle detected
            }
        }

        return false;
    }

    /**
     * @brief Print distance matrix in formatted way
     * @param dist Distance matrix
     * @param vertices Optional vertex labels
     */
    void printDistanceMatrix(const vector<vector<int>>& dist,
                            const vector<string>& vertices = {}) {
        int n = dist.size();

        // Print header
        cout << "\nShortest Distance Matrix:" << endl;
        cout << setw(8) << " ";
        for (int i = 0; i < n; i++) {
            if (!vertices.empty()) {
                cout << setw(8) << vertices[i];
            } else {
                cout << setw(8) << i;
            }
        }
        cout << endl;

        // Print matrix
        for (int i = 0; i < n; i++) {
            if (!vertices.empty()) {
                cout << setw(8) << vertices[i];
            } else {
                cout << setw(8) << i;
            }

            for (int j = 0; j < n; j++) {
                if (dist[i][j] == INF) {
                    cout << setw(8) << "INF";
                } else {
                    cout << setw(8) << dist[i][j];
                }
            }
            cout << endl;
        }
    }

    /**
     * @brief Print path from source to destination
     * @param path Vector containing path vertices
     * @param vertices Optional vertex labels
     */
    void printPath(const vector<int>& path, const vector<string>& vertices = {}) {
        if (path.empty()) {
            cout << "No path exists" << endl;
            return;
        }

        for (int i = 0; i < path.size(); i++) {
            if (!vertices.empty()) {
                cout << vertices[path[i]];
            } else {
                cout << path[i];
            }
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
};

/**
 * @brief Example usage and test cases
 */
int main() {
    FloydWarshall solver;
    const int INF = 1e9;

    // Test case 1: Simple weighted graph
    cout << "=== Test Case 1: Simple Weighted Graph ===" << endl;
    vector<vector<int>> graph1 = {
        {0,   5,   INF, 10},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    vector<string> vertices1 = {"A", "B", "C", "D"};
    vector<vector<int>> dist1 = solver.findShortestPaths(graph1);
    solver.printDistanceMatrix(dist1, vertices1);

    // Test case 2: Graph with path reconstruction
    cout << "\n=== Test Case 2: Path Reconstruction ===" << endl;
    vector<vector<int>> graph2 = {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };

    vector<string> vertices2 = {"0", "1", "2", "3"};
    vector<vector<int>> next;
    vector<vector<int>> dist2 = solver.findShortestPathsWithReconstruction(graph2, next);

    solver.printDistanceMatrix(dist2, vertices2);

    cout << "\nShortest paths:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j && dist2[i][j] != INF) {
                cout << vertices2[i] << " to " << vertices2[j] << " (cost " << dist2[i][j] << "): ";
                vector<int> path = solver.reconstructPath(next, i, j);
                solver.printPath(path, vertices2);
            }
        }
    }

    // Test case 3: Graph with negative edges (but no negative cycle)
    cout << "\n=== Test Case 3: Graph with Negative Edges ===" << endl;
    vector<vector<int>> graph3 = {
        {0,   -1,  4,   INF},
        {INF, 0,   3,   2},
        {INF, INF, 0,   INF},
        {INF, 1,   5,   0}
    };

    vector<vector<int>> dist3 = solver.findShortestPaths(graph3);
    solver.printDistanceMatrix(dist3);

    // Test case 4: Negative cycle detection
    cout << "\n=== Test Case 4: Negative Cycle Detection ===" << endl;
    vector<vector<int>> graph4 = {
        {0,   1,   INF},
        {INF, 0,   -3},
        {-5,  INF, 0}
    };

    if (solver.hasNegativeCycle(graph4)) {
        cout << "Graph contains a negative cycle!" << endl;
    } else {
        cout << "Graph does not contain a negative cycle." << endl;
        vector<vector<int>> dist4 = solver.findShortestPaths(graph4);
        solver.printDistanceMatrix(dist4);
    }

    return 0;
}
