# Problem: Climbing Stairs
# Approach: Memoization (Top-Down Dynamic Programming)
# Time Complexity: O(n) - Each subproblem is solved only once.
# Space Complexity: O(n) - For the recursion stack and the dp array.

def dfs(n, dp):
    """
    Calculates the number of ways to climb n stairs using recursion with memoization.
    """
    if n < 2:
        return 1
    
    # If the result for 'n' is already computed, return it.
    if dp[n] != -1:
        return dp[n]
    
    # Compute and store the result before returning.
    one_step = dfs(n - 1, dp)
    two_steps = dfs(n - 2, dp)
    dp[n] = one_step + two_steps
    
    return dp[n]

def climbStairs(n):
    """
    Main function to initiate the memoized calculation.
    Initializes a dp array with -1 to store results of subproblems.
    """
    dp = [-1] * (n + 1)
    return dfs(n, dp)

# Example usage:
if __name__ == "__main__":
    num_stairs = 4
    print(f"Number of ways to climb {num_stairs} stairs: {climbStairs(num_stairs)}") # Outputs: 5
