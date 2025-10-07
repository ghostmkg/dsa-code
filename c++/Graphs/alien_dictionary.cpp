// Problem: Alien Dictionary
// Language: C++
// Topic: Graphs / Topological Sorting
// Description:
// Given a sorted dictionary of an alien language, find the order of characters.
// Approach: Build a graph of character precedence and perform topological sort (Kahn’s Algorithm).
// Time Complexity: O(N * K), where N = number of words, K = alphabet size.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(vector<string>& dict, int K) {
        // Step 1: Build adjacency list for K characters
        vector<int> adj[K];

        // Compare adjacent words to find ordering
        for (int i = 0; i < dict.size() - 1; i++) {
            string word1 = dict[i];
            string word2 = dict[i + 1];
            int len = min(word1.size(), word2.size());

            for (int j = 0; j < len; j++) {
                if (word1[j] != word2[j]) {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    break; // Only first differing character matters
                }
            }
        }

        // Step 2: Perform Topological Sort (Kahn's Algorithm)
        vector<int> indegree(K, 0);
        for (int i = 0; i < K; i++) {
            for (auto it : adj[i])
                indegree[it]++;
        }

        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        string order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            order += (node + 'a');

            for (auto neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        // Step 3: Return result
        return order;
    }
};

int main() {
    /*
        Example:
        Dictionary = {"baa", "abcd", "abca", "cab", "cad"}
        K = 4  (characters: a, b, c, d)

        Possible order: b -> d -> a -> c
        Output: "bdac" (or another valid topological ordering)
    */

    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    int K = 4;

    Solution sol;
    string result = sol.findOrder(dict, K);

    cout << "Alien Dictionary Order: " << result << endl;

    return 0;
}
