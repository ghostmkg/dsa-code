# Problem: Climbing Stairs
# Approach: Space-Optimized Dynamic Programming
# Time Complexity: O(n) - Single loop up to n.
# Space Complexity: O(1) - Only two variables are used to store previous results.

def climbStairs(n):
    """
    Calculates the number of ways to climb n stairs using space optimization.
    """
    if n < 2:
        return 1
        
    prev = 1  # Represents ways to climb (i-1) stairs, initially for n=1
    prev2 = 1 # Represents ways to climb (i-2) stairs, initially for n=0
    
    for i in range(2, n + 1):
        curr = prev + prev2
        prev2 = prev
        prev = curr
        
    return prev

# Example usage:
if __name__ == "__main__":
    num_stairs = 4
    print(f"Number of ways to climb {num_stairs} stairs: {climbStairs(num_stairs)}") # Outputs: 5
