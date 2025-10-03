/**
 * @file DijkstraShortestPath.cpp
 * @brief Implementation of Dijkstra's Shortest Path Algorithm
 * @author Hacktoberfest Contributor
 * @date October 2025
 *
 * Problem: Find shortest path from a source vertex to all other vertices
 * in a weighted graph with non-negative edge weights.
 *
 * Algorithm: Greedy approach using priority queue
 * - Start from source vertex with distance 0
 * - Maintain a priority queue of vertices ordered by distance
 * - Extract vertex with minimum distance
 * - Relax all adjacent edges (update distances if shorter path found)
 * - Repeat until all vertices processed
 *
 * Key Insight: Always process the closest unvisited vertex next.
 * Once a vertex is processed, we've found its shortest path.
 *
 * Time Complexity: O((V + E) log V) with priority queue (min-heap)
 *                  O(V²) with array-based implementation
 * Space Complexity: O(V + E) for adjacency list + priority queue
 *
 * Note: Does NOT work with negative edge weights (use Bellman-Ford for that)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

/**
 * @brief Edge structure to represent weighted edge
 */
struct Edge {
    int to;      // Destination vertex
    int weight;  // Edge weight

    Edge(int t, int w) : to(t), weight(w) {}
};

/**
 * @brief Node structure for priority queue (vertex, distance pair)
 */
struct Node {
    int vertex;
    int distance;

    Node(int v, int d) : vertex(v), distance(d) {}

    // For min-heap: smaller distance has higher priority
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

class Dijkstra {
private:
    static const int INF = INT_MAX;  // Represents infinity (unreachable)

public:
    /**
     * @brief Dijkstra's algorithm using priority queue (min-heap)
     * @param graph Adjacency list representation of weighted graph
     * @param source Source vertex
     * @return Vector of shortest distances from source to all vertices
     *
     * Algorithm Steps:
     * 1. Initialize distances to infinity, source to 0
     * 2. Add source to priority queue
     * 3. While queue not empty:
     *    a. Extract vertex u with minimum distance
     *    b. For each neighbor v of u:
     *       - If distance[u] + weight(u,v) < distance[v]:
     *         - Update distance[v]
     *         - Add v to priority queue
     */
    vector<int> findShortestPaths(const vector<vector<Edge>>& graph, int source) {
        int n = graph.size();
        vector<int> dist(n, INF);         // Distance from source to each vertex
        vector<bool> visited(n, false);   // Track processed vertices

        // Priority queue: min-heap of (distance, vertex)
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        // Initialize source
        dist[source] = 0;
        pq.push(Node(source, 0));

        while (!pq.empty()) {
            // Extract vertex with minimum distance
            Node current = pq.top();
            pq.pop();

            int u = current.vertex;

            // Skip if already processed (can have duplicates in PQ)
            if (visited[u]) continue;

            visited[u] = true;

            // Relax all adjacent edges
            for (const Edge& edge : graph[u]) {
                int v = edge.to;
                int weight = edge.weight;

                // Relaxation step: check if path through u is shorter
                if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(Node(v, dist[v]));
                }
            }
        }

        return dist;
    }

    /**
     * @brief Dijkstra with path reconstruction
     * @param graph Adjacency list
     * @param source Source vertex
     * @param parent Vector to store parent of each vertex in shortest path tree
     * @return Vector of shortest distances
     */
    vector<int> findShortestPathsWithParent(const vector<vector<Edge>>& graph,
                                           int source,
                                           vector<int>& parent) {
        int n = graph.size();
        vector<int> dist(n, INF);
        vector<bool> visited(n, false);
        parent.assign(n, -1);  // Initialize parent array

        priority_queue<Node, vector<Node>, greater<Node>> pq;

        dist[source] = 0;
        pq.push(Node(source, 0));

        while (!pq.empty()) {
            Node current = pq.top();
            pq.pop();

            int u = current.vertex;

            if (visited[u]) continue;
            visited[u] = true;

            for (const Edge& edge : graph[u]) {
                int v = edge.to;
                int weight = edge.weight;

                if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;  // Track parent for path reconstruction
                    pq.push(Node(v, dist[v]));
                }
            }
        }

        return dist;
    }

    /**
     * @brief Reconstruct shortest path from source to destination
     * @param parent Parent array from findShortestPathsWithParent
     * @param source Source vertex
     * @param dest Destination vertex
     * @return Vector containing path from source to dest
     */
    vector<int> reconstructPath(const vector<int>& parent, int source, int dest) {
        vector<int> path;

        // Check if path exists
        if (parent[dest] == -1 && dest != source) {
            return path;  // No path exists
        }

        // Backtrack from destination to source
        for (int v = dest; v != -1; v = parent[v]) {
            path.push_back(v);
        }

        // Reverse to get path from source to dest
        reverse(path.begin(), path.end());

        return path;
    }

    /**
     * @brief Print shortest distances from source to all vertices
     * @param dist Distance array
     * @param source Source vertex
     * @param vertices Optional vertex labels
     */
    void printDistances(const vector<int>& dist, int source,
                       const vector<string>& vertices = {}) {
        cout << "\nShortest distances from ";
        if (!vertices.empty()) {
            cout << vertices[source];
        } else {
            cout << source;
        }
        cout << ":" << endl;

        for (int i = 0; i < dist.size(); i++) {
            cout << "To ";
            if (!vertices.empty()) {
                cout << vertices[i];
            } else {
                cout << i;
            }
            cout << ": ";

            if (dist[i] == INF) {
                cout << "INF (unreachable)";
            } else {
                cout << dist[i];
            }
            cout << endl;
        }
    }

    /**
     * @brief Print path from source to destination
     * @param path Vector containing path vertices
     * @param dist Distance array
     * @param dest Destination vertex
     * @param vertices Optional vertex labels
     */
    void printPath(const vector<int>& path, const vector<int>& dist, int dest,
                  const vector<string>& vertices = {}) {
        if (path.empty()) {
            cout << "No path exists" << endl;
            return;
        }

        cout << "Path: ";
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
        cout << " (Total cost: " << dist[dest] << ")" << endl;
    }
};

/**
 * @brief Example usage and test cases
 */
int main() {
    Dijkstra dijkstra;

    // Test case 1: Simple graph
    cout << "=== Test Case 1: Simple Weighted Graph ===" << endl;

    // Graph with 5 vertices (0-4)
    // Edges: 0->1(4), 0->2(1), 2->1(2), 1->3(1), 2->3(5), 3->4(3)
    vector<vector<Edge>> graph1(5);
    graph1[0].push_back(Edge(1, 4));
    graph1[0].push_back(Edge(2, 1));
    graph1[2].push_back(Edge(1, 2));
    graph1[1].push_back(Edge(3, 1));
    graph1[2].push_back(Edge(3, 5));
    graph1[3].push_back(Edge(4, 3));

    int source1 = 0;
    vector<int> dist1 = dijkstra.findShortestPaths(graph1, source1);
    dijkstra.printDistances(dist1, source1);

    // Test case 2: Graph with path reconstruction
    cout << "\n=== Test Case 2: Path Reconstruction ===" << endl;

    // Graph: 0->1(7), 0->2(9), 0->5(14), 1->2(10), 1->3(15),
    //        2->3(11), 2->5(2), 3->4(6), 4->5(9)
    vector<vector<Edge>> graph2(6);
    graph2[0].push_back(Edge(1, 7));
    graph2[0].push_back(Edge(2, 9));
    graph2[0].push_back(Edge(5, 14));
    graph2[1].push_back(Edge(2, 10));
    graph2[1].push_back(Edge(3, 15));
    graph2[2].push_back(Edge(3, 11));
    graph2[2].push_back(Edge(5, 2));
    graph2[3].push_back(Edge(4, 6));
    graph2[4].push_back(Edge(5, 9));

    vector<string> vertices2 = {"A", "B", "C", "D", "E", "F"};
    int source2 = 0;
    vector<int> parent2;
    vector<int> dist2 = dijkstra.findShortestPathsWithParent(graph2, source2, parent2);

    dijkstra.printDistances(dist2, source2, vertices2);

    cout << "\nShortest paths:" << endl;
    for (int i = 1; i < 6; i++) {
        vector<int> path = dijkstra.reconstructPath(parent2, source2, i);
        cout << vertices2[source2] << " to " << vertices2[i] << ": ";
        dijkstra.printPath(path, dist2, i, vertices2);
    }

    // Test case 3: Disconnected graph
    cout << "\n=== Test Case 3: Disconnected Graph ===" << endl;

    vector<vector<Edge>> graph3(4);
    graph3[0].push_back(Edge(1, 5));
    graph3[1].push_back(Edge(0, 5));
    // Vertices 2 and 3 are disconnected from 0 and 1

    int source3 = 0;
    vector<int> dist3 = dijkstra.findShortestPaths(graph3, source3);
    dijkstra.printDistances(dist3, source3);

    // Test case 4: Dense graph
    cout << "\n=== Test Case 4: Complete Graph (Dense) ===" << endl;

    vector<vector<Edge>> graph4(4);
    // Complete graph where all vertices are connected
    graph4[0].push_back(Edge(1, 1));
    graph4[0].push_back(Edge(2, 4));
    graph4[0].push_back(Edge(3, 3));
    graph4[1].push_back(Edge(0, 1));
    graph4[1].push_back(Edge(2, 2));
    graph4[1].push_back(Edge(3, 5));
    graph4[2].push_back(Edge(0, 4));
    graph4[2].push_back(Edge(1, 2));
    graph4[2].push_back(Edge(3, 1));
    graph4[3].push_back(Edge(0, 3));
    graph4[3].push_back(Edge(1, 5));
    graph4[3].push_back(Edge(2, 1));

    int source4 = 0;
    vector<int> parent4;
    vector<int> dist4 = dijkstra.findShortestPathsWithParent(graph4, source4, parent4);

    dijkstra.printDistances(dist4, source4);

    cout << "\nOptimal paths:" << endl;
    for (int i = 1; i < 4; i++) {
        vector<int> path = dijkstra.reconstructPath(parent4, source4, i);
        cout << source4 << " to " << i << ": ";
        dijkstra.printPath(path, dist4, i);
    }

    return 0;
}
