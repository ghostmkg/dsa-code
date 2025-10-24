#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> adj, res;
    vector<int> disc, low;
    int timeCounter;

    void dfs(int u, int parent) {
        disc[u] = low[u] = ++timeCounter;
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (!disc[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) res.push_back({u, v}); // bridge
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.assign(n, {});
        for (auto &e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        disc.assign(n, 0);
        low.assign(n, 0);
        timeCounter = 0;

        for (int i = 0; i < n; i++)
            if (!disc[i]) dfs(i, -1);

        return res;
    }
};
