Climbing Stairs

This directory contains multiple solutions to the classic "Climbing Stairs" problem, showcasing different algorithmic approaches and optimizations.

Problem Link: LeetCode 70. Climbing Stairs

Intuition

You are climbing a staircase that has n steps. You can either climb 1 or 2 steps at a time. The goal is to find the total number of distinct ways you can reach the top.

Let's analyze the core logic:

To reach the n-th step, you must have come from either the (n-1)-th step or the (n-2)-th step.

There are no other possibilities.

Therefore, the total number of ways to reach step n is the sum of the ways to reach step (n-1) and the ways to reach step (n-2).

This gives us the recurrence relation:
ways(n) = ways(n-1) + ways(n-2)

This is the exact formula for the Fibonacci sequence.

Base Cases:

ways(0) = 1 (There is one way to be at the ground floor: do nothing).

ways(1) = 1 (There is one way to reach the first step: take one step).

Approaches

1. Simple Recursion

This is the most straightforward approach where we directly translate the recurrence relation into a recursive function.

Code: recursiveSolution.py

def dfs(n):
    if n < 2:
        return 1
    oneStep = dfs(n-1)
    twoSteps = dfs(n-2)
    return oneStep + twoSteps


Time Complexity: O(2^n). This is very inefficient because the same subproblems (e.g., dfs(2)) are calculated multiple times.

Space Complexity: O(n) for the recursion call stack.

2. Memoization (Top-Down DP)

To optimize the recursive solution, we can store the results of subproblems in a data structure (like an array or hash map) and reuse them. This is a top-down approach.

Code: memoization.py

def dfs(n, dp):
    if n < 2:
        return 1
    if dp[n] != -1:
        return dp[n]
    dp[n] = dfs(n-1, dp) + dfs(n-2, dp)
    return dp[n]


Time Complexity: O(n). Each subproblem from n down to 0 is solved only once.

Space Complexity: O(n) for the dp array and O(n) for the recursion stack.

3. Tabulation (Bottom-Up DP)

Instead of recursion, we can solve the problem iteratively. We build the solution from the base cases up to n.

Code: tabulation.py

def climbStairs(n):
    dp = [0] * (n+1)
    dp[0] = 1
    dp[1] = 1
    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]


Time Complexity: O(n). We iterate through the loop n-1 times.

Space Complexity: O(n) for the dp array.

4. Space-Optimized DP

Looking at the tabulation approach, we see that to calculate dp[i], we only need the values of dp[i-1] and dp[i-2]. We don't need the entire dp array. We can optimize the space by only storing the last two values.

Code: spaceOptimized.py

def climbStairs(n):
    prev = 1
    prev2 = 1
    for i in range(2, n+1):
        curr = prev + prev2
        prev2 = prev
        prev = curr
    return prev


Time Complexity: O(n).

Space Complexity: O(1). We only use a few variables to store the state.