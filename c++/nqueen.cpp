#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiag(2*n - 1, 0), lowerDiag(2*n - 1, 0);
        solve(0, board, res, leftRow, upperDiag, lowerDiag, n);
        return res;
    }

private:
    void solve(int col, vector<string> &board, vector<vector<string>> &res,
               vector<int> &leftRow, vector<int> &upperDiag, vector<int> &lowerDiag, int n) {
        if (col == n) {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n - 1 + col - row] = 1;

                solve(col + 1, board, res, leftRow, upperDiag, lowerDiag, n);

                // Backtrack
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n - 1 + col - row] = 0;
            }
        }
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "\nNumber of solutions: " << solutions.size() << "\n\n";
    for (auto &board : solutions) {
        for (auto &row : board)
            cout << row << "\n";
        cout << "\n";
    }
    return 0;
}
