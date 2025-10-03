/**
 * @file NQueens.cpp
 * @brief Solution to the N-Queens problem using backtracking
 * @author Hacktoberfest Contributor
 * @date October 2025
 *
 * Problem: Place N chess queens on an N×N chessboard so that no two queens threaten each other.
 * A queen can attack horizontally, vertically, and diagonally.
 *
 * Algorithm: Backtracking
 * - Place queens one row at a time
 * - For each row, try placing queen in each column
 * - Check if placement is safe (no conflicts with previously placed queens)
 * - If safe, recursively place queens in next row
 * - If no valid placement found, backtrack and try different position
 *
 * Time Complexity: O(N!) - trying N positions in first row, N-1 in second, etc.
 * Space Complexity: O(N²) for the board + O(N) for recursion stack
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NQueens {
private:
    /**
     * @brief Check if placing queen at board[row][col] is safe
     * @param board Current board configuration
     * @param row Row to place queen
     * @param col Column to place queen
     * @param n Board size
     * @return true if position is safe, false otherwise
     *
     * We only need to check:
     * 1. Same column (upper rows)
     * 2. Upper left diagonal
     * 3. Upper right diagonal
     * (No need to check rows below as we fill top to bottom)
     */
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check column above
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    /**
     * @brief Optimized safety check using arrays to track columns and diagonals
     * @param cols Array tracking which columns have queens
     * @param diag1 Array tracking which left diagonals have queens
     * @param diag2 Array tracking which right diagonals have queens
     * @param row Current row
     * @param col Current column
     * @param n Board size
     * @return true if position is safe, false otherwise
     */
    bool isSafeOptimized(vector<bool>& cols, vector<bool>& diag1,
                         vector<bool>& diag2, int row, int col, int n) {
        // For left diagonal: row - col is constant (offset by n for positive index)
        // For right diagonal: row + col is constant
        return !cols[col] && !diag1[row - col + n] && !diag2[row + col];
    }

    /**
     * @brief Recursive backtracking function to solve N-Queens
     * @param board Current board state
     * @param row Current row to place queen
     * @param n Board size
     * @param solutions Vector to store all solutions
     */
    void solve(vector<string>& board, int row, int n, vector<vector<string>>& solutions) {
        // Base case: all queens placed successfully
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        // Try placing queen in each column of current row
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                // Place queen
                board[row][col] = 'Q';

                // Recursively place queens in next rows
                solve(board, row + 1, n, solutions);

                // Backtrack: remove queen and try next position
                board[row][col] = '.';
            }
        }
    }

    /**
     * @brief Optimized recursive backtracking using tracking arrays
     * @param board Current board state
     * @param row Current row
     * @param n Board size
     * @param cols Column tracking array
     * @param diag1 Left diagonal tracking array
     * @param diag2 Right diagonal tracking array
     * @param solutions Vector to store all solutions
     */
    void solveOptimized(vector<string>& board, int row, int n,
                       vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2,
                       vector<vector<string>>& solutions) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafeOptimized(cols, diag1, diag2, row, col, n)) {
                // Place queen
                board[row][col] = 'Q';
                cols[col] = true;
                diag1[row - col + n] = true;
                diag2[row + col] = true;

                // Recurse
                solveOptimized(board, row + 1, n, cols, diag1, diag2, solutions);

                // Backtrack
                board[row][col] = '.';
                cols[col] = false;
                diag1[row - col + n] = false;
                diag2[row + col] = false;
            }
        }
    }

public:
    /**
     * @brief Solve N-Queens problem and return all solutions
     * @param n Size of the board (n x n)
     * @return Vector of all valid board configurations
     */
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));

        solve(board, 0, n, solutions);
        return solutions;
    }

    /**
     * @brief Optimized solution using tracking arrays for O(1) safety checks
     * @param n Size of the board
     * @return Vector of all valid board configurations
     */
    vector<vector<string>> solveNQueensOptimized(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));

        // Tracking arrays for O(1) conflict detection
        vector<bool> cols(n, false);           // Track occupied columns
        vector<bool> diag1(2 * n, false);      // Track occupied left diagonals
        vector<bool> diag2(2 * n, false);      // Track occupied right diagonals

        solveOptimized(board, 0, n, cols, diag1, diag2, solutions);
        return solutions;
    }

    /**
     * @brief Print a single board solution
     * @param board Board configuration to print
     */
    void printBoard(const vector<string>& board) {
        for (const string& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    /**
     * @brief Print all solutions
     * @param solutions Vector of all board configurations
     */
    void printAllSolutions(const vector<vector<string>>& solutions) {
        cout << "Total solutions: " << solutions.size() << endl << endl;

        for (int i = 0; i < solutions.size(); i++) {
            cout << "Solution " << (i + 1) << ":" << endl;
            printBoard(solutions[i]);
        }
    }
};

/**
 * @brief Example usage and test cases
 */
int main() {
    NQueens solver;

    // Test case 1: 4-Queens (classic small example)
    cout << "=== 4-Queens Problem ===" << endl;
    vector<vector<string>> solutions4 = solver.solveNQueens(4);
    solver.printAllSolutions(solutions4);

    // Test case 2: 8-Queens (standard chess board)
    cout << "\n=== 8-Queens Problem ===" << endl;
    vector<vector<string>> solutions8 = solver.solveNQueensOptimized(8);
    cout << "Total solutions for 8-Queens: " << solutions8.size() << endl;

    // Print first solution only (92 solutions total is too many)
    if (!solutions8.empty()) {
        cout << "\nFirst solution:" << endl;
        solver.printBoard(solutions8[0]);
    }

    // Test case 3: 1-Queen (trivial case)
    cout << "=== 1-Queen Problem ===" << endl;
    vector<vector<string>> solutions1 = solver.solveNQueens(1);
    solver.printAllSolutions(solutions1);

    // Test case 4: 3-Queens (impossible case)
    cout << "=== 3-Queens Problem ===" << endl;
    vector<vector<string>> solutions3 = solver.solveNQueens(3);
    if (solutions3.empty()) {
        cout << "No solution exists for 3-Queens" << endl;
    } else {
        solver.printAllSolutions(solutions3);
    }

    return 0;
}
