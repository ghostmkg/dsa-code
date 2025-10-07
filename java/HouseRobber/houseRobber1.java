// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
 

package HouseRobber;

import java.util.Arrays;

public class houseRobber1 {
    /**
     * Recursive helper function to calculate the maximum amount that can be robbed starting from house i.
     * @param i  Current house index
     * @param a  Array of money in each house
     * @param dp Memoization table to store results for subproblems
     * @return   Maximum money that can be robbed from house i onwards
     */
    private int f(int i, int[] a, int[] dp) {
        // If at the last house, rob it (base case)
        if(i == a.length - 1){
            return a[i];
        }
        // If out of bounds, no money can be robbed
        if(i >= a.length){
            return 0;
        }
        // Return cached result if already computed
        if(dp[i] != -1) {
            return dp[i];
        }

        // Option 1: Rob current house and skip next (move to i+2)
        int take = a[i]+f(i+2,a,dp);
        // Option 2: Skip current house (move to i+1)
        int notTake = f(i+1,a,dp);
        // Store and return the maximum of both options
        return dp[i] = Math.max(take,notTake);
    }

    /**
     * Calculates the maximum amount of money that can be robbed without alerting the police.
     * @param a Array of money in each house
     * @return  Maximum money that can be robbed
     */
    public int rob(int[] a) {
        int n = a.length;
        int[] dp = new int[n];
        Arrays.fill(dp,-1); // Initialize memoization table
        return f(0,a,dp);   // Start from the first house
    }
}
