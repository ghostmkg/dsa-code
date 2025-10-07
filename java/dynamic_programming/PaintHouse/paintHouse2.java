// There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

// The cost of painting each house with a certain color is represented by an n x k cost matrix costs.

// For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on...
// Return the minimum cost to paint all houses.

 

// Example 1:

// Input: costs = [[1,5,3],[2,9,4]]
// Output: 5
// Explanation:
// Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
// Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5.
// Example 2:

// Input: costs = [[1,3],[2,4]]
// Output: 5

/*
Algorithm Description:
----------------------
This solution uses recursion with memoization (top-down dynamic programming) to find the minimum cost to paint all houses such that no two adjacent houses have the same color.
- For each house, we try all possible colors except the color used for the previous house.
- We recursively compute the minimum cost for each choice and use a memoization table (dp) to avoid recomputation.
- The recursion starts from the first house with no previous color (-1).

Complexity Analysis:
--------------------
Let n be the number of houses and k be the number of colors.
- Time Complexity: O(n * k^2), since for each house and each color, we try up to k-1 colors for the next house and memoize results.
- Space Complexity: O(n * k) for the memoization table.
*/

package dynamic_programming.PaintHouse;

import java.util.Arrays;

public class paintHouse2 {
    /**
     * Recursive helper function to calculate the minimum cost to paint houses from index i onwards,
     * given that the previous house was painted with color 'col'.
     * @param i   Current house index
     * @param col Color used for the previous house (-1 if no previous house)
     * @param a   Cost matrix
     * @param dp  Memoization table
     * @return    Minimum cost to paint from house i to the end
     */
    private int f(int i, int col, int[][] a, int[][] dp) {
        // Base case: If all houses are painted, cost is 0
        if(i >= a.length) {
            return 0;
        }
        // Return cached result if already computed
        if(col != -1 && dp[i][col] != -1) {
            return dp[i][col];
        }

        int mini = Integer.MAX_VALUE;

        if(col == -1){
            // No previous color, try all colors for the first house
            for(int j = 0; j < a[i].length; j++){
                mini = Math.min(mini,a[i][j] + f(i+1,j,a,dp));
            }
            return mini;
        }

        // Try all colors except the previous color for the current house
        for(int j = 0; j < a[i].length; j++){
            // for colour a[i][j], we need to find minimum cost
            if(j != col) {
                mini = Math.min(mini, a[i][j] + f(i+1,j,a,dp));
            }
        }
        // Store result in dp table and return
        return dp[i][col] = mini;
    }

    /**
     * Calculates the minimum cost to paint all houses such that no two adjacent houses have the same color.
     * @param a Cost matrix
     * @return  Minimum total cost
     */
    public int minCostII(int[][] a) {
        int n = a.length, k = a[0].length;
        int[][] dp = new int[n+1][k+1];
        // Initialize dp table with -1 (uncomputed)
        for(int[] r : dp) {
            Arrays.fill(r,-1);
        }
        // Start from the first house, with no previous color (-1)
        return f(0,-1,a,dp);
    }
}
