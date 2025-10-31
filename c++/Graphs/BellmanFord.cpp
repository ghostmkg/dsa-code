#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

const int INF = 1e9;

class Solution {
public:
    vector<int> bellmanFord(int V, int startNode, const vector<tuple<int, int, int>>& edges) {
        // 1. initialize distances
        vector<int> dist(V, INF);
        dist[startNode] = 0;

        // 2. main relaxation loop (v-1 times)
        // after v-1 passes, all shortest paths should be found (if no negative cycles)
        for (int i = 0; i < V - 1; ++i) {
            bool updated = false;
            for (const auto& edge : edges) {
                int u, v, weight;
                tie(u, v, weight) = edge; 

                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    updated = true;
                }
            }
            // optimization: if no distance was updated, we can stop early
            if (!updated) break; 
        }

        // 3. negative Cycle Check (The V-th pass)
        for (const auto& edge : edges) {
            int u, v, weight;
            tie(u, v, weight) = edge;

            // if a distance can still be reduced, a negative cycle exists
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                return {}; 
            }
        }

        return dist;
    }
};

/*
// example for testing:
int main() {
    Solution s;
    int V = 5; 
    
    // Edges: (source, destination, weight)
    vector<tuple<int, int, int>> edges_no_cycle = {
        {0, 1, 6}, {0, 2, 7}, {1, 3, 5}, {1, 4, -4}, 
        {2, 3, -8}, {3, 1, -2}, {4, 3, 9}
    };

    // Example with no negative cycle
    vector<int> result = s.bellmanFord(V, 0, edges_no_cycle);
    
    if (result.empty()) {
        cout << "Negative cycle detected or graph is empty." << endl;
    } else {
        cout << "Shortest distances from source 0: [ ";
        for (int d : result) {
            cout << (d == s.INF ? "INF" : to_string(d)) << " ";
        }
        cout << "]" << endl; // Expected: [ 0 2 7 -2 -4 ]
    }

    return 0;
}
*/