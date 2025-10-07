// There is a row of n houses, where each house can be painted one of three colors: red, blue, or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

// The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.

// For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the cost of painting house 1 with color green, and so on...
// Return the minimum cost to paint all houses.

 

// Example 1:

// Input: costs = [[17,2,17],[16,16,5],[14,3,19]]
// Output: 10
// Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
// Minimum cost: 2 + 5 + 3 = 10.
// Example 2:

// Input: costs = [[7,6,2]]
// Output: 2

/*
Algorithm Description:
----------------------
This solution uses recursion with memoization (top-down dynamic programming) to find the minimum cost to paint all houses such that no two adjacent houses have the same color.
- For each house, we try all possible colors (red, blue, green) except the color used for the previous house.
- We recursively compute the minimum cost for each choice and use a memoization table (dp) to avoid recomputation.
- The recursion starts from the first house with no previous color (-1).

Complexity Analysis:
--------------------
Let n be the number of houses.
- Time Complexity: O(n * 3), since for each house and each color, we compute the result once and memoize it.
- Space Complexity: O(n * 3) for the memoization table.
*/

package dynamic_programming.PaintHouse;

import java.util.Arrays;

public class paintHouse1 {
    /**
     * Recursive helper function to calculate the minimum cost to paint houses from index i onwards,
     * given that the previous house was painted with color 'col'.
     * @param i   Current house index
     * @param col Color used for the previous house (-1 if no previous house)
     * @param dp  Memoization table
     * @param a   Cost matrix
     * @return    Minimum cost to paint from house i to the end
     */
    private int f(int i, int col, int[][] dp, int[][] a) {
        // Base case: If all houses are painted, cost is 0
        if(i >= a.length){
            return 0;
        }
        // Return cached result if already computed
        if(col != -1 && dp[i][col] != -1){
            return dp[i][col];
        }

        if(col == -1){
            // No previous color, try all three colors for the first house
            int red = f(i+1,0,dp,a) + a[i][0];
            int blue = f(i+1,1,dp,a) + a[i][1];
            int green = f(i+1,2,dp,a) + a[i][2];
            return Math.min(red, Math.min(blue,green));
        }

        // For each color, try the other two colors for the next house
        if(col == 0) {
            // Previous was red, so try blue and green
            dp[i][col] = Math.min(f(i+1,1,dp,a)+ a[i][1], f(i+1,2,dp,a)+ a[i][2]);
        }
        if(col == 1) {
            // Previous was blue, so try red and green
            dp[i][col] = Math.min(f(i+1,0,dp,a)+ a[i][0], f(i+1,2,dp,a) + a[i][2]);
        }
        if(col == 2) {
            // Previous was green, so try blue and red
            dp[i][col] = Math.min(f(i+1,1,dp,a)+ a[i][1], f(i+1,0,dp,a)+ a[i][0]);
        }
        return dp[i][col];
    }

    /**
     * Calculates the minimum cost to paint all houses such that no two adjacent houses have the same color.
     * @param a Cost matrix
     * @return  Minimum total cost
     */
    public int minCost(int[][] a) {
        int n = a.length;
        int[][] dp = new int[n+1][4];
        // Initialize dp table with -1 (uncomputed)
        for(int[] r:dp){
            Arrays.fill(r,-1);
        }
        // Start from the first house, with no previous color (-1)
        return f(0,-1,dp,a);
    }
}
