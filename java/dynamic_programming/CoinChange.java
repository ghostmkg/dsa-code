/**
 * Coin Change Problem - Dynamic Programming Solutions
 * 
 * The coin change problem is a classic dynamic programming problem where
 * we need to find the minimum number of coins needed to make a given amount.
 * 
 * Problem Statement:
 * Given a set of coin denominations and a target amount, find the minimum
 * number of coins needed to make that amount. If it's not possible, return -1.
 * 
 * Time Complexity: O(amount × coins.length)
 * Space Complexity: O(amount) for optimized version
 * 
 * Author: Hacktoberfest Contributor
 * Date: October 2024
 */

import java.util.*;

public class CoinChange {
    
    /**
     * Approach 1: Bottom-up Dynamic Programming (Tabulation)
     * Most efficient and commonly used approach
     * 
     * @param coins Array of coin denominations
     * @param amount Target amount to make
     * @return Minimum number of coins needed, or -1 if impossible
     */
    public static int coinChangeDP(int[] coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        
        // dp[i] represents minimum coins needed to make amount i
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1); // Initialize with impossible value
        dp[0] = 0; // Base case: 0 coins needed for amount 0
        
        // Fill dp table
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
    
    /**
     * Approach 2: Top-down Dynamic Programming (Memoization)
     * Recursive approach with caching
     * 
     * @param coins Array of coin denominations
     * @param amount Target amount to make
     * @return Minimum number of coins needed, or -1 if impossible
     */
    public static int coinChangeMemo(int[] coins, int amount) {
        Map<Integer, Integer> memo = new HashMap<>();
        int result = coinChangeMemoHelper(coins, amount, memo);
        return result == Integer.MAX_VALUE ? -1 : result;
    }
    
    private static int coinChangeMemoHelper(int[] coins, int amount, Map<Integer, Integer> memo) {
        if (amount == 0) return 0;
        if (amount < 0) return Integer.MAX_VALUE;
        
        if (memo.containsKey(amount)) {
            return memo.get(amount);
        }
        
        int minCoins = Integer.MAX_VALUE;
        for (int coin : coins) {
            int result = coinChangeMemoHelper(coins, amount - coin, memo);
            if (result != Integer.MAX_VALUE) {
                minCoins = Math.min(minCoins, result + 1);
            }
        }
        
        memo.put(amount, minCoins);
        return minCoins;
    }
    
    /**
     * Approach 3: Coin Change II - Count number of ways to make amount
     * 
     * @param coins Array of coin denominations
     * @param amount Target amount to make
     * @return Number of ways to make the amount
     */
    public static int coinChangeWays(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        dp[0] = 1; // One way to make amount 0 (use no coins)
        
        // Process each coin
        for (int coin : coins) {
            // Update dp array for this coin
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        
        return dp[amount];
    }
    
    /**
     * Approach 4: Reconstruct the actual coin combination
     * Returns the actual coins used to make the amount
     * 
     * @param coins Array of coin denominations
     * @param amount Target amount to make
     * @return List of coins used, empty list if impossible
     */
    public static List<Integer> coinChangeWithPath(int[] coins, int amount) {
        if (amount == 0) return new ArrayList<>();
        
        int[] dp = new int[amount + 1];
        int[] parent = new int[amount + 1]; // Track which coin was used
        
        Arrays.fill(dp, amount + 1);
        Arrays.fill(parent, -1);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin && dp[i - coin] + 1 < dp[i]) {
                    dp[i] = dp[i - coin] + 1;
                    parent[i] = coin;
                }
            }
        }
        
        if (dp[amount] > amount) {
            return new ArrayList<>(); // Impossible to make amount
        }
        
        // Reconstruct path
        List<Integer> result = new ArrayList<>();
        int curr = amount;
        while (curr > 0) {
            int coin = parent[curr];
            result.add(coin);
            curr -= coin;
        }
        
        return result;
    }
    
    /**
     * Approach 5: Space-optimized version for large amounts
     * Uses BFS approach, good when amount is very large
     * 
     * @param coins Array of coin denominations
     * @param amount Target amount to make
     * @return Minimum number of coins needed, or -1 if impossible
     */
    public static int coinChangeBFS(int[] coins, int amount) {
        if (amount == 0) return 0;
        
        Queue<Integer> queue = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();
        
        queue.offer(0);
        visited.add(0);
        int level = 0;
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            level++;
            
            for (int i = 0; i < size; i++) {
                int curr = queue.poll();
                
                for (int coin : coins) {
                    int next = curr + coin;
                    
                    if (next == amount) {
                        return level;
                    }
                    
                    if (next < amount && !visited.contains(next)) {
                        visited.add(next);
                        queue.offer(next);
                    }
                }
            }
        }
        
        return -1;
    }
    
    /**
     * Utility method to print detailed analysis
     */
    public static void analyzeTestCase(int[] coins, int amount) {
        System.out.println("\\n" + "=".repeat(50));
        System.out.println("Test Case: coins = " + Arrays.toString(coins) + ", amount = " + amount);
        System.out.println("=".repeat(50));
        
        long startTime, endTime;
        
        // Test DP approach
        startTime = System.nanoTime();
        int dpResult = coinChangeDP(coins, amount);
        endTime = System.nanoTime();
        System.out.println("DP Result: " + dpResult + " (Time: " + (endTime - startTime) / 1000000.0 + " ms)");
        
        // Test Memoization approach
        startTime = System.nanoTime();
        int memoResult = coinChangeMemo(coins, amount);
        endTime = System.nanoTime();
        System.out.println("Memo Result: " + memoResult + " (Time: " + (endTime - startTime) / 1000000.0 + " ms)");
        
        // Test BFS approach
        startTime = System.nanoTime();
        int bfsResult = coinChangeBFS(coins, amount);
        endTime = System.nanoTime();
        System.out.println("BFS Result: " + bfsResult + " (Time: " + (endTime - startTime) / 1000000.0 + " ms)");
        
        // Show number of ways
        int ways = coinChangeWays(coins, amount);
        System.out.println("Number of ways: " + ways);
        
        // Show actual coins used
        List<Integer> coinsUsed = coinChangeWithPath(coins, amount);
        if (!coinsUsed.isEmpty()) {
            System.out.println("Coins used: " + coinsUsed);
            
            // Verify the solution
            int sum = coinsUsed.stream().mapToInt(Integer::intValue).sum();
            System.out.println("Verification: " + coinsUsed + " sum = " + sum + 
                             (sum == amount ? " ✓" : " ✗"));
        } else if (dpResult != -1) {
            System.out.println("Error in path reconstruction!");
        } else {
            System.out.println("No solution possible");
        }
    }
    
    /**
     * Comprehensive test suite with various scenarios
     */
    public static void runComprehensiveTests() {
        System.out.println("🪙 COIN CHANGE PROBLEM - COMPREHENSIVE SOLUTION");
        System.out.println("===============================================");
        
        // Test Case 1: Standard case
        analyzeTestCase(new int[]{1, 3, 4}, 6);
        
        // Test Case 2: Classic example
        analyzeTestCase(new int[]{1, 5, 10, 25}, 30);
        
        // Test Case 3: No solution
        analyzeTestCase(new int[]{3, 5}, 1);
        
        // Test Case 4: Large denomination
        analyzeTestCase(new int[]{1, 2, 5}, 11);
        
        // Test Case 5: Single coin
        analyzeTestCase(new int[]{1}, 10);
        
        // Test Case 6: Amount is 0
        analyzeTestCase(new int[]{1, 2, 5}, 0);
        
        // Test Case 7: Greedy vs DP difference
        analyzeTestCase(new int[]{1, 3, 4}, 6);
        
        System.out.println("\\n" + "=".repeat(60));
        System.out.println("📊 ALGORITHM COMPARISON");
        System.out.println("=".repeat(60));
        System.out.println("1. Bottom-up DP: Most efficient, O(amount × coins) time");
        System.out.println("2. Top-down Memo: Intuitive recursive, same complexity");
        System.out.println("3. BFS: Good for very large amounts, space efficient");
        System.out.println("4. Path Reconstruction: Shows actual coins used");
        System.out.println("5. Counting Ways: Finds number of possible combinations");
    }
    
    /**
     * Interactive demo for user input
     */
    public static void interactiveDemo() {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("\\n🎮 INTERACTIVE COIN CHANGE DEMO");
        System.out.println("=================================");
        
        System.out.print("Enter coin denominations (space-separated): ");
        String[] coinStrings = scanner.nextLine().split("\\\\s+");
        int[] coins = Arrays.stream(coinStrings).mapToInt(Integer::parseInt).toArray();
        
        System.out.print("Enter target amount: ");
        int amount = scanner.nextInt();
        
        analyzeTestCase(coins, amount);
        
        // Ask for another test
        System.out.print("\\nTry another case? (y/n): ");
        String choice = scanner.next();
        if (choice.toLowerCase().startsWith("y")) {
            scanner.nextLine(); // Consume newline
            interactiveDemo();
        }
    }
    
    /**
     * Main method - Entry point
     */
    public static void main(String[] args) {
        // Run comprehensive tests
        runComprehensiveTests();
        
        // Ask user if they want to try interactive demo
        Scanner scanner = new Scanner(System.in);
        System.out.print("\\nWould you like to try the interactive demo? (y/n): ");
        String choice = scanner.nextLine();
        
        if (choice.toLowerCase().startsWith("y")) {
            interactiveDemo();
        }
        
        System.out.println("\\n🎯 Perfect for Hacktoberfest 2024!");
        System.out.println("Happy coding! 🚀");
    }
}

/*
 * Sample Inputs and Expected Outputs:
 * 
 * Input: coins = [1,3,4], amount = 6
 * Output: 2 (use coins [3,3])
 * 
 * Input: coins = [2], amount = 3  
 * Output: -1 (impossible)
 * 
 * Input: coins = [1,5,10,25], amount = 30
 * Output: 2 (use coins [5,25])
 * 
 * Key Insights:
 * 1. Greedy approach doesn't always work (e.g., coins=[1,3,4], amount=6)
 * 2. DP builds solution from smaller subproblems
 * 3. Multiple approaches help understand the problem better
 * 4. Path reconstruction is useful for verification
 */