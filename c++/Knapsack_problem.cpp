/*
 * Algorithm: 0/1 Knapsack Problem
 * Language: C++
 * Description: Given weights and values of n items, determine the maximum value
 *              that can be put in a knapsack of capacity W. Each item can be 
 *              included at most once (0/1 property).
 * Time Complexity: O(n * W) where n = number of items, W = knapsack capacity
 * Space Complexity: O(n * W)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Function to solve 0/1 Knapsack problem using DP
 *
 * @param weights vector of item weights
 * @param values vector of item values
 * @param capacity maximum capacity of the knapsack
 * @return maximum total value that fits in the knapsack
 */
int knapsack01(const vector<int> &weights, const vector<int> &values, int capacity) {
    int n = weights.size();

    // DP table initialization (n+1 x capacity+1)
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                // Take maximum of including or excluding current item
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                // Cannot include current item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity]; // Maximum value achievable
}

/**
 * Test function for 0/1 Knapsack implementation
 */
void testKnapsack() {
    vector<pair<vector<int>, vector<int>>> testCases = {
        {{1, 2, 3, 8}, {10, 20, 30, 90}}, // Items 1-4
        {{3, 2, 1}, {50, 40, 60}},        // Smaller knapsack
        {{5, 4, 6, 3}, {10, 40, 30, 50}}  // Random test
    };
    vector<int> capacities = {10, 5, 10};

    for (int i = 0; i < testCases.size(); i++) {
        int maxVal = knapsack01(testCases[i].first, testCases[i].second, capacities[i]);
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Weights: ";
        for (auto w : testCases[i].first) cout << w << " ";
        cout << "\nValues: ";
        for (auto v : testCases[i].second) cout << v << " ";
        cout << "\nKnapsack Capacity: " << capacities[i] << "\n";
        cout << "Maximum Value: " << maxVal << "\n\n";
    }
}

int main() {
    cout << "Testing 0/1 Knapsack Problem Implementation\n\n";
    testKnapsack();
    return 0;
}