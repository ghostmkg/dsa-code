#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9; // A large number representing infinity

// Dijkstra's Algorithm to find the shortest path from a source node
void dijkstra(int n, int src, vector<vector<pair<int,int>>>& adj) {
    vector<int> dist(n + 1, INF); // distance array
    dist[src] = 0;

    // Min-heap priority queue: (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        // Explore neighbors
        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            cout << "Node " << i << " : INF\n";
        else
            cout << "Node " << i << " : " << dist[i] << "\n";
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // If the graph is undirected, uncomment below:
        // adj[v].push_back({u, w});
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    dijkstra(n, src, adj);
    return 0;
}
