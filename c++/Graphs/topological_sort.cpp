#include <vector>
#include <unordered_map>
#include <algorithm> // For std::reverse
#include <iostream>

using namespace std;

class Solution {
private:
    // 0: unvisited, 1: visiting (in current DFS stack), 2: visited (finished)
    bool hasCycle;
    vector<vector<int>> adj;
    vector<int> result;
    
    /**
     * @brief Performs DFS for topological sort and cycle detection.
     * @param u The current course node.
     * @param state The state array (0=unvisited, 1=visiting, 2=finished).
     * @return true if a cycle is detected, false otherwise.
     */
    bool dfs_util(int u, vector<int>& state) {
        // Mark current node as 'visiting' (in the current recursion stack)
        state[u] = 1;

        // Recurse on all neighbors
        for (int v : adj[u]) {
            if (state[v] == 1) {
                // Found a node that is currently being visited -> Cycle detected!
                hasCycle = true;
                return true;
            }
            if (state[v] == 0) {
                // Unvisited neighbor
                if (dfs_util(v, state)) {
                    return true;
                }
            }
        }

        // Mark current node as 'finished' and add it to the result
        // This is post-order traversal, which is the reverse topological order
        state[u] = 2;
        result.push_back(u);

        return false; // No cycle found starting from this node
    }

public:
    /**
     * @brief Finds a valid course order using topological sort.
     * @param numCourses The total number of courses (nodes).
     * @param prerequisites A list of pairs [course, prerequisite].
     * @return A vector representing the course order, or an empty vector if a cycle exists.
     */
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // --- Initialization ---
        adj.assign(numCourses, vector<int>());
        hasCycle = false;
        result.clear();

        // 1. Build the Adjacency List (Graph)
        // Edge: prerequisite[1] -> prerequisite[0] (i.e., to take course[0], you must first take course[1])
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            adj[prerequisite].push_back(course);
        }

        // 2. Perform DFS on all nodes
        // state: 0=unvisited, 1=visiting, 2=finished
        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0) {
                if (dfs_util(i, state)) {
                    // Cycle detected during DFS, stop and return empty
                    return {};
                }
            }
        }
        
        // 3. Final Result
        if (hasCycle) {
            // Should have been caught inside the loop, but for safety
            return {};
        }

        // The result is in reverse topological order (prerequisite first).
        // Reverse it to get the correct course order (course first).
        reverse(result.begin(), result.end());

        return result;
    }
};

// Example of how to use the corrected code (not part of the class, just for demonstration)
/*
int main() {
    Solution s;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0}, {2,0}, {3,1}, {3,2}}; // 0 -> 1, 0 -> 2, 1 -> 3, 2 -> 3
    vector<int> order = s.findOrder(numCourses, prerequisites);

    cout << "Course Order: ";
    for(int course : order) {
        cout << course << " "; // Expected output: 0 1 2 3 or 0 2 1 3
    }
    cout << endl;

    // Example with a cycle: 0 -> 1, 1 -> 0
    numCourses = 2;
    prerequisites = {{1,0}, {0,1}};
    order = s.findOrder(numCourses, prerequisites);
    cout << "Course Order (with cycle): ";
    if (order.empty()) {
        cout << "Impossible (Cycle Detected)";
    }
    cout << endl;

    return 0;
}
*/