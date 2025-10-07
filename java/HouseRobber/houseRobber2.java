// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

package HouseRobber;

import java.util.Arrays;

public class houseRobber2 {
    /**
     * Recursive helper function to calculate the maximum amount that can be robbed up to house i.
     * @param i  Current house index (working backwards)
     * @param a  Array of money in each house
     * @param dp Memoization table to store results for subproblems
     * @return   Maximum money that can be robbed up to house i
     */
    private int f(int i, int[] a, int[] dp) {
        // If out of bounds, no money can be robbed
        if(i < 0) return 0;
        // If at the first house, rob it (base case)
        if(i == 0) return a[i];
        // Return cached result if already computed
        if(dp[i] != -1) return dp[i];

        // Option 1: Rob current house and skip previous (move to i-2)
        // Option 2: Skip current house (move to i-1)
        return dp[i] = Math.max(a[i] + f(i-2, a, dp), f(i-1,a,dp));
    }

    /**
     * Calculates the maximum amount of money that can be robbed in a circular arrangement of houses.
     * @param a Array of money in each house
     * @return  Maximum money that can be robbed
     */
    public int rob(int[] a) {
        int n = a.length;
        // If only one house, rob it
        if(n == 1)return a[0];
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);

        // Create two scenarios:
        // 1. Exclude the first house (rob from 1 to n-1)
        // 2. Exclude the last house (rob from 0 to n-2)
        int arr1[] = new int[n - 1];
        int arr2[] = new int[n - 1];
        int t = 0;
        for (int i = 1; i < n; i++) {
            arr1[t++] = a[i];
        }
        t = 0;
        for (int i = 0; i < n - 1; i++) {
            arr2[t++] = a[i];
        }

        // Compute max for both scenarios and return the best
        int first = f(n-2,arr1,dp);
        Arrays.fill(dp,-1);
        int last = f(n-2,arr2,dp);
        return Math.max(first,last);
    }
}
