/**
 * Program: Dijkstra's Shortest Path Algorithm
 * Problem Statement: Find the shortest path from a source vertex to all other vertices
 * in a weighted graph with non-negative edge weights.
 * 
 * Input Example:
 *   Graph with 5 vertices (0-4)
 *   Edges: (0,1,4), (0,2,1), (1,3,1), (2,1,2), (2,3,5), (3,4,3)
 *   Source: 0
 * 
 * Output Example:
 *   Shortest distances from vertex 0:
 *   Vertex 0: 0
 *   Vertex 1: 3
 *   Vertex 2: 1
 *   Vertex 3: 4
 *   Vertex 4: 7
 * 
 * Time Complexity: O((V + E) log V) using priority queue
 * Space Complexity: O(V)
 * Where V = vertices, E = edges
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <iomanip>

class Graph {
private:
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adjacency_list;

public:
    // Constructor
    explicit Graph(int v) : vertices(v) {
        adjacency_list.resize(v);
    }

    // Add weighted edge to the graph
    void addEdge(int source, int destination, int weight) {
        if (source >= 0 && source < vertices && destination >= 0 && destination < vertices) {
            adjacency_list[source].push_back({destination, weight});
            // For undirected graph, uncomment the line below:
            // adjacency_list[destination].push_back({source, weight});
        }
    }

    // Dijkstra's algorithm implementation
    std::vector<int> dijkstra(int source) {
        // Distance array initialized to infinity
        std::vector<int> distance(vertices, INT_MAX);
        
        // Priority queue: {distance, vertex}
        std::priority_queue<std::pair<int, int>, 
                          std::vector<std::pair<int, int>>, 
                          std::greater<std::pair<int, int>>> pq;

        // Distance to source is 0
        distance[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int current_distance = pq.top().first;
            int current_vertex = pq.top().second;
            pq.pop();

            // Skip if we've already found a shorter path
            if (current_distance > distance[current_vertex]) {
                continue;
            }

            // Check all adjacent vertices
            for (const auto& edge : adjacency_list[current_vertex]) {
                int neighbor = edge.first;
                int weight = edge.second;
                int new_distance = distance[current_vertex] + weight;

                // If shorter path is found
                if (new_distance < distance[neighbor]) {
                    distance[neighbor] = new_distance;
                    pq.push({new_distance, neighbor});
                }
            }
        }

        return distance;
    }

    // Print the graph
    void printGraph() {
        std::cout << "\nGraph Adjacency List:" << std::endl;
        for (int i = 0; i < vertices; i++) {
            std::cout << "Vertex " << i << ": ";
            for (const auto& edge : adjacency_list[i]) {
                std::cout << "(" << edge.first << ", w=" << edge.second << ") ";
            }
            std::cout << std::endl;
        }
    }

    // Print shortest distances
    void printShortestDistances(int source, const std::vector<int>& distances) {
        std::cout << "\nShortest distances from vertex " << source << ":" << std::endl;
        std::cout << std::setw(8) << "Vertex" << std::setw(12) << "Distance" << std::endl;
        std::cout << std::string(20, '-') << std::endl;
        
        for (int i = 0; i < vertices; i++) {
            std::cout << std::setw(8) << i;
            if (distances[i] == INT_MAX) {
                std::cout << std::setw(12) << "INF" << std::endl;
            } else {
                std::cout << std::setw(12) << distances[i] << std::endl;
            }
        }
    }
};

// Function to demonstrate Dijkstra's algorithm with different examples
void demonstrateDijkstra() {
    std::cout << "=== Dijkstra's Algorithm Demo ===" << std::endl;

    // Example 1: Small graph
    std::cout << "\n--- Example 1: Small Graph ---" << std::endl;
    Graph g1(5);
    g1.addEdge(0, 1, 4);
    g1.addEdge(0, 2, 1);
    g1.addEdge(1, 3, 1);
    g1.addEdge(2, 1, 2);
    g1.addEdge(2, 3, 5);
    g1.addEdge(3, 4, 3);

    g1.printGraph();
    std::vector<int> distances1 = g1.dijkstra(0);
    g1.printShortestDistances(0, distances1);

    // Example 2: Larger graph
    std::cout << "\n--- Example 2: Larger Graph ---" << std::endl;
    Graph g2(6);
    g2.addEdge(0, 1, 5);
    g2.addEdge(0, 2, 3);
    g2.addEdge(1, 3, 6);
    g2.addEdge(1, 4, 2);
    g2.addEdge(2, 1, 1);
    g2.addEdge(2, 4, 10);
    g2.addEdge(3, 5, 2);
    g2.addEdge(4, 3, 4);
    g2.addEdge(4, 5, 6);

    g2.printGraph();
    std::vector<int> distances2 = g2.dijkstra(0);
    g2.printShortestDistances(0, distances2);
}

// Interactive function to create custom graph
void interactiveMode() {
    int vertices, edges, source;
    
    std::cout << "\n=== Interactive Mode ===" << std::endl;
    std::cout << "Enter number of vertices: ";
    std::cin >> vertices;
    
    if (vertices <= 0) {
        std::cout << "Invalid number of vertices!" << std::endl;
        return;
    }

    Graph g(vertices);
    
    std::cout << "Enter number of edges: ";
    std::cin >> edges;
    
    std::cout << "Enter edges (source destination weight):" << std::endl;
    for (int i = 0; i < edges; i++) {
        int src, dest, weight;
        std::cout << "Edge " << (i + 1) << ": ";
        std::cin >> src >> dest >> weight;
        
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices && weight >= 0) {
            g.addEdge(src, dest, weight);
        } else {
            std::cout << "Invalid edge! Skipping..." << std::endl;
            i--; // Retry current edge
        }
    }
    
    std::cout << "Enter source vertex (0 to " << (vertices - 1) << "): ";
    std::cin >> source;
    
    if (source >= 0 && source < vertices) {
        g.printGraph();
        std::vector<int> distances = g.dijkstra(source);
        g.printShortestDistances(source, distances);
    } else {
        std::cout << "Invalid source vertex!" << std::endl;
    }
}

int main() {
    int choice;
    
    std::cout << "Dijkstra's Shortest Path Algorithm" << std::endl;
    std::cout << "1. Run demonstration examples" << std::endl;
    std::cout << "2. Interactive mode" << std::endl;
    std::cout << "3. Both" << std::endl;
    std::cout << "Enter your choice (1-3): ";
    std::cin >> choice;
    
    switch (choice) {
        case 1:
            demonstrateDijkstra();
            break;
        case 2:
            interactiveMode();
            break;
        case 3:
            demonstrateDijkstra();
            interactiveMode();
            break;
        default:
            std::cout << "Invalid choice! Running demonstration..." << std::endl;
            demonstrateDijkstra();
    }
    
    std::cout << "\nProgram completed successfully!" << std::endl;
    return 0;
}
