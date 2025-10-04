# Problem: Climbing Stairs
# Approach: Tabulation (Bottom-Up Dynamic Programming)
# Time Complexity: O(n) - We iterate from 2 to n.
# Space Complexity: O(n) - For the dp array.

def climbStairs(n):
    """
    Calculates the number of ways to climb n stairs using tabulation.
    """
    if n < 2:
        return 1

    # dp[i] will store the number of ways to reach stair i.
    dp = [0] * (n + 1)
    dp[0] = 1 # Base case: 1 way to be at the start
    dp[1] = 1 # Base case: 1 way to reach the first stair
    
    # Fill the dp table from the bottom up.
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
        
    return dp[n]

# Example usage:
if __name__ == "__main__":
    num_stairs = 4
    print(f"Number of ways to climb {num_stairs} stairs: {climbStairs(num_stairs)}") # Outputs: 5
