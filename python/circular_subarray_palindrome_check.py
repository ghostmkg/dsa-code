# Circular Subarray Palindrome Check

# Problem:
# Given an array of integers, check if the array can be rearranged in a circular fashion such that the sequence forms a palindrome when traversed clockwise.

# Example:

# Input: [1, 2, 3, 2, 1] → Output: True
# Input: [1, 2, 3, 4] → Output: False


# Solution (Python):

from collections import Counter

def circular_palindrome(arr):
    freq = Counter(arr)
    odd_count = sum(v % 2 for v in freq.values())
    return odd_count <= 1

# Example
print(circular_palindrome([1,2,3,2,1])) # True
print(circular_palindrome([1,2,3,4]))   # False