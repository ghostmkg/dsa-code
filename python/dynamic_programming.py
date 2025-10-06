def knapsack_01(weights, values, capacity):
    """
    0/1 Knapsack problem using dynamic programming
    Time Complexity: O(n * W)
    Space Complexity: O(n * W)
    """
    n = len(weights)
    
    # Create a 2D DP table
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]
    
    # Build table dp[][] in bottom-up manner
    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            # If weight of current item is more than capacity, skip it
            if weights[i-1] > w:
                dp[i][w] = dp[i-1][w]
            else:
                # Take maximum of including or excluding current item
                include = values[i-1] + dp[i-1][w - weights[i-1]]
                exclude = dp[i-1][w]
                dp[i][w] = max(include, exclude)
    
    # Backtrack to find which items to include
    result_weight = capacity
    items_included = []
    
    for i in range(n, 0, -1):
        if dp[i][result_weight] != dp[i-1][result_weight]:
            items_included.append(i-1)  # Item index
            result_weight -= weights[i-1]
    
    return dp[n][capacity], items_included[::-1]

def longest_common_subsequence(text1, text2):
    """
    Longest Common Subsequence using dynamic programming
    Time Complexity: O(m * n)
    Space Complexity: O(m * n)
    """
    m, n = len(text1), len(text2)
    
    # Create DP table
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    # Fill the DP table
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i-1] == text2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    # Backtrack to find the actual LCS
    lcs = []
    i, j = m, n
    while i > 0 and j > 0:
        if text1[i-1] == text2[j-1]:
            lcs.append(text1[i-1])
            i -= 1
            j -= 1
        elif dp[i-1][j] > dp[i][j-1]:
            i -= 1
        else:
            j -= 1
    
    return dp[m][n], ''.join(reversed(lcs))

def edit_distance(str1, str2):
    """
    Edit Distance (Levenshtein Distance) using dynamic programming
    Time Complexity: O(m * n)
    Space Complexity: O(m * n)
    """
    m, n = len(str1), len(str2)
    
    # Create DP table
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    # Initialize base cases
    for i in range(m + 1):
        dp[i][0] = i  # Delete all characters from str1
    for j in range(n + 1):
        dp[0][j] = j  # Insert all characters to str1
    
    # Fill the DP table
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if str1[i-1] == str2[j-1]:
                dp[i][j] = dp[i-1][j-1]  # No operation needed
            else:
                dp[i][j] = 1 + min(
                    dp[i-1][j],    # Delete
                    dp[i][j-1],    # Insert
                    dp[i-1][j-1]   # Replace
                )
    
    return dp[m][n]

def coin_change_min_coins(coins, amount):
    """
    Minimum number of coins to make amount
    Time Complexity: O(amount * len(coins))
    Space Complexity: O(amount)
    """
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0
    
    for i in range(1, amount + 1):
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)
    
    return dp[amount] if dp[amount] != float('inf') else -1

def coin_change_ways(coins, amount):
    """
    Number of ways to make amount using given coins
    Time Complexity: O(amount * len(coins))
    Space Complexity: O(amount)
    """
    dp = [0] * (amount + 1)
    dp[0] = 1
    
    for coin in coins:
        for i in range(coin, amount + 1):
            dp[i] += dp[i - coin]
    
    return dp[amount]

def longest_increasing_subsequence(nums):
    """
    Longest Increasing Subsequence using dynamic programming
    Time Complexity: O(n²)
    Space Complexity: O(n)
    """
    if not nums:
        return 0, []
    
    n = len(nums)
    dp = [1] * n
    parent = [-1] * n
    
    for i in range(1, n):
        for j in range(i):
            if nums[j] < nums[i] and dp[j] + 1 > dp[i]:
                dp[i] = dp[j] + 1
                parent[i] = j
    
    # Find the index with maximum LIS length
    max_length = max(dp)
    max_index = dp.index(max_length)
    
    # Reconstruct the LIS
    lis = []
    current = max_index
    while current != -1:
        lis.append(nums[current])
        current = parent[current]
    
    return max_length, list(reversed(lis))

def matrix_chain_multiplication(dimensions):
    """
    Matrix Chain Multiplication using dynamic programming
    Time Complexity: O(n³)
    Space Complexity: O(n²)
    """
    n = len(dimensions) - 1  # Number of matrices
    
    # dp[i][j] represents minimum scalar multiplications for matrices i to j
    dp = [[0] * n for _ in range(n)]
    
    # l is chain length
    for l in range(2, n + 1):
        for i in range(n - l + 1):
            j = i + l - 1
            dp[i][j] = float('inf')
            
            for k in range(i, j):
                cost = (dp[i][k] + dp[k+1][j] + 
                       dimensions[i] * dimensions[k+1] * dimensions[j+1])
                dp[i][j] = min(dp[i][j], cost)
    
    return dp[0][n-1]

def rod_cutting(prices, length):
    """
    Rod Cutting problem using dynamic programming
    Time Complexity: O(n²)
    Space Complexity: O(n)
    """
    dp = [0] * (length + 1)
    cuts = [0] * (length + 1)
    
    for i in range(1, length + 1):
        for j in range(i):
            if prices[j] + dp[i - j - 1] > dp[i]:
                dp[i] = prices[j] + dp[i - j - 1]
                cuts[i] = j + 1
    
    # Reconstruct the solution
    cut_lengths = []
    remaining = length
    while remaining > 0:
        cut_length = cuts[remaining]
        cut_lengths.append(cut_length)
        remaining -= cut_length
    
    return dp[length], cut_lengths

def max_subarray_sum(nums):
    """
    Maximum Subarray Sum (Kadane's Algorithm)
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    max_ending_here = max_so_far = nums[0]
    start = end = 0
    temp_start = 0
    
    for i in range(1, len(nums)):
        if max_ending_here < 0:
            max_ending_here = nums[i]
            temp_start = i
        else:
            max_ending_here += nums[i]
        
        if max_ending_here > max_so_far:
            max_so_far = max_ending_here
            start = temp_start
            end = i
    
    return max_so_far, nums[start:end+1]

# Test all dynamic programming algorithms
if __name__ == "__main__":
    print("=== Dynamic Programming Algorithms ===\n")
    
    # Test 0/1 Knapsack
    print("1. 0/1 Knapsack Problem:")
    weights = [10, 20, 30]
    values = [60, 100, 120]
    capacity = 50
    max_value, items = knapsack_01(weights, values, capacity)
    print(f"   Weights: {weights}, Values: {values}, Capacity: {capacity}")
    print(f"   Maximum value: {max_value}, Items selected: {items}\n")
    
    # Test LCS
    print("2. Longest Common Subsequence:")
    text1, text2 = "AGGTAB", "GXTXAYB"
    lcs_length, lcs_string = longest_common_subsequence(text1, text2)
    print(f"   Text1: {text1}, Text2: {text2}")
    print(f"   LCS length: {lcs_length}, LCS: '{lcs_string}'\n")
    
    # Test Edit Distance
    print("3. Edit Distance:")
    str1, str2 = "kitten", "sitting"
    distance = edit_distance(str1, str2)
    print(f"   String1: '{str1}', String2: '{str2}'")
    print(f"   Edit distance: {distance}\n")
    
    # Test Coin Change
    print("4. Coin Change:")
    coins = [1, 3, 4]
    amount = 6
    min_coins = coin_change_min_coins(coins, amount)
    ways = coin_change_ways(coins, amount)
    print(f"   Coins: {coins}, Amount: {amount}")
    print(f"   Minimum coins needed: {min_coins}")
    print(f"   Number of ways: {ways}\n")
    
    # Test LIS
    print("5. Longest Increasing Subsequence:")
    nums = [10, 9, 2, 5, 3, 7, 101, 18]
    lis_length, lis_sequence = longest_increasing_subsequence(nums)
    print(f"   Array: {nums}")
    print(f"   LIS length: {lis_length}, LIS: {lis_sequence}\n")
    
    # Test Matrix Chain Multiplication
    print("6. Matrix Chain Multiplication:")
    dimensions = [1, 2, 3, 4]  # Matrices: 1x2, 2x3, 3x4
    min_multiplications = matrix_chain_multiplication(dimensions)
    print(f"   Matrix dimensions: {dimensions}")
    print(f"   Minimum scalar multiplications: {min_multiplications}\n")
    
    # Test Rod Cutting
    print("7. Rod Cutting:")
    prices = [1, 5, 8, 9, 10, 17, 17, 20]
    length = 8
    max_profit, cuts = rod_cutting(prices, length)
    print(f"   Prices: {prices}, Rod length: {length}")
    print(f"   Maximum profit: {max_profit}, Cuts: {cuts}\n")
    
    # Test Maximum Subarray
    print("8. Maximum Subarray Sum:")
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    max_sum, subarray = max_subarray_sum(nums)
    print(f"   Array: {nums}")
    print(f"   Maximum sum: {max_sum}, Subarray: {subarray}")