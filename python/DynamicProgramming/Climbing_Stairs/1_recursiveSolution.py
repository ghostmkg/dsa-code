# Problem: Climbing Stairs
# Approach: Simple Recursion
# Time Complexity: O(2^n) - Exponential, due to redundant calculations
# Space Complexity: O(n) - For the recursion stack

def dfs(n):
    """
    Calculates the number of ways to climb n stairs using recursion.
    Base cases:
    - If n is 0 or 1, there's only one way.
    """
    if n < 2:
        return 1
    
    # The number of ways to reach step 'n' is the sum of ways to reach 'n-1' and 'n-2'.
    one_step = dfs(n - 1)
    two_steps = dfs(n - 2)
    
    return one_step + two_steps

def climbStairs(n):
    """
    Main function to initiate the recursive calculation.
    """
    return dfs(n)

# Example usage:
if __name__ == "__main__":
    num_stairs = 4
    print(f"Number of ways to climb {num_stairs} stairs: {climbStairs(num_stairs)}") # Outputs: 5
