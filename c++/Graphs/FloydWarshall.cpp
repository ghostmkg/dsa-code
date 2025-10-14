/*
 * Floyd-Warshall Algorithm Implementation
 * 
 * The Floyd-Warshall algorithm is used to find the shortest paths between all pairs
 * of vertices in a weighted graph. It works with both positive and negative edge weights
 * (but no negative cycles).
 * 
 * Time Complexity: O(V³) where V is the number of vertices
 * Space Complexity: O(V²) for the distance matrix
 * 
 * Key Features:
 * - Finds shortest paths between all pairs of vertices
 * - Handles negative weights (detects negative cycles)
 * - Dynamic programming approach
 * - Can reconstruct actual paths
 * 
 * Author: Hacktoberfest Contributor
 * Date: October 2024
 */

#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

class FloydWarshall {
private:
    int V; // Number of vertices
    vector<vector<int>> graph;
    vector<vector<int>> dist;
    vector<vector<int>> next; // For path reconstruction
    
    const int INF = 1e9; // Represents infinity
    
public:
    // Constructor
    FloydWarshall(int vertices) : V(vertices) {
        graph.assign(V, vector<int>(V, INF));
        dist.assign(V, vector<int>(V, INF));
        next.assign(V, vector<int>(V, -1));
        
        // Distance from a vertex to itself is 0
        for (int i = 0; i < V; i++) {
            graph[i][i] = 0;
            dist[i][i] = 0;
        }
    }
    
    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            graph[u][v] = weight;
            next[u][v] = v;
        }
    }
    
    // Core Floyd-Warshall algorithm
    void floydWarshall() {
        // Initialize distance matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = graph[i][j];
                if (graph[i][j] != INF && i != j) {
                    next[i][j] = j;
                }
            }
        }
        
        // Floyd-Warshall triple nested loop
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    // If path through k is shorter, update distance
                    if (dist[i][k] != INF && dist[k][j] != INF && 
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }
    
    // Check for negative cycles
    bool hasNegativeCycle() {
        for (int i = 0; i < V; i++) {
            if (dist[i][i] < 0) {
                return true;
            }
        }
        return false;
    }
    
    // Get shortest distance between two vertices
    int getDistance(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            return (dist[u][v] == INF) ? -1 : dist[u][v];
        }
        return -1;
    }
    
    // Reconstruct and return the shortest path
    vector<int> getPath(int u, int v) {
        vector<int> path;
        if (u >= V || v >= V || dist[u][v] == INF) {
            return path; // No path exists
        }
        
        int curr = u;
        path.push_back(curr);
        
        while (curr != v) {
            curr = next[curr][v];
            if (curr == -1) break; // No path
            path.push_back(curr);
        }
        
        return path;
    }
    
    // Print the distance matrix
    void printDistanceMatrix() {
        cout << "\n=== All Pairs Shortest Distances ===\n";
        cout << setw(8) << "";
        for (int j = 0; j < V; j++) {
            cout << setw(8) << "V" + to_string(j);
        }
        cout << "\n";
        
        for (int i = 0; i < V; i++) {
            cout << setw(8) << "V" + to_string(i);
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF) {
                    cout << setw(8) << "INF";
                } else {
                    cout << setw(8) << dist[i][j];
                }
            }
            cout << "\n";
        }
    }
    
    // Print a specific path
    void printPath(int u, int v) {
        vector<int> path = getPath(u, v);
        
        if (path.empty()) {
            cout << "No path from V" << u << " to V" << v << "\n";
            return;
        }
        
        cout << "Path from V" << u << " to V" << v << ": ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << "V" << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << " (Distance: " << dist[u][v] << ")\n";
    }
    
    // Print all shortest paths
    void printAllPaths() {
        cout << "\n=== All Shortest Paths ===\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i != j && dist[i][j] != INF) {
                    printPath(i, j);
                }
            }
        }
    }
};

// Utility function to create a sample graph for testing
void demonstrateFloydWarshall() {
    cout << "=== Floyd-Warshall Algorithm Demonstration ===\n\n";
    
    // Example 1: Simple 4-vertex graph
    cout << "Example 1: 4-vertex graph with positive weights\n";
    FloydWarshall fw1(4);
    
    fw1.addEdge(0, 1, 3);
    fw1.addEdge(0, 3, 7);
    fw1.addEdge(1, 0, 8);
    fw1.addEdge(1, 2, 2);
    fw1.addEdge(2, 0, 5);
    fw1.addEdge(2, 3, 1);
    fw1.addEdge(3, 0, 2);
    
    fw1.floydWarshall();
    
    if (fw1.hasNegativeCycle()) {
        cout << "Graph contains negative cycle!\n";
    } else {
        fw1.printDistanceMatrix();
        fw1.printAllPaths();
    }
    
    cout << "\n" << string(60, '-') << "\n";
    
    // Example 2: Graph with negative edges
    cout << "Example 2: Graph with negative edges\n";
    FloydWarshall fw2(4);
    
    fw2.addEdge(0, 1, 1);
    fw2.addEdge(1, 2, -3);
    fw2.addEdge(2, 3, 2);
    fw2.addEdge(3, 1, 1);
    fw2.addEdge(1, 3, 2);
    
    fw2.floydWarshall();
    
    if (fw2.hasNegativeCycle()) {
        cout << "Graph contains negative cycle!\n";
    } else {
        fw2.printDistanceMatrix();
        
        // Show some specific paths
        cout << "\nSample paths:\n";
        fw2.printPath(0, 3);
        fw2.printPath(0, 2);
        fw2.printPath(1, 3);
    }
}

// Interactive function to build custom graph
void interactiveDemo() {
    int V, E;
    cout << "\n=== Interactive Floyd-Warshall Demo ===\n";
    cout << "Enter number of vertices: ";
    cin >> V;
    
    FloydWarshall fw(V);
    
    cout << "Enter number of edges: ";
    cin >> E;
    
    cout << "Enter edges (format: from to weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v >> w;
        fw.addEdge(u, v, w);
    }
    
    fw.floydWarshall();
    
    if (fw.hasNegativeCycle()) {
        cout << "\nWarning: Graph contains negative cycle!\n";
        return;
    }
    
    fw.printDistanceMatrix();
    
    // Query shortest paths
    char choice;
    cout << "\nDo you want to query specific paths? (y/n): ";
    cin >> choice;
    
    while (choice == 'y' || choice == 'Y') {
        int from, to;
        cout << "Enter source and destination vertices: ";
        cin >> from >> to;
        
        fw.printPath(from, to);
        
        cout << "Query another path? (y/n): ";
        cin >> choice;
    }
}

int main() {
    cout << "Floyd-Warshall Algorithm Implementation\n";
    cout << "======================================\n";
    
    // Run demonstration
    demonstrateFloydWarshall();
    
    // Ask user for interactive demo
    char choice;
    cout << "\nWould you like to try the interactive demo? (y/n): ";
    cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        interactiveDemo();
    }
    
    cout << "\n=== Algorithm Analysis ===\n";
    cout << "Time Complexity: O(V³)\n";
    cout << "Space Complexity: O(V²)\n";
    cout << "Best for: All-pairs shortest paths in dense graphs\n";
    cout << "Handles: Negative weights (but not negative cycles)\n";
    
    return 0;
}

/*
 * Sample Input for Interactive Demo:
 * 4
 * 7
 * 0 1 3
 * 0 3 7
 * 1 2 2
 * 2 0 5
 * 2 3 1
 * 3 0 2
 * 1 0 8
 * 
 * Expected Output:
 * Shortest path matrix showing optimal distances between all vertex pairs
 */