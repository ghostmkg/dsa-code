// Problem: Kruskal's Algorithm - Minimum Spanning Tree (MST)
// Language: C++
// Topic: Graphs / Greedy Algorithms / Disjoint Set Union
// Description:
// Kruskal’s algorithm finds the Minimum Spanning Tree (MST) of a connected, weighted graph.
// It sorts all edges in ascending order of weight and adds them one by one,
// avoiding cycles using the Disjoint Set Union (Union-Find) data structure.
// Time Complexity: O(E * logE), where E = number of edges
// Space Complexity: O(V), where V = number of vertices

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false; // Same component, adding this edge creates a cycle

        // Union by rank
        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[py] < rank[px])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }

        return true;
    }
};

class Solution {
public:
    // Each edge is represented as {u, v, weight}
    int kruskalMST(int V, vector<vector<int>>& edges) {
        // Sort edges by weight
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        DSU dsu(V);
        int mstWeight = 0;
        vector<vector<int>> mstEdges;

        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];

            if (dsu.unite(u, v)) {
                mstWeight += w;
                mstEdges.push_back({u, v, w});
            }
        }

        // Print MST edges
        cout << "Edges in the Minimum Spanning Tree:\n";
        for (auto& e : mstEdges)
            cout << e[0] << " - " << e[1] << " : " << e[2] << "\n";

        return mstWeight;
    }
};

int main() {
    /*
        Example Graph:
        Vertices = 4
        Edges = 5
        Edge list: (u, v, w)
        0 -- 1 (10)
        0 -- 2 (6)
        0 -- 3 (5)
        1 -- 3 (15)
        2 -- 3 (4)

        Expected MST:
        Edges -> (2,3,4), (0,3,5), (0,1,10)
        Total Weight = 19
    */

    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    Solution sol;
    int totalWeight = sol.kruskalMST(V, edges);

    cout << "\nTotal weight of MST: " << totalWeight << endl;

    return 0;
}
