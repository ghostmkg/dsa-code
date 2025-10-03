#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, set<char>> adj;
        unordered_map<char, int> indegree;

        // Initialize indegree map with all characters
        for (auto &w : words)
            for (char c : w)
                indegree[c] = 0;

        // Build graph (edges)
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i+1];
            if (w1.size() > w2.size() && w1.find(w2) == 0) return "";
            for (int j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) {
                    if (!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }

        // Topological Sort (Kahn's Algorithm)
        queue<char> q;
        for (auto &p : indegree)
            if (p.second == 0) q.push(p.first);

        string order = "";
        while (!q.empty()) {
            char c = q.front(); q.pop();
            order += c;
            for (auto neigh : adj[c]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) q.push(neigh);
            }
        }

        return (order.size() == indegree.size()) ? order : "";
    }
};
