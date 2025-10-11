/*
    Problem: Frog Jump (Dynamic Programming)
    ----------------------------------------
    A frog is at the 0th stone and wants to reach the (n-1)th stone.
    The frog can jump either:
        - To the next stone (i+1), or
        - Skip one stone and jump to (i+2).
    Each stone has a height, and the cost of jumping from stone i to j is:
        cost = abs(height[i] - height[j])

    Goal:
    Find the minimum total cost for the frog to reach the last stone.

    ---------------------------------------------------------
    🧠 Approach:
    1️⃣ Recursive (Brute Force)
        - Try all possible jumps (i+1, i+2)
        - Exponential time → O(2^n)

    2️⃣ Memoization (Top-Down DP)
        - Store already computed states (DP[i])
        - Time Complexity → O(n)
        - Space Complexity → O(n) for recursion + memo array

    3️⃣ Tabulation (Bottom-Up DP)
        - Iterative version, avoids recursion overhead.
        - Time → O(n), Space → O(n) or optimized to O(1)

    ---------------------------------------------------------
    ✅ Example:
    Input:
        n = 4
        heights = [10, 30, 40, 20]
    Output:
        Minimum Cost = 30
        Explanation:
          Path: 0 → 1 → 3
          Cost: |10-30| + |30-20| = 20 + 10 = 30
*/

#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// Top-Down DP (Memoization)
int solveMemo(int i, vector<int> &h, vector<int> &dp) {
    if (i == 0) return 0; // base case
    if (dp[i] != -1) return dp[i];

    int oneJump = solveMemo(i - 1, h, dp) + abs(h[i] - h[i - 1]);
    int twoJump = INT_MAX;
    if (i > 1)
        twoJump = solveMemo(i - 2, h, dp) + abs(h[i] - h[i - 2]);

    return dp[i] = min(oneJump, twoJump);
}

// -----------------------------------------------------
// Bottom-Up DP (Iterative)
int solveTabulation(vector<int> &h) {
    int n = h.size();
    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++) {
        int oneJump = dp[i - 1] + abs(h[i] - h[i - 1]);
        int twoJump = (i > 1) ? dp[i - 2] + abs(h[i] - h[i - 2]) : INT_MAX;
        dp[i] = min(oneJump, twoJump);
    }
    return dp[n - 1];
}

// -----------------------------------------------------
int main() {
    int n;
    cout << "Enter the number of stones: ";
    cin >> n;

    cout << "Enter heights of stones:\n";
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    // --- Using Memoization ---
    vector<int> dp(n, -1);
    int ansMemo = solveMemo(n - 1, h, dp);
    cout << "\nMinimum cost using Memoization: " << ansMemo << "\n";

    // --- Using Tabulation ---
    int ansTab = solveTabulation(h);
    cout << "Minimum cost using Tabulation: " << ansTab << "\n";

    return 0;
}
