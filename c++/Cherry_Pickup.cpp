#include <bits/stdc++.h>
using namespace std;


int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
    dp[0][0][0] = grid[0][0];


    for (int k = 1; k < 2 * n - 1; ++k) {
        vector<vector<vector<int>>> new_dp(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        for (int x1 = max(0, k - (n - 1)); x1 <= min(n - 1, k); ++x1) {
            for (int x2 = max(0, k - (n - 1)); x2 <= min(n - 1, k); ++x2) {
                int y1 = k - x1;
                int y2 = k - x2;
                if (y1 >= n || y2 >= n || grid[x1][y1] == -1 || grid[x2][y2] == -1) continue;
                int val = grid[x1][y1];
                if (x1 != x2 || y1 != y2) val += grid[x2][y2];
                for (int dx1 = -1; dx1 <= 0; ++dx1) {
                    for (int dx2 = -1; dx2 <= 0; ++dx2) {
                        int px1 = x1 + dx1;
                        int px2 = x2 + dx2;
                        int py1 = y1 - dx1;
                        int py2 = y2 - dx2;
                        if (px1 >= 0 && px2 >= 0 && py1 >= 0 && py2 >= 0 && dp[px1][px2][k - 1] != INT_MIN) {
                            new_dp[x1][x2][k] = max(new_dp[x1][x2][k], dp[px1][px2][k - 1] + val);
                        }
                    }
                }
            }
        }
        dp = new_dp;
    }
    return max(0, dp[n - 1][n - 1][2 * n - 2]);
}


int main() {
    int n;
    cout << "Enter the size of the grid (n): ";
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter the grid (" << n << "x" << n << "):" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)

            cin >> grid[i][j];


    int result = cherryPickup(grid);
    cout << "Maximum cherries collected: " << result << endl;
    return 0;
}

