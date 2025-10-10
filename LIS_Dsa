# ------------------------------------------------------------
# Problem: Longest Increasing Subsequence
# Difficulty: Advanced
# Source: LeetCode #300
# ------------------------------------------------------------
# Statement:
# Given an integer array nums, return the length of the longest
# strictly increasing subsequence.
#
# Example:
#   Input: nums = [10,9,2,5,3,7,101,18]
#   Output: 4  # LIS: [2,3,7,101]
#
# Approach:
#   - Use Dynamic Programming with a patience sorting technique.
#   - Maintain a list `sub` representing the smallest possible
#     tail of all increasing subsequences with length i+1.
#   - Use binary search to find the position to replace or append.
#
# Time Complexity: O(n log n)
# Space Complexity: O(n)
# ------------------------------------------------------------

from bisect import bisect_left

def length_of_lis(nums):
    sub = []  # Holds the smallest tail of all increasing subsequences
    for num in nums:
        i = bisect_left(sub, num)  # Find position to replace or append
        if i == len(sub):
            sub.append(num)  # Extend the subsequence
        else:
            sub[i] = num  # Replace to keep smaller tail
    return len(sub)

# ------------------------------------------------------------
# Driver Code for Testing
# ------------------------------------------------------------
if __name__ == "__main__":
    nums = [10, 9, 2, 5, 3, 7, 101, 18]
    print("Input Array:", nums)
    print("Length of LIS:", length_of_lis(nums))
